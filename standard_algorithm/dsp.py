



class DSP:
    def __init__(self,nodes,representative):
        self.nodes = nodes
        self.representative = representative

    # find representative element
    def find(self,element):

        index = -1
        for i,item in enumerate(self.nodes):
            if item==element:
                index = i 

        while self.representative[index]!=index:
            index = self.representative[index]

        return index


    def combine(self,element1,element2):

        r1 = self.find(element1)
        r2 = self.find(element2)

        self.representative[r2] = r1

    def printSolution(self):
        print(self.nodes)
        print(self.representative)



nodes = ['a','b','c','d','e','f','g','h']
representative = [0,1,2,3,4,5,6,7]
dsp_obj = DSP(nodes,representative)
dsp_obj.combine('b','c')
dsp_obj.combine('g','h')
dsp_obj.combine('a','c')
dsp_obj.printSolution()




