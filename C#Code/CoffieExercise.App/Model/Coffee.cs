namespace CoffieExercise.App.Model;

public abstract class Item {
    public string Name { get; set; } = string.Empty;
    public string Description { get; set; } = string.Empty;
}
public class Drink : Item {
    public decimal Price { get; set; } = 0.00m;
    public List<Ingredient> Ingredients { get; set; } = new();
}
public class Menu {
    public List<Drink> Drinks { get; set; } = new();
}
public abstract class Ingredient : Item {
    public float Temperature { get; set; } = 0;
    public int Amount { get; set; } = 0;
}
public class Other : Ingredient { 
}
public class Coffee : Ingredient {
    public CoffeeType coffieType { get; set; } = CoffeeType.Arabica;
}
public class Milk : Ingredient {
    public string Form { get; set; } = string.Empty;
    public MilkType milkType { get; set; } = MilkType.Natural;
}
public class Tea : Ingredient {
    public TeaType teaType { get; set; }
}
public enum MilkType {
    Natural,
    UHT,
    Vege,
}
public enum CoffeeType {
    Arabica,
    Robusta,
    Excelsa,
    Liberica
}
public enum TeaType {
    Green,
    Black,
    Red,
    Roibos
}