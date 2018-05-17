class que:

    def __init__ (self):
        self.que = []

    def enqueue(self, x):
        self.que += [x]

    def dequeue(self):
        tmp = []
        if self.que == []:
            tmp += [False,[]]
            return tmp
        tmp += [True]
        tmp += [self.que[0]]
        self.que = self.que[1:len(self.que)]
        return tmp
