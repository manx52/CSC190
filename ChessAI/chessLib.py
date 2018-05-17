from chessPlayer_que import *
from chessPlayer_tree import *
import time
def getPiece(name):
    if name=="pawn":
        return 0
    elif name=="knight":
        return 1
    elif name=="bishop":
        return 2
    elif name=="rook":
        return 3
    elif name=="queen":
        return 4
    elif name=="king":
        return 5
    else:
        return -1

def genBoard():
    r=[0]*64
    White=10
    Black=20
    for i in [ White, Black ]:
        if i==White:
            factor=+1
            shift=0
        else:
            factor=-1
            shift=63

        r[shift+factor*7] = r[shift+factor*0] = i+getPiece("rook")
        r[shift+factor*6] = r[shift+factor*1] = i+getPiece("knight")
        r[shift+factor*5] = r[shift+factor*2] = i+getPiece("bishop")
        if i==White:
            r[shift+factor*4] = i+getPiece("queen") # queen is on its own color square
            r[shift+factor*3] = i+getPiece("king")
        else:
            r[shift+factor*3] = i+getPiece("queen") # queen is on its own color square
            r[shift+factor*4] = i+getPiece("king")

        for j in range(0,8):
            r[shift+factor*(j+8)] = i+getPiece("pawn")

    return r

def printBoard(board):
    accum="---- BLACK SIDE ----\n"
    max=63
    for j in range(0,8,1):
        for i in range(max-j*8,max-j*8-8,-1):
            accum=accum+'{0: <5}'.format(board[i])
        accum=accum+"\n"
    accum=accum+"---- WHITE SIDE ----"
    return accum

def GetPlayerPositions(board,player):
    tmp = []
    for i in range(0,64):
        if (board[i] >= player and board[i] <= (player + 5)):
            tmp += [i]
    return tmp
def IsFriendly(pp, board, cp):
    if board[cp] // 10 == 1 and board[pp] // 10 == 1:
        return False
    elif board[cp] // 20 == 1 and board[pp] // 20 == 1:
        return False
    else:
        return True

def IsOnBoard(pp,board, cp):
    if (pp >= 0) and (pp <= 63) :
        return True
    else:
        return False

def IsCollision(pp, board, cp):
    if board[cp] // 10 == 1 and board[pp] // 20 == 1:
        return 1
    elif board[cp] // 20 == 1 and board[pp] // 10 == 1:
        return 1
    if board[cp] // 20 == 1 and board[pp] // 20 == 1:
        return 2
    elif board[cp] // 10 == 1 and board[pp] // 10 == 1:
        return 2
    else:
        return 0

def GetBishopMoves(pos,board):
    nr = pos % 8
    nl = 7 - (pos % 8)
    accum=[]
    ul = pos
    ll = pos
    ur = pos
    lr = pos
    for i in range(0,nr,1):
        lr -= 9
        if IsOnBoard(lr,board,pos):
            if IsCollision(lr, board, pos) == 1:
                accum += [lr]
                break
            elif IsCollision(lr, board, pos) == 2:
                break
            else:
                accum += [lr]

    for i in range(0,nr,1):
        ur += 7
        if IsOnBoard(ur,board,pos):
            if IsCollision(ur, board, pos) == 1:
                accum += [ur]
                break
            elif IsCollision(ur, board, pos) == 2:
                break
            else:
                accum += [ur]

    for i in range(0,nl,1):
        ll -= 7
        if IsOnBoard(ll,board,pos):
            if IsCollision(ll, board, pos) == 1:
accum += [ul]
                break
            elif IsCollision(ul, board, pos) == 2:
                break
            else:
                accum += [ul]
    return accum

def GetRookMoves(pos,board):
    nl = pos % 8
    nr = 7 - (pos % 8)
    nd = pos / 8
    nu = 7 - (pos / 8)
    #print nl,nr,nd,nu
    accum=[]
    l=r=u=d=pos
    for i in range(0,nl,1):
        l -= 1
        if IsOnBoard(l,board,pos):
            if IsCollision(l, board, pos) == 1:
                accum += [l]
                break
            elif IsCollision(l, board, pos) == 2:
                break
            else:
                accum += [l]

    for i in range(0,nr,1):
        r += 1
        if IsOnBoard(r,board,pos):
            if IsCollision(r, board, pos) == 1:
                accum += [r]
                break
            elif IsCollision(r, board, pos) == 2:
                break
            else:
                accum += [r]

    for i in range(0,nd,1):
        d -= 8
        if IsOnBoard(d,board,pos):
            if IsCollision(d, board, pos) == 1:
 accum += [d]
                break
            elif IsCollision(d, board, pos) == 2:
                break
            else:
                accum += [d]
    #print nu
    for i in range(0,nu,1):
        u += 8
        if IsOnBoard(u,board,pos):
            if IsCollision(u, board, pos) == 1:
                accum += [u]
                break
            elif IsCollision(u, board, pos) == 2:
                break
            else:
                accum += [u]

    return accum

