from sklearn.cross_validation import train_test_split
from sklearn.metrics import classification_report
from sklearn import datasets
from nolearn.dbn import DBN
import numpy as np
import datetime

print "[X] downloading data..."
dataset = datasets.fetch_mldata("MNIST Original")

(trainX, testX, trainY, testY) = train_test_split(
	dataset.data / 255.0, dataset.target.astype("int0"), test_size = 0.33)

startTime = datetime.datetime.now();

dbn = DBN(
	[trainX.shape[1], 300, 10],
	learn_rates = 0.3,
	learn_rate_decays = 0.9,
	epochs = 10,
	verbose = 1)
dbn.fit(trainX, trainY)

preds = dbn.predict(testX)
endTime = datetime.datetime.now()
print 'Use time: '+str(endTime-startTime)
print classification_report(testY, preds)

for i in np.random.choice(np.arange(0, len(testY)), size = (10,)):
	pred = dbn.predict(np.atleast_2d(testX[i]))
	image = (testX[i] * 255).reshape((28, 28)).astype("uint8")
	print "Actual digit is {0}, predicted {1}".format(testY[i], pred[0])