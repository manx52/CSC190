class stack():
    def __init__(self):
        self.stack = []

    def push (self, val):
        self.stack += [val]

    def pop (self):
        self.stack = self.stack[0:len(self.stack)-1]

