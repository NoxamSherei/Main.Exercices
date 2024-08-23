using FluentAssertions;

namespace Containers.UT;

[TestClass]
public class QueueTest {
    private readonly Queue _queue = new();
    private readonly List<int> _testItems = new() { 1, 2, 3, 4, 5 };
    [TestMethod]
    public void Ctor() {
        Queue queue2 = new(1, 2, 3, 4);

        _queue.Should().NotBeNull();
        queue2.Should().NotBeNull();
        _queue.IsEmpty.Should().BeTrue();
        queue2.IsEmpty.Should().BeFalse();
        _queue.Top().Should().Be(0);
        queue2.Top().Should().Be(1);
    }

    [TestMethod]
    public void Inserting() {
        for (int i = 0; i < _testItems.Count; i++) {
            int item = _testItems[i];
            _queue.Insert(item);
            _queue.Top().Should().Be(_testItems.First());
            _queue.Count.Should().Be(i+1);
            _queue.IsEmpty.Should().BeFalse();
        }
    }

    [TestMethod]
    public void Removing() {
        for (int i = 0; i < _testItems.Count; i++) {
            int item = _testItems[i];
            _queue.Insert(item);
        }
        _queue.Count.Should().Be(_testItems.Count);
        foreach (var item in _testItems) {
            _queue.Top().Should().Be(item);
            _queue.Remove();
        }
        _queue.Count.Should().Be(0);
    }
    [TestMethod]
    public void RunToString() {
        _queue.ToString().Should().Be("Containers.Queue{Count:0,Top:0,Elems:Empty}");
        for (int i = 0; i < _testItems.Count; i++) {
            int item = _testItems[i];
            _queue.Insert(item);
        }
        _queue.ToString().Should().Be("Containers.Queue{Count:5,Top:1,Elems:[1][2][3][4][5]}");
    }
}