def GetQueenMoves(pos,board):
    return GetRookMoves(pos,board) + GetBishopMoves(pos,board)

def GetPawnMoves(pos, board):
    tmp = []
    if board[pos] // 10 == 1:
        pp = pos + 8
        if IsOnBoard(pp, board, pos) and IsFriendly(pp,board,pos):
            tmp += [pp]
        ppr = pos + 7
        if IsOnBoard(ppr, board, pos) and IsCollision(ppr,board,pos) == 1:
            tmp += [ppr]
        ppl = pos + 9
        if IsOnBoard(ppl, board, pos) and IsCollision(ppl,board,pos) == 1:
            tmp += [ppl]
    if board[pos] // 20 == 1:
        pp = pos - 8
        if IsOnBoard(pp, board, pos) and IsFriendly(pp,board,pos):
            tmp += [pp]
        ppr = pos - 7
        if IsOnBoard(ppr, board, pos) and IsCollision(ppr,board,pos) == 1:
            tmp += [ppr]
        ppl = pos - 9
        if IsOnBoard(ppl, board, pos) and IsCollision(ppl,board,pos) == 1:
            tmp += [ppl]

    return tmp

def GetKingMoves(pos, board):
    tmp = []
    nr = pos % 8
    nl = 7 - (pos % 8)
    nd = pos / 8
    nu = 7 - (pos / 8)
    ppu = pos + 8
    if IsOnBoard(ppu, board, pos) and nu >= 1  and IsFriendly(ppu,board,pos):
        tmp += [ppu]
    ppd = pos - 8
    if IsOnBoard(ppd, board, pos) and nd >= 1  and IsFriendly(ppd,board,pos):
        tmp += [ppd]

 ppr = pos - 1
    if IsOnBoard(ppr, board, pos) and nr >= 1  and IsFriendly(ppr,board,pos):
        tmp += [ppr]
    ppl= pos + 1
    if IsOnBoard(ppl, board, pos) and nl >= 1  and IsFriendly(ppl,board,pos) :
        tmp += [ppl]
    ppur = pos+7
    if IsOnBoard(ppur, board, pos) and nr >= 1 and nu >= 1  and IsFriendly(ppur,board,pos):
        tmp += [ppur]
    ppul = pos + 9
    if IsOnBoard(ppul, board, pos) and nl >= 1 and nu >= 1  and IsFriendly(ppul,board,pos):
        tmp += [ppul]
    ppdr = pos -9
    if IsOnBoard(ppdr, board, pos) and nr >= 1 and nd >= 1  and IsFriendly(ppdr,board,pos):
        tmp += [ppdr]
    ppdl = pos -7
    if IsOnBoard(ppdl, board, pos) and nl >= 1 and nd >= 1  and IsFriendly(ppdl,board,pos):
        tmp += [ppdl]

    return tmp
def GetKnightMoves(pos,board):
    tmp = []
    nr = pos % 8
    nl = 7 - (pos % 8)
    nd = pos / 8
    nu = 7 - (pos / 8)
    uhr = (pos + (8+8-1) )
    ulr = (pos + (8-2))
    uhl = (pos + (8+8+1))
    ull = (pos + (8+2))
    lhr = (pos + (-8-8-1))
    llr = (pos + (-8-2))
    lhl = (pos + (-8-8+1))
    lll = (pos + (-8+2))
    if IsOnBoard(uhr,board,pos) and nr >= 1 and nu >= 2  and IsFriendly(uhr,board,pos):
        tmp += [uhr]
    if IsOnBoard(ulr,board,pos) and nr >= 2 and nu >= 1  and IsFriendly(ulr,board,pos):
        tmp += [ulr]
    if IsOnBoard(uhl,board,pos) and nl >= 1 and nu >= 2  and IsFriendly(uhl,board,pos):
        tmp += [uhl]
    if IsOnBoard(ull,board,pos) and nl >= 2 and nu >= 1  and IsFriendly(ull,board,pos):
        tmp += [ull]
    if IsOnBoard(lhr,board,pos) and nr >= 1 and nd >= 2  and IsFriendly(lhr,board,pos):
        tmp += [lhr]
    if IsOnBoard(llr,board,pos) and nr >= 2 and nd >= 1  and IsFriendly(llr,board,pos):
        tmp += [llr]
    if IsOnBoard(lhl,board,pos) and nl >= 1 and nd >= 2  and IsFriendly(lhl,board,pos):
        tmp += [lhl]
    if IsOnBoard(lll,board,pos) and nl >= 2 and nd >= 1  and IsFriendly(lll,board,pos):
        tmp += [lll]
    return tmp

