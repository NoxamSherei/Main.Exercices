from Stack import IInsert, Stack, IStack
#first comment

def main():
    print("Hello World!")
    myStack: IStack = Stack()
    insertingObj: IInsert = myStack
    print("Print __str__():",str(myStack))
    print("Print __repr__():",repr(myStack))
    #print("Print __str__():",myStack.__str__())
    myStack.insert(1)
    insertingObj.insert(2)
    insertingObj.insert(3)
    myStack.insert(4)
    val=insertingObj.top()
    print( "Top {}==4".format(val))
    print("Print __str__():",str(myStack))
    print("Print __repr__():",repr(myStack))
 
    myStack.remove();
    myStack.remove();
    val=myStack.top()
    
    print("Top {}==2".format(val))
    
    myStack.remove();
    myStack.remove();

    print(f"Top {myStack.top()}==0")
    print("Print __str__():",str(myStack))
    print("Print __repr__():",repr(myStack))

if __name__ == "__main__":
    main()