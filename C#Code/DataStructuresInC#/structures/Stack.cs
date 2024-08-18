namespace structures
{
    public class Stack {
        private List<char> dataHolder;

        public Stack(){
            dataHolder = new List<char>();
        }

        public void Insert(char c) => dataHolder.Add(c);

        public void Pop() => dataHolder.RemoveAt(dataHolder.Count - 1);
        public char Top() => dataHolder.Last();
        public bool Contains(char c) {
            dataHolder.Find(x => x == c);
            return true;
        }
        public int Count => dataHolder.Count;
        public bool IsEmpty => dataHolder.Count == 0;
    }
}
