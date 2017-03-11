import time
import random
import sys 

def timeAppends(alist,numBatches,numPerBatch,fileOut):
    fout = open(fileOut,'w')
    for i in range(numBatches):
        start = time.time()
        for j in range(numPerBatch):
            alist.append(j)
        end = time.time()     
        fout.write( str(len(alist))+' '+str(end-start)+'\n')
    fout.close

def timePrepends(alist,numBatches,numPerBatch,fileOut):
    fout = open(fileOut,'w')
    for i in range(numBatches):
        start = time.time()
        for j in range(numPerBatch):
            alist.insert(0,j)
        end = time.time()     
        fout.write( str(len(alist))+' '+str(end-start)+'\n')
    fout.close

def timeInserts(alist,numBatches,numPerBatch,fileOut):
    fout = open(fileOut,'w')
    for i in range(numBatches):
        start = time.time()
        for j in range(numPerBatch):
            alist.insert(len(alist)//2,j)
        end = time.time()     
        fout.write( str(len(alist))+' '+str(end-start)+'\n')
    fout.close

def timeAccesses(alist,numBatches,numPerBatch,fileOut):
    fout = open(fileOut,'w')
    for i in range(numBatches):
        for j in range(numPerBatch):
            alist.append(j)
        size = len(alist)
        start = time.time()
        for k in range(numPerBatch):
            alist[random.randint(0,size-1)]
        end = time.time()     
        fout.write( str(len(alist))+' '+str(end-start)+'\n')
    fout.close

def main():
    alist = []
    operator = sys.argv[1]            ##AHh, how i was in a matrix before I knew this was a pointer!
    numBatches = int(sys.argv[2])            
    numPerBatch = int(sys.argv[3])
    fileOut = sys.argv[4]
    if operator == 'a':
        timeAppends(alist,numBatches,numPerBatch,fileOut)
    elif operator == 'p':
        timePrepends(alist,numBatches,numPerBatch,fileOut)
    elif operator == 'i':
        timeInserts(alist,numBatches,numPerBatch,fileOut)
    elif operator == 'x':
        timeAccesses(alist,numBatches,numPerBatch,fileOut)
    
main()
