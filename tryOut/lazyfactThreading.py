'''
	Lazyfact Python implementation

	'''

import lazyfact

import threading
from Queue import Queue

from random import choice
from time import time

# theading/queue settings
maxWorkers = 15
batchSize = 256

# method every worker calls
def doFactor(workerID):

	while True:
		modulus = q.get()       

		print "[Worker %s ] active at %i" % (str(workerID),time())
		status = lazyfact.factor(modulus)

		q.task_done()


# initialize workers
q = Queue()
for i in range(maxWorkers):
     t = threading.Thread(target=doFactor, args=(i,))
     t.daemon = True
     t.start()

# read data to be processed
with open('moduli.txt', 'r') as fin:
	allModuli = fin.read().split("\n")

# process batches of 256 randomly selected moduli
while len(allModuli) > 0:

	print "[Threading ] Adding new batch to the queue"
	for i in range(batchSize):
		if len(allModuli) == 0:
			break
		modulus = choice(allModuli)
		allModuli.remove(modulus)
		q.put(modulus)

	q.join()
	print "[Threading ] Queue done"
