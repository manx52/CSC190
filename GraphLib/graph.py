class graph:
    def __init__(self):
        self.store = []
        self.vert = 0
        self.s = [1]
    def addVertex(self,n):
        if n <= 0:
            return -1
        for i in range(0,n):
            self.store += [[]]
            self.vert += 1
        return self.vert
    def addEdge(self,from_idx,to_idx,directed,weight):
        if from_idx  > self.vert - 1  or to_idx > self.vert - 1 or from_idx  < 0 or to_idx < 0 or not(weight != 0):
            return False

        if directed == True:
            self.store[from_idx] += [[to_idx,weight]]
        else:
            self.store[from_idx] += [[to_idx,weight]]
            self.store[to_idx] += [[from_idx,weight]]

        return True
    def IsSim(self,x,y):
        count = 0
        if len(x) != len(y):
            return False
        for i in x:
            for j in y:
                if i == j:
                    count+= 1

        if count == len(x):
            return True
        return False

    def connectivity(self,vx,vy):
        tmp = [False,False]
        if vx > self.vert - 1  or vy > self.vert - 1 or vx  < 0 or  vy < 0:
            return [False,False]
        x = self.traverse(vx,True)
        y = self.traverse(vy,True)

        for i in x[0]:
            if vy == i:
                tmp[0] = True
        for i in y[0]:
            if vx == i:
                tmp[1] = True
        return tmp

    def help1(self,start,end, visit,path):
        visit[start] = True
        path += [start]
        if start == end:
            #print path
            return path
        else:
            for i in self.store[start]:
                if visit[i[0]] == False:
                    t = self.help1(i[0], end, visit, path)
                    if t != None:
 return path

            #return path




        path.pop()
        visit[start]= False



    def path(self,vx,vy):
        tmp = [[],[]]
        if vx > self.vert - 1  or vy > self.vert - 1 or vx  < 0 or  vy < 0:
            return tmp
        t = self.connectivity(vx,vy)
        x = self.traverse(vx,True)
        y = self.traverse(vy,True)
        if t[0] == True:
            path = []
            visit = [False] * self.vert
            self.help1(vx,vy,visit,path)
            #print path
            tmp[0] = path
        if t[1] == True:
            path = []
            visit = [False] * self.vert
            self.help1(vy,vx,visit,path)
            #print path
            tmp[1] = path

        return tmp





    def traverse(self,start,typeBreadth):
        final = []
        if (typeBreadth != True and typeBreadth != False) or start > self.vert-1 or (start < 0 and start != None):
            return 4
        if start == None and typeBreadth == True:
            c = []

            for i in range(0,self.vert):
                dis = [False] * self.vert
                pro = [False] * self.vert
                tmp = []
                #print i
                #print dis[i]
                if dis[i] == False:
                    c += self.store[i]
                    tmp += [i]
                    pro[i] = True
                    dis[i] = True

                while len(c) != 0:
                    w = c[0][0]
                    #print c
                                    #print w
                    c = c[1:len(c)]
                    if pro[w] == False:
                        dis[w] = True
                        tmp += [w]
                        pro[w] = True
                    l = list(self.store[w])
                    #print 45
                    #print l
                    for x in l:
                        #print x[0]
                        #print dis[x[0]]
                        if dis[x[0]] == False:
                            c += [x]
                            dis[x[0]] = True
                #print tmp
                if len(tmp) > 0:
                    if len(final) >= 1:
                        count = 0
                        for i in final:
                            if self.IsSim(tmp,i):
                                count = 1
                        if count == 0:
                            final += [tmp]

                    else:
                        final += [tmp]

        elif start != None and typeBreadth == True:
            c = []
            dis = [False] * self.vert
            pro = [False] * self.vert


            tmp = []
            #print i
            #print dis[i]
            if dis[start] == False:
                c += self.store[start]
                tmp += [start]
                pro[start] = True
                dis[start] = True

            while len(c) != 0:
                w = c[0][0]
                #print c
                #print w
                c = c[1:len(c)]
                if pro[w] == False:
                    dis[w] = True
                    tmp += [w]
                    pro[w] = True
                l = list(self.store[w])
                #print 45
                #print l
                for x in l:
                    #print x[0]
                    #print dis[x[0]]
                    if dis[x[0]] == False:
                        c += [x]
                        dis[x[0]] = True
            #print tmp
             final += [tmp]

        if start == None and typeBreadth == False:
            c = []

            for i in range(0,self.vert):
                #print self.store
                dis = [False] * self.vert
                pro = [False] * self.vert
                tmp = []
                #print i
                #print dis[i]
                if dis[i] == False:
                    c += self.store[i]
                    tmp += [i]
                    pro[i] = True
                    dis[i] = True

                while len(c) != 0:

                    w = c[len(c)-1][0]
                    #print c
                    #print w
                    c = c[0:len(c)-1]
                    if pro[w] == False:
                        dis[w] = True
                        tmp += [w]
                        pro[w] = True

                    l = list(self.store[w])
                    #print 45
                    #print l
                    for x in l:
                        #print x[0]
                        #print dis[x[0]]
                        if dis[x[0]] == False:
                            tmp += [x[0]]
                            c = self.store[x[0]] + c
                            dis[x[0]] = True
                            pro[x[0]] = True
                #print tmp
                if len(tmp) > 0:

                    if len(final) >= 1:
                        count = 0
                        for i in final:
                            if self.IsSim(tmp,i):
                                count = 1
                        if count == 0:
                            final += [tmp]

                    else:
                        final += [tmp]


        if start != None and typeBreadth == False:
            c = []
            dis = [False] * self.vert
            pro = [False] * self.vert


                      tmp = []
            #print i
            #print dis[i]
            if dis[start] == False:
                c += self.store[start]
                tmp += [start]
                pro[start] = True
                dis[start] = True

            while len(c) != 0:

                w = c[len(c)-1][0]
                #print c
                #print w
                c = c[0:len(c)-1]
                if pro[w] == False:
                    dis[w] = True
                    tmp += [w]
                    pro[w] = True


                l = list(self.store[w])

                #print 45
                #print l
                for x in l:
                    #print x[0]
                    #print dis[x[0]]
                    if dis[x[0]] == False:
                        tmp += [x[0]]
                        c = self.store[x[0]] + c
                        #print l
                        dis[x[0]] = True
                        pro[x[0]] = True
                #print c
            #print tmp
            if len(tmp) > 0:
                final += [tmp]



        return final
    def printEdges(self):
        print self.store

                                                         
