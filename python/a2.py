def get_length(dna):
    ''' (str) -> int

    Return the length of the DNA sequence dna.

    >>> get_length('ATCGAT')
    6
    >>> get_length('ATCG')
    4
    '''

    return len(dna)


def is_longer(dna1, dna2):
    ''' (str, str) -> bool

    Return True if and only if DNA sequence dna1 is longer than DNA sequence
    dna2.

    >>> is_longer('ATCG', 'AT')
    True
    >>> is_longer('ATCG', 'ATCGGA')
    False
    '''

    if dna1 > dna2:
       return True
    else:
       return False


def count_nucleotides(dna, nucleotide):
    ''' (str, str) -> int

    Return the number of occurrences of nucleotide in the DNA sequence dna.

    >>> count_nucleotides('ATCGGC', 'G')
    2
    >>> count_nucleotides('ATCTA', 'G')
    0
    '''
    
    return dna.count(nucleotide)


def contains_sequence(dna1, dna2):
    ''' (str, str) -> bool

    Return True if and only if DNA sequence dna2 occurs in the DNA sequence
    dna1.

    >>> contains_sequence('ATCGGC', 'GG')
    True
    >>> contains_sequence('ATCGGC', 'GT')
    False
    '''
    
    if dna1.find(dna2) != -1:
       return True
    else:
       return False


def is_valid_sequence(dna):
    '''(str) -> bool

    Return True if and only if the DNA sequence dna is valid (that is, it
    contains no characters other than 'A', 'T', 'C' and 'G').

    >>> is_valid_sequence('ATCG')
    True
    >>> is_valid_sequence('ATNCG')
    False
    >>> is_valid_sequence('ATnCG')
    False
    '''

    num_invalid = 0

    for char in dna:
       if char in 'abcdefghijklmnopqrstuvwxyzBDEFHIJKLMNOPQRSUVWXYZ' :
          num_invalid = num_invalid + 1

    if num_invalid > 0:
        return False
    else:
        return True


def insert_sequence(dna1, dna2, index):
    '''(str, str, int) -> str

    Return the DNA sequence dna1 obtained by inserting the second DNA sequence
    dna2 into the first DNA sequence dna1 at the given index.

    >>> insert_sequence('CCGG', 'AT', 2)
    'CCATGG'
    >>> insert_sequence('TCGT', 'AT', 2)
    'TCATGT'
    '''

    return dna1[:index] + dna2 + dna1[index:]


def get_complement(nucleotide):
    '''(str) -> str

    Return the nucleotide's complement.

    >>> get_complement('A')
    'T'
    >>> get_complement('C')
    'G'
    '''

    if nucleotide == 'A':
        return 'T'
    elif nucleotide == 'T':
        return 'A'
    elif nucleotide == 'C':
        return 'G'
    else:
        return 'C'


def get_complementary_sequence(dna):
    '''(str) -> str

    Return the DNA sequence that is complementary to the given DNA sequence dna.

    >>> get_complementary_sequence('AT')
    'TA'
    >>> get_complementary_sequence('CG')
    'GC'
    >>> get_complementary_sequence('ATCG')
    'TAGC'
    '''

    new_dna = ''

    for char in dna:
        new_dna = new_dna + get_complement(char)

    return new_dna