def GetPieceLegalMoves(board,position):
    tmp = []
    if position < 0 or position > 63:
        return tmp
    if board[position] // 10 == 1:
        if board[position] - 10 == 0:
            tmp += GetPawnMoves(position, board)
 elif board[position] - 10 == 1:
            tmp += GetKnightMoves(position, board)
        elif board[position] - 10 == 2:
            tmp += GetBishopMoves(position, board)
        elif board[position] - 10 == 3:
            tmp += GetRookMoves(position, board)
        elif board[position] - 10 == 4:
            tmp += GetQueenMoves(position, board)
        elif board[position] - 10 == 5:
            tmp += GetKingMoves(position, board)
    elif board[position] // 20 == 1:
        if board[position] - 20 == 0:
            tmp += GetPawnMoves(position, board)
        elif board[position] - 20 == 1:
            tmp += GetKnightMoves(position, board)
        elif board[position] - 20 == 2:
            tmp += GetBishopMoves(position, board)
        elif board[position] - 20 == 3:
            tmp += GetRookMoves(position, board)
        elif board[position] - 20 == 4:
            tmp += GetQueenMoves(position, board)
        elif board[position] - 20 == 5:
            tmp += GetKingMoves(position, board)
    return tmp

def IsPositionUnderThreat(board,position,player):
    if position < 0 or position > 63:
        return False
    if player == 10:
        pieces = GetPlayerPositions(board, 20)
        for i in pieces:
            moves = GetPieceLegalMoves(board,i)
            for j in moves:
                if j == position:
                    return True
    if player == 20:
        pieces = GetPlayerPositions(board, 10)
        for i in pieces:
            moves = GetPieceLegalMoves(board,i)
            for j in moves:
                if j == position:
                    return True
    return False

def GetCandidateList(board,player, tree):
    tmp = []
    for i in tree.store[1]:
        tmp += [[i.store[0],i.score]]
    return tmp



def ptsLost(board, pos):
    pts = 0
 if board[pos] // 10 == 1:
        if board[pos] - 10 == 0:
            pts = -10
        elif board[pos] - 10 == 1:
            pts = -30
        elif board[pos] - 10 == 2:
            pts = -30
        elif board[pos] - 10 == 3:
            pts = -50
        elif board[pos] - 10 == 4:
            pts = -90
        elif board[pos] - 10 == 5:
            pts = -900
    if board[pos] // 20 == 1:
        if board[pos] - 20 == 0:
            pts = -10
        elif board[pos] - 20 == 1:
            pts = -30
        elif board[pos] - 20 == 2:
            pts = -30
        elif board[pos] - 20 == 3:
            pts = -50
        elif board[pos] - 20 == 4:
            pts = -90
        elif board[pos] - 20 == 5:
            pts = -900
    return pts

def ptsGain(board, pos):
    pts = 0;
    if board[pos] // 10 == 1:
        if board[pos] - 10 == 0:
            pts = 10.0
        elif board[pos] - 10 == 1:
            pts = 30.0
        elif board[pos] - 10 == 2:
            pts = 30.0
        elif board[pos] - 10 == 3:
            pts = 50.0
        elif board[pos] - 10 == 4:
            pts = 90.0
        elif board[pos] - 10 == 5:
            pts = 900.0
    if board[pos] // 20 == 1:
        if board[pos] - 20 == 0:
            pts = 10.0
        elif board[pos] - 20 == 1:
            pts = 30.0
        elif board[pos] - 20 == 2:
            pts = 30.0
        elif board[pos] - 20 == 3:
            pts = 50.0
        elif board[pos] - 20 == 4:
            pts = 90.0
        elif board[pos] - 20 == 5:
            pts = 900.0
    return pts
def IsCheck(board, player, k):
    if IsPositionUnderThreat(board,k,player):
        return True
    return False
def FindKing(board, player, pieces):
    found = -1
    if player == 10:
        for i in pieces:
            if board[i] == 15:
                found = i
    if player == 20:
        for i in pieces:
            if board[i] == 25:
                found = i
    if found == -1:
        return False
    else:
        return found
