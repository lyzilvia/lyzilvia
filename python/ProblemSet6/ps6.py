# 6.00x Problem Set 6
# RSS Feed Filter

import feedparser
import string
import time
from project_util import translate_html
from Tkinter import *


#-----------------------------------------------------------------------
#
# Problem Set 6

#======================
# Code for retrieving and parsing RSS feeds
# Do not change this code
#======================

def process(url):
    """
    Fetches news items from the rss url and parses them.
    Returns a list of NewsStory-s.
    """
    feed = feedparser.parse(url)
    entries = feed.entries
    ret = []
    for entry in entries:
        guid = entry.guid
        title = translate_html(entry.title)
        link = entry.link
        summary = translate_html(entry.summary)
        try:
            subject = translate_html(entry.tags[0]['term'])
        except AttributeError:
            subject = ""
        newsStory = NewsStory(guid, title, subject, summary, link)
        ret.append(newsStory)
    return ret
#======================

#======================
# Part 1
# Data structure design
#======================

# Problem 1

# TODO: NewsStory --> DONE
class NewsStory(object):
    def __init__(self, guid, title, subject, summary, link):
        self.guid = guid
        self.title = title
        self.subject = subject
        self.summary = summary
        self.link = link
        
    def getGuid(self):
        return self.guid

    def getTitle(self):
        return self.title

    def getSubject(self):
        return self.subject

    def getSummary(self):
        return self.summary

    def getLink(self):
        return self.link

#======================
# Part 2
# Triggers
#======================

class Trigger(object):
    def evaluate(self, story):
        """
        Returns True if an alert should be generated
        for the given news item, or False otherwise.
        """
        raise NotImplementedError

# Whole Word Triggers
# Problems 2-5

# TODO: WordTrigger --> DONE
class WordTrigger(Trigger):
    def __init__(self, word):
        self.word = word

    def isWordIn(self, text):
        newtext = text.lower()
        L = list(newtext)
        for count in range(len(L)):
            for punct in string.punctuation:
                if L[count] == punct:
                    L[count] = ' '
        string1 = ''.join(L)
        L2 = string1.split()
        return self.word.lower() in L2
        
# TODO: TitleTrigger --> DONE
class TitleTrigger(WordTrigger):
    def evaluate(self, story):
        text = story.getTitle()
        return self.isWordIn(text)
        
# TODO: SubjectTrigger --> DONE
class SubjectTrigger(WordTrigger):
    def evaluate(self, story):
        text = story.getSubject()
        return self.isWordIn(text)
    
# TODO: SummaryTrigger --> DONE
class SummaryTrigger(WordTrigger):
    def evaluate(self, story):
        text = story.getSummary()
        return self.isWordIn(text)

# Composite Triggers
# Problems 6-8

# TODO: NotTrigger --> DONE
class NotTrigger(Trigger):
    def __init__(self, trigger):
        self.trigger = trigger
        
    def evaluate(self, story):
        return not self.trigger.evaluate(story)
    
# TODO: AndTrigger --> DONE
class AndTrigger(Trigger):
    def __init__(self, trigger1, trigger2):
        self.trigger1 = trigger1
        self.trigger2 = trigger2

    def evaluate(self, story):
        return self.trigger1.evaluate(story) and self.trigger2.evaluate(story)
    
# TODO: OrTrigger --> DONE
class OrTrigger(Trigger):
    def __init__(self, trigger1, trigger2):
        self.trigger1 = trigger1
        self.trigger2 = trigger2

    def evaluate(self, story):
        return self.trigger1.evaluate(story) or self.trigger2.evaluate(story)


# Phrase Trigger
# Question 9

# TODO: PhraseTrigger
class PhraseTrigger(Trigger):
    def __init__(self, phrase):
        self.phrase = phrase
    
    def evaluate(self, story):
        title =  story.getTitle()
        subject = story.getSubject()
        summary = story.getSummary()
        return self.phrase in title or self.phrase in subject or self.phrase in summary


#======================
# Part 3
# Filtering
#======================

