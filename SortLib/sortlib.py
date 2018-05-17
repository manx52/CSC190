def selection_sort(u):
        for i in range(len(u)):
                m = i
                for j in range(i+1, len(u)):
                        if u[m] > u[j]:
                                m = j
                tmp = u[i]
                u[i] = u[m]
                u[m] = tmp

        return True

def heapify(u):
        for i in range(len(u),-1,-1):
                helper_heap(u,len(u),i)
        return True
def helper_heap(u,end,root):

    left = (2* root) +1
    right = (2* root) + 2

    m = root
    if left < end and u[root] < u[left]:
        m = left

    if right < end and u[m] < u[right]:
        m = right
    if m != root:
        tmp = u[root]
        u[root] = u[m]
        u[m] = tmp
        helper_heap(u,end,m)
    return True

def reheapify(u,end):
   tmp = u[0]
   u[0] = u[end]
   u[end] = tmp
   return True

def heap_sort(u):
   heapify(u)
   for i in range(len(u)-1,0,-1):
        reheapify(u,i)
        helper_heap(u,i,0)
   return True

def merge_sort(u):
        helper_recur(u);
        return True
def helper_recur(u):
        if len(u) <  2:
                return u
        mid = len(u) /2
        left = helper_recur(u[:mid])
    #print left
        right = helper_recur(u[mid:])
        #print right

        helper_merge(u,left,right);
        return u
def helper_merge(u,left,right):

        tmp = []
        i =0
        j = 0

        while len(right) + len(left) > len(tmp):
                if left[i] < right[j]:

                        tmp += [left[i]]
                        i += 1
                else:
                        tmp += [right[j]]
                        j += 1
                if i == len(left):
                        tmp += right[j:]
                        break
                if j == len(right):
                        tmp += left[i:]
                        break
        for i in range(len(u)):
                u[i]  = tmp[i]