def GenTree(board, player):
    pieces = GetPlayerPositions(board, player)
    king= FindKing(board, player, pieces)
    if IsCheck(board, player, king):
        pieces = [king]

    allMoves = []
    for i in pieces:
        moves = GetPieceLegalMoves(board ,i)
        for j in moves:
            allMoves +=  [[i,j]]
    moveTree = tree(0)
    for k in allMoves:
        tmp = tree(k)
        moveTree.AddSuccessor(tmp)
    return moveTree

def AddDepth (board, player, Tree):
    if Tree.store[0] == 0:
        i = 0
        for node in Tree.store[1]:
            tmp = MakeMove(board,player, node.store[0])
            AddDepth(board, player, Tree.store[1][i])

            for n in node.store[1]:
                tmp1 = MakeMove(board,player, n.store[0])
                if player // 10 == 1:
                    AddDepth(board, 20, n)
                else:
                    AddDepth(board, 10, n)
                UndoMove(board,player, n.store[0], tmp1)


            UndoMove(board,player, node.store[0],tmp)
            i+=1
    else:
        if player == 10:
            pieces = GetPlayerPositions(board, 20)
            king= FindKing(board, 20, pieces)
            if IsCheck(board, 20, king):
                pieces = [king]
            allMoves = []
            for i in pieces:
                moves = GetPieceLegalMoves(board ,i)
                for j in moves:
                    allMoves +=  [[i,j]]

            for k in allMoves:
                tmp = tree(k)
                Tree.AddSuccessor(tmp)
            for j in Tree.store[1]:
                tmp1 = MakeMove(board,20, j.store[0])
                j.score = Eval(board, 20)
                UndoMove(board,20, j.store[0], tmp1)


        if player == 20:
            pieces = GetPlayerPositions(board, 10)
            king= FindKing(board, 10, pieces)
            if IsCheck(board, 10, king):
                pieces = [king]

            allMoves = []
            for i in pieces:
                moves = GetPieceLegalMoves(board ,i)
                for j in moves:
                    allMoves +=  [[i,j]]

            for k in allMoves:
                tmp = tree(k)
                Tree.AddSuccessor(tmp)


            for j in Tree.store[1]:
                tmp1 = MakeMove(board,10, j.store[0])
                j.score = Eval(board, 10)
                UndoMove(board,10, j.store[0], tmp1)

def Eval(board, player):
    if player // 10 == 1:
        w = 0
        b = 0
        friend = GetPlayerPositions(board, 10)
        enemy = GetPlayerPositions(board, 20)
        for i in friend:
            w += ptsGain(board, i)
        for j in enemy:
            b += ptsGain(board, j)
        return w-b
    if player // 20 == 1:
        w = 0
        b = 0
        friend = GetPlayerPositions(board, 20)
        enemy = GetPlayerPositions(board, 10)
        for i in friend:
            b += ptsGain(board, i)
        for j in enemy:
            w += ptsGain(board, j)
        return b-w

def MakeMove(board, player, move):
    tmp = board[move[1]]
    board[move[1]] = board[move[0]]
    board[move[0]] = 0
    return tmp

def UndoMove(board, player, move, tmp):
    board[move[0]] = board[move[1]]
    board[move[1]] = tmp

def MinMax(board, player, depth, tree):
    if tree.store[1]  != []:
        for node in tree.store[1]:
            node.score = MinMax(board,player,depth + 1,node)
            #print node.score

        if depth+1 % 2 == 1:
            tmp = []
            for i in tree.store[1]:
                tmp += [i.score]
            return max(tmp)
        else:
            tmp = []
            for i in tree.store[1]:
                tmp += [i.score]
            return min(tmp)

    else:
        return tree.score
def BestMove(board, player, tree):
    move = []
    if tree.store[0] == 0:
        tmp = []
        count = 0
        for j in tree.store[1]:
            tmp += [j.score]
        tt = tmp[0]
        for k in range(1, len(tree.store[1])):
            if tt == tmp[k]:
                count += 1
            else:
                count = 0
                break

        if count == len(tree.store[1])-1:

            for i in tree.store[1]:
                if board[i.store[0][0]] // player == 1 and board[i.store[0][0]] - player == 0:
                    move = i.store[0]
        else:
            m = -2391
            for i in tree.store[1]:
                tmp = max(m,i.score)
                if i.score == tmp:
                    move = i.store[0]
                    m = tmp
    return move

def chessPlayer(board, player):
    status = []
    status += [True]
    root = GenTree(board,player)
    AddDepth(board, player, root)
    root.score = MinMax(board,player,0,root)
    move = BestMove(board, player, root)
    status += [move]
    can = GetCandidateList(board, player,root)
    status+= [can]
    status += [root.Get_LevelOrder()]

    return status