def filterStories(stories, triggerlist):
	newstories = []
	for story in stories:
		for trigger in triggerlist:
			if trigger.evaluate(story) == True:
				newstories.append(story)
	
	stories = newstories
	return stories
	
# 6.00
# Problem Set 6 Test Suite
import unittest
from ps6 import *

class ProblemSet6NewsStory(unittest.TestCase):
    def setUp(self):
        pass
    def testNewsStoryConstructor(self):
        story = NewsStory('', '', '', '', '')
    def testNewsStoryGetGuid(self):
        story = NewsStory('test guid', 'test title', 'test subject',
                          'test summary', 'test link')
        self.assertEquals(story.getGuid(), 'test guid')
    def testNewsStoryGetTitle(self):
        story = NewsStory('test guid', 'test title', 'test subject',
                          'test summary', 'test link')
        self.assertEquals(story.getTitle(), 'test title')
    def testNewsStoryGetSubject(self):
        story = NewsStory('test guid', 'test title', 'test subject',
                          'test summary', 'test link')
        self.assertEquals(story.getSubject(), 'test subject')
    def testNewsStoryGetSummary(self):
        story = NewsStory('test guid', 'test title', 'test subject',
                          'test summary', 'test link')
        self.assertEquals(story.getSummary(), 'test summary')
    def testNewsStoryGetLink(self):
        story = NewsStory('test guid', 'test title', 'test subject',
                          'test summary', 'test link')
        self.assertEquals(story.getLink(), 'test link')

