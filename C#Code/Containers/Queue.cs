using System.Linq;
using System.Text;

namespace Containers;

public class Queue {
    private readonly List<int> _dataHolder = new();
    private int TopId => 0;
    public bool IsEmpty => _dataHolder.Count == 0;
    public int Count => _dataHolder.Count;

    public Queue() { }
    public Queue(params int[] ints) => _dataHolder.AddRange(ints);

    public void Insert(int value) => _dataHolder.Add(value);
    public bool Remove() {
        if (IsEmpty) { return false; }
        _dataHolder.RemoveAt(TopId);
        return true;
    }
    public void Clear() => _dataHolder.Clear();
    public int Top() => _dataHolder.FirstOrDefault();
    public override string ToString() {
        StringBuilder sb = new StringBuilder();
        sb.Append($"{base.ToString()}{{Count:{Count},Top:{Top()},Elems:");
        if (IsEmpty) {
            sb.Append("Empty");
        }
        _dataHolder.ForEach(item => sb.Append($"[{item}]"));
        sb.Append('}');
        return sb.ToString();
    }
}