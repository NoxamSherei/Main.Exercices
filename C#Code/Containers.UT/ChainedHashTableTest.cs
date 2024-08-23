using FluentAssertions;

namespace Containers.UT;

[TestClass]
public class ChainedHashTableTest {
    private readonly ChainedHashTable _container = new();
    private readonly List<string> _testItems = new(sentence.Split(' '));
    private const string sentence = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    
    [TestMethod]
    public void Ctor() {
        ChainedHashTable container2 = new("1", "2", "3", "4");
        ChainedHashTable container3 = new(new List<string>{ "1", "2", "3", "4" });

        _container.Should().NotBeNull();
        container2.Should().NotBeNull();
        container3.Should().NotBeNull();
        _container.IsEmpty.Should().BeTrue();
        container2.IsEmpty.Should().BeFalse();
        container3.IsEmpty.Should().BeFalse();
        _container.Count.Should().Be(0);
        container2.Count.Should().Be(4);
        container3.Count.Should().Be(4);
    }

    [TestMethod]
    public void Inserting() {
        for (int i = 0; i < _testItems.Count; i++) {
            string item = _testItems[i];
            _container.Insert(item);
            _container.Count.Should().Be(i+1);
            _container.IsEmpty.Should().BeFalse();
        }
    }
    [TestMethod]
    public void InsertingAll() {
        _container.IsEmpty.Should().BeTrue();
        _container.InsertRange(_testItems);
        _container.Count.Should().Be(_testItems.Count);
        _container.IsEmpty.Should().BeFalse();
    }

    [TestMethod]
    public void Removing() {
        _container.InsertRange(_testItems);
        _container.Count.Should().Be(_testItems.Count);

        Random rnd = new Random();
        var suffledWords=_testItems.OrderBy((item) => rnd.Next());
        foreach (var item in suffledWords) {
            _container.Contain(item).Should().BeTrue();
            _container.Remove(item);
        }
        _container.IsEmpty.Should().BeTrue();
        _container.Count.Should().Be(0);
    }

    [TestMethod]
    public void RemovingAll() {
        _container.InsertRange(_testItems);
        _container.Count.Should().Be(_testItems.Count);

        Random rnd = new Random();
        List<string> suffledWords=_testItems.OrderBy((item) => rnd.Next()).ToList();
        _container.RemoveRange(suffledWords);
        _container.IsEmpty.Should().BeTrue();
        _container.Count.Should().Be(0);
    }
    [TestMethod]
    public void RunToString() {
        string emptyCase = _container.ToString();
        emptyCase.Should().Contain("Containers.ChainedHashTable{Count:0,TableSize:10,Table:");
        for (int i = 0; i < 10; i++) {
            emptyCase.Should().Contain($"Chain[{i}]:Empty");
        }
        _container.InsertRange(_testItems);

        string fullCase = _container.ToString();
        fullCase.Should().Contain("Containers.ChainedHashTable{Count:91,TableSize:10,Table:");
        fullCase.Should().Contain($"Chain[0]:[Lorem][Lorem][standard][it][It][essentially][It][Lorem][Lorem]");
        fullCase.Should().Contain($"Chain[1]:[and][printer][took][galley][and][make][book.][not][only][and][publishing][software][like]");
        fullCase.Should().Contain($"Chain[2]:[Ipsum][text][Ipsum][has][text][since][has][leap][typesetting,][1960s][release][Ipsum]");
        fullCase.Should().Contain($"Chain[3]:[simply][printing][industry's][five][but][also][versions]");
        fullCase.Should().Contain($"Chain[4]:[dummy][of][dummy][ever][when][of][survived][unchanged.][with][of][with][Aldus][of][Ipsum.]");
        fullCase.Should().Contain($"Chain[5]:[is][type][type][sheets][containing]");
        fullCase.Should().Contain($"Chain[6]:[the][typesetting][the][the][1500s,][an][a][a][the][was][in][the][the]");
        fullCase.Should().Contain($"Chain[7]:[industry.][unknown][scrambled][popularised][passages,][more][desktop][PageMaker]");
        fullCase.Should().Contain($"Chain[8]:[been][specimen][centuries,][remaining][Letraset][including]");
        fullCase.Should().Contain($"Chain[9]:[to][into][electronic][recently]");
        fullCase.Should().EndWith("}");
    }
}