class ProblemSet6(unittest.TestCase):
    def setUp(self):
        class TrueTrigger:
            def evaluate(self, story): return True

        class FalseTrigger:
            def evaluate(self, story): return False

        self.tt = TrueTrigger()
        self.tt2 = TrueTrigger()
        self.ft = FalseTrigger()
        self.ft2 = FalseTrigger()

    def test1TitleTrigger(self):
        koala     = NewsStory('', 'Koala bears are soft and cuddly', '', '', '')
        pillow    = NewsStory('', 'I prefer pillows that are soft.', '', '', '')
        soda      = NewsStory('', 'Soft drinks are great', '', '', '')
        pink      = NewsStory('', "Soft's the new pink!", '', '', '')
        football  = NewsStory('', '"Soft!" he exclaimed as he threw the football', '', '', '')
        microsoft = NewsStory('', 'Microsoft announced today that pillows are bad', '', '', '')
        nothing   = NewsStory('', 'Reuters reports something really boring', '', '' ,'')
        caps      = NewsStory('', 'soft things are soft', '', '', '')

        s1 = TitleTrigger('SOFT')
        s2  = TitleTrigger('soft')
        for trig in [s1, s2]:
            self.assertTrue(trig.evaluate(koala), "TitleTrigger failed to fire when the word appeared in the title")
            self.assertTrue(trig.evaluate(pillow), "TitleTrigger failed to fire when the word had punctuation on it")
            self.assertTrue(trig.evaluate(soda), "TitleTrigger failed to fire when the case was different")
            self.assertTrue(trig.evaluate(pink), "TitleTrigger failed to fire when the word had an apostrophe on it")
            self.assertTrue(trig.evaluate(football), "TitleTrigger failed to fire in the presence of lots of punctuation")
            self.assertTrue(trig.evaluate(caps), "TitleTrigger is case-sensitive and shouldn't be")
            
            self.assertFalse(trig.evaluate(microsoft), "TitleTrigger fired when the word was present, but not as its own word (e.g. 'soft' and 'Microsoft)'")
            self.assertFalse(trig.evaluate(nothing), "TitleTrigger fired when the word wasn't really present in the title")

    def test2SubjectTrigger(self):
        koala     = NewsStory('', '', 'Koala bears are soft and cuddly', '', '')
        pillow    = NewsStory('', '', 'I prefer pillows that are soft.', '', '')
        soda      = NewsStory('', '', 'Soft drinks are great', '', '')
        pink      = NewsStory('', '', "Soft's the new pink!", '', '')
        football  = NewsStory('', '', '"Soft!" he exclaimed as he threw the football', '', '')
        microsoft = NewsStory('', '', 'Microsoft announced today that pillows are bad', '', '')
        nothing   = NewsStory('', '', 'Reuters reports something really boring', '', '')
        caps      = NewsStory('', '', 'soft things are soft', '', '')

        s1 = SubjectTrigger('SOFT')
        s2  = SubjectTrigger('soft')
        for trig in [s1, s2]:
            self.assertTrue(trig.evaluate(koala), "SubjectTrigger failed to fire when the word appeared in the subject")
            self.assertTrue(trig.evaluate(pillow), "SubjectTrigger failed to fire when the word had punctuation on it")
            self.assertTrue(trig.evaluate(soda), "SubjectTrigger failed to fire when the case was different")
            self.assertTrue(trig.evaluate(pink), "SubjectTrigger failed to fire when the word had an apostrophe on it")
            self.assertTrue(trig.evaluate(football), "SubjectTrigger failed to fire in the presence of lots of punctuation")
            self.assertTrue(trig.evaluate(caps), "SubjectTrigger is case-sensitive and shouldn't be")
            
            self.assertFalse(trig.evaluate(microsoft), "SubjectTrigger fired when the word was present, but not as its own word (e.g. 'soft' and 'Microsoft)'")
            self.assertFalse(trig.evaluate(nothing), "SubjectTrigger fired when the word wasn't really present in the subject")

    def test3SummaryTrigger(self):
        koala     = NewsStory('', '', '', 'Koala bears are soft and cuddly', '')
        pillow    = NewsStory('', '', '', 'I prefer pillows that are soft.', '')
        soda      = NewsStory('', '', '', 'Soft drinks are great', '')
        pink      = NewsStory('', '', '', "Soft's the new pink!", '')
        football  = NewsStory('', '', '', '"Soft!" he exclaimed as he threw the football', '')
        microsoft = NewsStory('', '', '', 'Microsoft announced today that pillows are bad', '')
        nothing   = NewsStory('', '', '', 'Reuters reports something really boring', '')
        caps      = NewsStory('', '', '', 'soft things are soft', '')

        s1 = SummaryTrigger('SOFT')
        s2  = SummaryTrigger('soft')
        for trig in [s1, s2]:
            self.assertTrue(trig.evaluate(koala), "SummaryTrigger failed to fire when the word appeared in the summary.")
            self.assertTrue(trig.evaluate(pillow), "SummaryTrigger failed to fire when the word had punctuation on it")
            self.assertTrue(trig.evaluate(soda), "SummaryTrigger failed to fire when the case was different")
            self.assertTrue(trig.evaluate(pink), "SummaryTrigger failed to fire when the word had an apostrophe on it")
            self.assertTrue(trig.evaluate(football), "SummaryTrigger failed to fire in the presence of lots of punctuation")
            self.assertTrue(trig.evaluate(caps), "SummaryTrigger is case-sensitive and shouldn't be")
            
            self.assertFalse(trig.evaluate(microsoft), "SummaryTrigger fired when the word was present, but not as its own word (e.g. 'soft' and 'Microsoft)'")
            self.assertFalse(trig.evaluate(nothing), "SummaryTrigger fired when the word wasn't really present in the summary")

    def test4NotTrigger(self):
        n = NotTrigger(self.tt)
        b = NewsStory("guid", "title", "subj", "summary", "link")

        self.assertFalse(n.evaluate(b), "A NOT trigger applied to 'always true' DID NOT return false")

        y = NotTrigger(self.ft)
        self.assertTrue(y.evaluate(b), "A NOT trigger applied to 'always false' DID NOT return true")

    def test5AndTrigger(self):
        yy = AndTrigger(self.tt, self.tt2)
        yn = AndTrigger(self.tt, self.ft)
        ny = AndTrigger(self.ft, self.tt)
        nn = AndTrigger(self.ft, self.ft2)
        b = NewsStory("guid", "title", "subj", "summary", "link")

        self.assertTrue(yy.evaluate(b), "AND of 'always true' and 'always true' should be true")
        self.assertFalse(yn.evaluate(b), "AND of 'always true' and 'always false' should be false")
        self.assertFalse(ny.evaluate(b), "AND of 'always false' and 'always true' should be false")
        self.assertFalse(nn.evaluate(b), "AND of 'always false' and 'always false' should be false")

    def test6OrTrigger(self):
        yy = OrTrigger(self.tt, self.tt2)
        yn = OrTrigger(self.tt, self.ft)
        ny = OrTrigger(self.ft, self.tt)
        nn = OrTrigger(self.ft, self.ft2)
        b = NewsStory("guid", "title", "subj", "summary", "link")

        self.assertTrue(yy.evaluate(b), "OR of 'always true' and 'always true' should be true")
        self.assertTrue(yn.evaluate(b), "OR of 'always true' and 'always false' should be true")
        self.assertTrue(ny.evaluate(b), "OR of 'always false' and 'always true' should be true")
        self.assertFalse(nn.evaluate(b), "OR of 'always false' and 'always false' should be false")

    def test7PhraseTrigger(self):
        pt = PhraseTrigger("New York City")
        a = NewsStory('', "asfdNew York Cityasfdasdfasdf", '', '', '')
        b = NewsStory('', '', "asdfasfdNew York Cityasfdasdfasdf", '', '')
        c = NewsStory('', '', '', "asdfasfdNew York Cityasfdasdfasdf", '')
        noa = NewsStory('', "something something new york city", '', '', '')
        nob = NewsStory('', '', "something something new york city", '', '')
        noc = NewsStory('', '', '', "something something new york city", '')


        self.assertTrue(pt.evaluate(a), "PhraseTrigger doesn't find phrase in title")
        self.assertTrue(pt.evaluate(b), "PhraseTrigger doesn't find phrase in subject")
        self.assertTrue(pt.evaluate(c), "PhraseTrigger doesn't find phrase in summary")
    
        for s in [noa, nob, noc]:
            self.assertFalse(pt.evaluate(s), "PhraseTrigger is case-insensitive, and shouldn't be")

    def test8FilterStories(self):
        pt = PhraseTrigger("New York City")
        a = NewsStory('', "asfdNew York Cityasfdasdfasdf", '', '', '')
        b = NewsStory('', '', "asdfasfdNew York Cityasfdasdfasdf", '', '')
        c = NewsStory('', '', '', "asdfasfdNew York Cityasfdasdfasdf", '')
        noa = NewsStory('', "something something new york city", '', '', '')
        nob = NewsStory('', '', "something something new york city", '', '')
        noc = NewsStory('', '', '', "something something new york city", '')

        triggers = [pt, self.tt, self.ft]
        stories = [a, b, c, noa, nob, noc]
        filteredStories = filterStories(stories, triggers)
        for story in stories:
            self.assertTrue(story in filteredStories)
        filteredStories = filterStories(stories, [self.ft])
        self.assertEquals(len(filteredStories), 0)

    def test8FilterStories2(self):
        pt = PhraseTrigger("New York City")
        a = NewsStory('', "asfdNew York Cityasfdasdfasdf", '', '', '')
        b = NewsStory('', '', "asdfasfdNew York Cityasfdasdfasdf", '', '')
        c = NewsStory('', '', '', "asdfasfdNew York Cityasfdasdfasdf", '')
        noa = NewsStory('', "something something new york city", '', '', '')
        nob = NewsStory('', '', "something something new york city", '', '')
        noc = NewsStory('', '', '', "something something new york city", '')

        class MatchTrigger(Trigger):
            def __init__(self, story):
                self.story = story
            def evaluate(self, story):
                return story == self.story
        triggers = [MatchTrigger(a), MatchTrigger(nob)]
        stories = [a, b, c, noa, nob, noc]
        filteredStories = filterStories(stories, triggers)
        self.assertTrue(a in filteredStories)
        self.assertTrue(nob in filteredStories)
        self.assertEquals(2, len(filteredStories))


if __name__ == "__main__":
    suite = unittest.TestSuite()
    suite.addTest(unittest.makeSuite(ProblemSet6NewsStory))
    suite.addTest(unittest.makeSuite(ProblemSet6))
    unittest.TextTestRunner(verbosity=2).run(suite)
