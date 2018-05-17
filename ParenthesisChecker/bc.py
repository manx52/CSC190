from stackLib import *

def bc (val):
    L = []
    o = stack()
    count = 0
    check = 0
    for x in val:
        if x == '(' or x == '[' or x == '{':
            o.push(x)

        if x == ')' or x == ']' or x == '}':
            if len(o.stack) != 0:
                if '(' == o.stack[-1] and x == ')':
                        o.pop()
                elif '[' == o.stack[-1] and  x == ']':
                        o.pop()
                elif '{' == o.stack[-1] and x == '}':
                        o.pop()
                else:
                        check = 1
                        break

            else:
                check = 1
                break
        count += 1

    if len(o.stack) == 0 and check == 0:
        L += [True]
        L += [0]
    else:
        L += [False]
        L += [count]

    return L
