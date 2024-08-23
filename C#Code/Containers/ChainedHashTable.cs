using System.Text;

namespace Containers;

public class ChainedHashTable {
    private const int tableSize = 10;
    private int _currentSize = 0;
    private readonly List<string>[] _dataHolder;
    public bool IsEmpty => _currentSize == 0;
    public int Count => _currentSize;
    public ChainedHashTable() {
        _dataHolder = new List<string>[tableSize];
        for (int i = 0; i < _dataHolder.Length; i++) {
            _dataHolder[i] = new List<string>();
        }
    }
    public ChainedHashTable(params string[] words) : this() => InsertRange(words);
    public ChainedHashTable(IEnumerable<string> words) : this() => InsertRange(words);
    private uint GetHash(string value) =>
        value.Aggregate(0u, (hash, character) => hash += hash ^ character) ^ ((uint)value.Length * (uint)value.Length);
    private uint GetId(uint hash) =>
        hash % tableSize;
    public void Insert(string input) {
        _dataHolder[GetId(GetHash(input))].Add(input);
        _currentSize++;
    }
    public void InsertRange(IEnumerable<string> input) {
        foreach(var inputItem in input) {
            Insert(inputItem);
        }
    }
    public bool Contain(string input) => IsEmpty ? false : _dataHolder[GetId(GetHash(input))].Any(x => x == input);
    public void Remove(string input) {
        if (IsEmpty) {
            return;
        }
        _dataHolder[GetId(GetHash(input))].Remove(input);
        _currentSize--;
    }
    public void RemoveRange(IEnumerable<string> input) {
        foreach (var inputItem in input) {
            Remove(inputItem);
        }
    }
    public void Clear() {
        foreach (var list in _dataHolder) { 
            list.Clear();
        }
    }
    public override string ToString() {
        StringBuilder sb = new StringBuilder();
        sb.Append($"{base.ToString()}{{Count:{Count},TableSize:{tableSize},Table:\n");
        for (int index = 0; index < _dataHolder.Length; index++) {
            List<string> list = _dataHolder[index];
            sb.Append($"Chain[{index}]:");
            if (IsEmpty) {
                sb.Append("Empty");
            }
            list.ForEach(item => sb.Append($"[{item}]"));
            sb.Append('\n');
        }
        sb.Append('}');
        return sb.ToString();
    }
}