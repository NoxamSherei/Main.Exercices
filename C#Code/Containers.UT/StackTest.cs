using FluentAssertions;

namespace Containers.UT;

[TestClass]
public class StackTest {
    private readonly Stack _stack = new();
    private readonly List<int> _testItems = new() { 1, 2, 3, 4, 5 };
    [TestMethod]
    public void Ctor() {
        Stack stack2 = new(1, 2, 3, 4);

        _stack.Should().NotBeNull();
        stack2.Should().NotBeNull();
        _stack.IsEmpty.Should().BeTrue();
        stack2.IsEmpty.Should().BeFalse();
        _stack.Top().Should().Be(0);
        stack2.Top().Should().Be(4);
    }

    [TestMethod]
    public void Inserting() {
        for (int i = 0; i < _testItems.Count; i++) {
            int item = _testItems[i];
            _stack.Insert(item);
            _stack.Top().Should().Be(item);
            _stack.Count.Should().Be(i+1);
            _stack.IsEmpty.Should().BeFalse();
        }
    }

    [TestMethod]
    public void Removing() {
        for (int i = 0; i < _testItems.Count; i++) {
            int item = _testItems[i];
            _stack.Insert(item);
        }
        _stack.Count.Should().Be(_testItems.Count);
        foreach (var item in _testItems.Reverse<int>()) {
            _stack.Top().Should().Be(item);
            _stack.Remove();
        }
        _stack.Count.Should().Be(0);
    }
    [TestMethod]
    public void RunToString() {
        _stack.ToString().Should().Be("Containers.Stack{Count:0,Top:0,Elems:Empty}");
        for (int i = 0; i < _testItems.Count; i++) {
            int item = _testItems[i];
            _stack.Insert(item);
        }
        _stack.ToString().Should().Be("Containers.Stack{Count:5,Top:5,Elems:[1][2][3][4][5]}");
    }
}