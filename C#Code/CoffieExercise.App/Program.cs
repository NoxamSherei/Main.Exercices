// See https://aka.ms/new-console-template for more information

using CoffieExercise.App.Model;

Menu menu = new();
menu.Drinks.Add(new Drink() {
    Name = "Americano", Price = 10,
    Ingredients = new List<Ingredient>() {
        new Other(){Name="Water",Temperature=100,Amount=50},
        new Coffee(){Name="Espresso",Temperature=100,coffieType=CoffeeType.Arabica,Amount=50 }
    }
});
menu.Drinks.Add(new Drink() {
    Name = "Cappucino", Price = 10,
    Ingredients = new List<Ingredient>() {
        new Milk(){Name="Milk",Temperature=50,milkType=MilkType.Natural,Form="Foam",Amount=50},
        new Milk(){Name="Milk",Temperature=50,milkType=MilkType.Natural,Form="Steamed Milk",Amount=50},
        new Coffee(){Name="Espresso",Temperature=100,coffieType=CoffeeType.Arabica,Amount=50 }
    }
});
menu.Drinks.Add(new Drink() {
    Name = "Macchiato", Price = 10,
    Ingredients = new List<Ingredient>() {
        new Milk(){Name="Milk",Temperature=50,milkType=MilkType.Natural,Form="Foam",Amount=50},
        new Coffee(){Name="Espresso",Temperature=100,coffieType=CoffeeType.Arabica,Amount=50 }
    }
});


CoffeeConsoleEngine engine = new(menu);
engine.RunProcess();



Console.WriteLine("Hello, World!");
class A {
    bool something=true;
    public void print() { 
        switch 
    }

}


interface ICoffeeEngineState {
    public void ConsolePrint();
}
class CoffeeConsoleEngine {
    //public ICoffeeEngineState state { get; set; }
    public Menu menu { get; set; }
    public CoffeeConsoleEngine(Menu menu) {
        this.menu = menu;
    }
    public void PrintMenu() {
        Console.WriteLine("Menu");
        for (int i = 0; i < menu.Drinks.Count; i++) {
            Drink drink = menu.Drinks[i];
            Console.WriteLine($"[{i}].{drink.Name}, price:{drink.Price:00.00}");
            foreach (var item in drink.Ingredients) {
                string other = string.Empty;
                if (item is Milk) {
                    other += (item as Milk).milkType.ToString() + ",";
                    other += (item as Milk).Form.ToString() + ",";
                }
                if (item is Coffee) {
                    other += (item as Coffee).coffieType.ToString() + ",";
                }
                Console.WriteLine($"\t-{item.Name}, {item.Amount},{item.Temperature},{other}");
            }
        }
        Console.WriteLine("Choose position:");
    }
    public void ConsolePrint() {
        PrintMenu();
    }
    public void RunProcess() {
        ConsolePrint();
        WaitForFeedback();
    }

    private void WaitForFeedback() {
        string s=Console.ReadLine();
        Console.WriteLine("You Write "+s);
    }
}