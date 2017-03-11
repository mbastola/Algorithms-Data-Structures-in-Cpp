

def editDistance(s1,s2,i,j,array):
    if array[i][j]<0:
        if i==len(s1):
            array[i][j] = len(array)-j-1
        elif j == len(s2):
            array[i][j] = len(s2)-i-1
        elif s1[i] ==s2[j]:
            array[i][j]=0
            editDistance(s1,s2,i+1,j+1,array)
            
        else:
            array[i][j] = 1+ min(editDistance(s1,s2,i+1,j+1,array),editDistance(s1,s2,i,j+1,array),editDistance(s1,s2,i+1,j,array))
    return array[i][j]

def editD(s1,s2,i,j):
    numRows = len(s1)+1
    numCols = len(s2)+1

    array = []
    for x in range(numRows):
        array.append([-1] * numCols )
    editDistance(s1,s2,i,j,array)
    mystr=''
    for row in range(numRows):
        for col in range(numCols):
            mystr += '  ' + str(array[row][col]) + '  '
        mystr += '\n'
    print(mystr)
