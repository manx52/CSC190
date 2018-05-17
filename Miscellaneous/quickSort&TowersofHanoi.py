def quick_sort(u,ini,fin):
   if ini < fin:
      pIndex = partition(u,ini,fin)
      quick_sort(u,ini,pIndex-1)
      quick_sort(u,pIndex+1,fin)


def partition(u,ini,fin):
#   select a pivot
#   separate u into two sections
#   return pIndex
        pval = u[ini]
        lm = ini+1
        rm = fin

        while rm >= lm:
                if u[lm] > pval:
                        if u[rm] < pval:
                                tmp = u[lm]
                                u[lm] = u[rm]
                                u[rm] = tmp
                        else:
                                rm  -= 1
                else:
                        lm+=1
        tmp = pval
        u[ini] = u[rm]
        u[rm] = tmp
        return rm

def hanoi(n,start,tmp,final):
   if n > 0:
        hanoi(n - 1,start,final,tmp)
        final.append(start.pop())
        hanoi(n - 1,tmp,start,final)
        print start,tmp,final
        return True
   else:
        return True

