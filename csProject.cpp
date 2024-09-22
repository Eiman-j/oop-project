#include<iostream>
#include<fstream>
#include<string>
#include <conio.h> // For getch()
#include <windows.h> // For Sleep()
#include<cstdlib>
#include<ctime>
//add age plus mechanism

// template<typename T>
// class VirtualPet;

// template<typename T>
// void shop(VirtualPet<T>& pet);

using namespace std;
void clearScreen() {
    system("cls");
}

void startGame()
{
    cout << "Welcome to the Pixel Pals, Virtual Pet Adoptions Centre!" << endl;
    cout << "Press any key to continue..." << endl;
    getch(); // Wait for user input

    clearScreen(); // Clear the screen

    cout << "Looking for your new furry friend..." << endl;
    Sleep(2000); // Sleep for 2 seconds
    clearScreen();

    cout << "Adorable pets waiting for loving homes..." << endl;
    Sleep(2000); // Sleep for 2 seconds
    clearScreen();

    cout << "Finding the perfect match for you..." << endl;
    Sleep(2000); // Sleep for 2 seconds
    clearScreen();

    cout << "Time To Choose Your Pet Pal!" << endl;

}//animation


template<typename T>
class VirtualPet
{
    protected:
    int ageCategoryIndex;
    T age;
    unsigned int healthPoints;//MAX 5(can add error handling)
    unsigned int happinessLevel;//can be string or int depending on derived class
    unsigned int hungerLevel;
    string ageCategory[3] = {"Baby", "Toddler", "Grown-up"};
    public:
    string name;
    bool fancyHat;
    bool stylishOutfit;
    bool gourmetTreats;
    unsigned int coins;
    string color;
    VirtualPet()
    {
        //constructor
    }
    VirtualPet(T age, string name)
    {
        
        this->age = age;
        this->name = name;
        
    }
    void deductCoins(int amount)
    {
        if(coins>=amount)
        {
            coins-=amount;
            cout<<"Coins deducted: "<<amount<<endl;
        }
        else
        {
            cout<<"Not enough coins!"<<endl;
        }
    }
    void increaseHungerLevel()
    {
        if(hungerLevel>5)
        {
            hungerLevel = 5;
        }
        else if (hungerLevel==5)
        {
            healthPoints--;
        }
        else
        {
            hungerLevel++;
            cout<<"Fed pet, new hunger level: "<<hungerLevel<<endl;
        }

    }
    void decreaseHungerLevel()
    {
        if (hungerLevel==0)
        {
            cout<<"Already full..."<<endl;
        }
        else
        {
            hungerLevel--;
            cout<<"Fed pet, new hunger level: "<<hungerLevel<<endl;
        }
    }
    void increaseHappinessLevel()
    {
        if(happinessLevel>100)
        {
            happinessLevel=100;
        }
        else if(happinessLevel==100)
        {
            cout<<"Completely Happy... "<<endl;
        }
        else
        {
            happinessLevel += 10;
        }

    }
    void decreaseHappinessLevel()
    {
        if(happinessLevel==0)
        {
            cout<<"So Sad..."<<endl;
        }
        else
        {
            happinessLevel -= 10;
        }
    }
    void increaseHealthPoints()
    {
        if(healthPoints>5)
        {
            healthPoints = 5;
        }
        else if(healthPoints==5)
        {
            cout<<"Perfectly Healthy Pet..."<<endl;
        }
        else
        {
            healthPoints++;
        }
    }
    virtual void feeding()
    {
        cout<<name<<" is munching on delicious food. Yum!"<<endl;
        cout<<"Nom Nom..."<<endl;
        decreaseHungerLevel();
    }
    void training()
    {
        if(gourmetTreats)
        {
        cout<<"Time to train "<<name<<" and have so much fun! Treats!!!"<<endl;
        increaseHappinessLevel();
        increaseHungerLevel();
        coins +=100;
        }
        else
        {
            cout<<"Shop for treats first!"<<endl;
        }
    }
    void playing(){
        cout<<name<<" wants to play with you!"<<endl;
        cout<<"Play with me and make me :D"<<endl;
        increaseHappinessLevel();
        increaseHungerLevel();
        coins+=90;
    }
    void grooming(){
        cout<<"Time to look sharp and handsome :p Grooming Day!"<<endl;
        cout<<name<<" enjoys self-care hehe"<<endl;
        increaseHappinessLevel();
        coins+=70;
    }
    void visitingVet(){
        cout<<"Oh No! please dont take "<<name<<" to the vet!"<<endl;
        cout<<name<<" does not like the vet *huffs*"<<endl;
        decreaseHappinessLevel();
        increaseHealthPoints();
        coins+=35;
    }
    void displayInfo(){

    cout<<"Your pet's info! Don't forget to feed your pet :< "<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Name: " <<name<<endl;
    cout<<"Age: " <<age<<endl;
    cout<<"Health Points: " <<healthPoints<<endl;
    cout<<"Happiness Level: " <<happinessLevel<<endl;
    cout<<"Hunger Level: " <<hungerLevel<<endl;
    cout<<"Color: "<<color<<endl;
    cout<<"Coins: "<<coins<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    }
    void setColor()
    {
        cout<<"Customizing your pet with random color generator..."<<endl;
        srand(time(0));
        int random = rand()% 5+1;
        switch(random)
        {
        case 1:
            cout << name << " is a marshmallow pink." << endl;
            color = "Marshmallow Pink";
            break;
        case 2:
            cout << name << " is a pastel green." << endl;
            color = "Pastel Green";
            break;
        case 3:
            cout << name << " is a lovely sage." << endl;
            color = "Lovely Sage";
            break;
        case 4:
            cout << name << " is a sparkly yellow." << endl;
            color = "Sparkly Yellow";
            break;
        case 5:
            cout << name << " is a mysterious lavender." << endl;
            color = "Mysterious Lavender";
            break;
        default:
            cout << name << " couldn't decide on a color, please try again :(" << endl;
            break;
        }
    }

    template<typename U>
    friend VirtualPet<U> loadPetInfo();

    template<typename U>
    friend void savePetInfo(const VirtualPet<U>& pet);
    
    template<typename U>
    friend void checkStats(VirtualPet<U>& pet); // Declaration of friend function

    //generic methods for virtual pets
};

template<typename T>
void checkStats(VirtualPet<T>& pet) {
    if (pet.healthPoints == 5 && pet.hungerLevel == 0 && pet.happinessLevel == 100) {
        pet.age++;
    }
}

// Definition of the friend function for VirtualPet<string>
template<>
void checkStats(VirtualPet<string>& pet) {
    if (pet.healthPoints == 5 && pet.hungerLevel == 0 && pet.happinessLevel == 100) {
        pet.age = pet.ageCategory[++pet.ageCategoryIndex];
    }
}

class Penguin : public VirtualPet<string>
{
    public:
    Penguin(string age, string name): VirtualPet<string>(age, name)
    { 
        ageCategoryIndex = 0;
        coins = 1000;
        hungerLevel = 5;
        happinessLevel = 0;
        healthPoints = 0;
        fancyHat = false;
        stylishOutfit= false;
        gourmetTreats = false;
    }
    //custom methods
    void feelingWarm(){
        cout<<name<<" is feeling extra warm, might need to turn on the air conditioner! *sigh* "<<endl;
    }
    void feeding(){
        cout<<"Feeding "<<name<<" Fish..."<<endl;
        cout<<name<<": I love fish, fish is my favorite. More fish!!!"<<endl;
        coins+=50;
        decreaseHungerLevel();
    }//fish
    
    template<typename U>
    friend VirtualPet<U> loadPetInfo();
    // friend void shop(VirtualPet<string>& pet);

};
class Doggo : public VirtualPet<int>
{
    public:
    //constructor
    Doggo(int age, string name): VirtualPet<int>(age, name)
    {
        ageCategoryIndex = 0;
        coins = 1000;
        hungerLevel = 5;
        happinessLevel = 0;
        healthPoints = 0;
        fancyHat = false;
        stylishOutfit= false;
        gourmetTreats = false;
    }
    void goForAWalk(){
        cout<<name<<" is going for a walk. Woof Woof!"<<endl;
    }
    void feeding()
    {
        cout <<"Feeding "<<name<<" Kibble..."<<endl;
        cout <<name<<": Yummy! Kibble is the best!"<<endl;
        coins+=50;
        decreaseHungerLevel();
        //logic to handle hungerlevel
    }//kibble
    
    template<typename U>
    friend VirtualPet<U> loadPetInfo();

};
class Kitten : public VirtualPet<int>
{
    public:
    //constructor
    Kitten(int age, string name): VirtualPet<int>(age, name)
    {
        ageCategoryIndex = 0;
        coins = 1000;
        hungerLevel = 5;
        happinessLevel = 0;
        healthPoints = 0;
        fancyHat = false;
        stylishOutfit= false;
        gourmetTreats = false;
    }
    void chaseYarn()
    {
        cout<<name<<" is chasing after yarn. So playful!"<<endl;
    }
    void feeding()
    {
        cout<<"Feeding "<<name<<" Wet food..."<<endl;
        cout<<name<<": Wet food is delicious! Meow!"<<endl;
        coins+=50;
        decreaseHungerLevel();
        // Add logic to decrease hunger level and update health points
    }//wetfood
    
    template<typename U>
    friend VirtualPet<U> loadPetInfo();

};
class Panda : public VirtualPet<string>
{
  
    public:
    //constructor
    Panda(string age, string name): VirtualPet<string>(age, name)
    {
        ageCategoryIndex = 0;
        coins = 1000;
        hungerLevel = 5;
        happinessLevel = 0;
        healthPoints = 0;
        fancyHat = false;
        stylishOutfit= false;
        gourmetTreats = false;
    }
    void climbTree(){
        cout<<name <<" is climbing a tree. So agile!"<<endl;
    }
    void feeding(){
        cout<<"Feeding "<<name<<" Bamboo..."<<endl;
        cout<<name<<": Munch munch! Bamboo is the best!"<<endl;
        coins+=50;
        decreaseHungerLevel();
    }//bamboo
   
    template<typename U>
    friend VirtualPet<U> loadPetInfo();
};
class Frog : public VirtualPet<string>
{
    public:

    //constructor
    Frog(string age, string name): VirtualPet<string>(age, name)
    {
        ageCategoryIndex = 0;
        coins = 1000;
        hungerLevel = 5;
        happinessLevel = 0;
        healthPoints = 0;
        fancyHat = false;
        stylishOutfit= false;
        gourmetTreats = false;
    }
    void catchInsect(){
        cout<<name<<" is catching insects. Hop Hop!"<<endl;
    }
    void feeding(){
        cout<<"Feeding "<<name<<" Insects..."<<endl;
        cout<<name<<": Yum! Insects are crunchy!"<<endl;
        coins+=50;
        decreaseHungerLevel();
        // Add logic to decrease hunger level and update health points
    }//insects/bugs
    template<typename U>
    friend VirtualPet<U> loadPetInfo();
};


template <typename T>
void shop(VirtualPet<T>& pet)
{
    //can shop for accessories/clothes, special food, limited edition
    //deduct points if buy somethin
    cout<<"Welcome to the Pet Emporium!"<<endl;
    cout<<"What would you like to buy for your beloved companion?"<<endl;
    cout<<"1. Fancy Hats"<<endl;
    cout<<"2. Stylish Outfits"<<endl;
    cout<<"3. Gourmet Treats"<<endl;
    cout<<"4. Mystery Box"<<endl;
    cout<<"Enter the number of your desired item: ";
    int choice;
    cin>>choice;
    int randomNumber;
    switch(choice) 
    {
        case 1:
            cout << "Your pet now looks fabulous in a fancy hat!" << endl;
            pet.deductCoins(20);
            pet.fancyHat = true;
            break;
        case 2:
            cout << "Your pet is now a fashion icon with its stylish outfit!" << endl;
            pet.deductCoins(40);
            pet.stylishOutfit = true;
            break;
        case 3:
            cout << "Your pet savors the delicious gourmet treats! Bon appétit!" << endl;
            pet.deductCoins(50);
            pet.gourmetTreats= true;
            break;
        case 4:
            cout << "You opened the mystery box and found a surprise gift for your pet!" << endl;
            pet.deductCoins(35);
            srand(time(0));
            randomNumber = rand() % 3 + 1;
            switch(randomNumber)
            {
                case 1:
                cout<<"Mystery box surprise -- A FANCY HAT"<<endl;
                pet.fancyHat = true;
                break;
                case 2:
                cout<<"Mystery box surprise -- A STYLISH OUTFIT"<<endl;
                pet.stylishOutfit = true;
                break;
                case 3:
                cout<<"Mystery box surprise --  GOURMET TREATS"<<endl;
                pet.gourmetTreats =true;
                break;
            }
            break;
        default:
            cout << "Oops! Looks like that's not an option. Try again!" << endl;
            break;
    }
}

template<typename T>
void doActions(VirtualPet<T>& pet)
{
    char ch;
    int choice;
    do {

        pet.displayInfo();
        checkStats(pet); 
        cout << "Start interacting with your pet, make them happy!" << endl;
        cout << "1. Feed your pet" << endl;
        cout << "2. Play with your pet" << endl;
        cout << "3. Groom your pet" << endl;
        cout << "4. Visit the vet" << endl;
        cout << "5. Go shopping for your pet" << endl;
        cout << "6. Train your pet" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: " << endl;
        choice = getch();
try{
        switch (choice)
        {
            case '1':
                pet.feeding();
                break;
            case '2':
                pet.playing();
                break;
            case '3':
                pet.grooming();
                break;
            case '4':
                pet.visitingVet();
                break;
            case '5':
                shop(pet);
                break;
            case '6':
                pet.training();
                break;
            case '7':
                cout<<"Do you wish to save your progress?(Y/N)";
                cin>>ch;
                if(ch=='y'|| ch=='Y')
                {
                    savePetInfo(pet);
                    cout<<"Progress saved..."<<endl;
                }
                else
                {
                    cout<<"Goodbye!"<<endl;
                }
                break;
            default:
                throw runtime_error("Invalid choice. Please try again.");
                break;
        }
        
    }

    catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Display pet information after each interaction
        pet.displayInfo();

    } while (choice != '7');
}
// Function to save pet information to a file
template<typename T>
void savePetInfo(const VirtualPet<T>& pet) {
    ofstream file("saved_pet_info.txt");
    if (file.is_open()) {
        file << pet.name << endl;
        file << pet.age << endl;
        file << pet.healthPoints << endl;
        file << pet.happinessLevel << endl;
        file << pet.hungerLevel << endl;
        file << pet.fancyHat << endl;
        file << pet.stylishOutfit << endl;
        file << pet.gourmetTreats << endl;
        file << pet.coins << endl;
        file << pet.color << endl;
        file.close();
    } else {
        cout << "Unable to save pet information to file." << endl;
    }
}
template<typename T>
VirtualPet<T> loadPetInfo() {
    ifstream file("saved_pet_info.txt");
    VirtualPet<T> pet;

    if (file.good()) {
        file >> pet.name;
        file >> pet.age;
        file >> pet.healthPoints;
        file >> pet.happinessLevel;
        file >> pet.hungerLevel;
        file >> pet.fancyHat;
        file >> pet.stylishOutfit;
        file >> pet.gourmetTreats;
        file >> pet.coins;
        file >> pet.color;
        file.close();
    } else {
        cout<<" "<<endl;
    }
    return pet;
}

int main()
{
    char choice;
    startGame();
    srand(time(0)); // Seed for random number generation


    VirtualPet<int> loadedIntPet = loadPetInfo<int>();
    VirtualPet<string> loadedStringPet = loadPetInfo<string>();
    bool isPetLoaded = (loadedIntPet.name != "" || loadedStringPet.name != "");

    if (isPetLoaded)
    {
        cout << "Previous pet information found!" << endl;
        if (loadedIntPet.name != "")
            loadedIntPet.displayInfo();
        else if (loadedStringPet.name != "")
            loadedStringPet.displayInfo();

        cout << "Do you want to continue with this pet? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
                VirtualPet<int> *intVirtualpet;
                VirtualPet<string> *stringVirtualpet;

                if (loadedIntPet.name != "")
                {
                    intVirtualpet = &loadedIntPet;
                    intVirtualpet->setColor();
                    doActions(*intVirtualpet);
                }
                else if (loadedStringPet.name != "")
                {
                    stringVirtualpet = &loadedStringPet;
                    stringVirtualpet->setColor();
                    doActions(*stringVirtualpet);
                }
        }
    }
    
    if (!isPetLoaded || (isPetLoaded && (choice == 'N' || choice == 'n')))
    {
    VirtualPet<int> *intVirtualpet;
    VirtualPet<string> *stringVirtualpet;
    // Creating virtual pets
    Penguin penguin("Baby", "Pebbles");
    Doggo doggo(2, "Skippy");
    Kitten kitten(3, "Floofy");
    Panda panda("Baby", "Pooh");
    Frog frog("Baby", "Princess");

    // Display the list of pets
    cout << "Take your pick of the ton: " << endl;
    cout << "1. Pebbles the Penguin" << endl;
    cout << "2. Skippy the Doggo" << endl;
    cout << "3. Floofy the Kitten" << endl;
    cout << "4. Pooh the Panda" << endl;
    cout << "5. Princess the Frog" << endl;
    
    char choice2;
    cout << "Enter your choice (1-5): ";
    cin >> choice2;
    try
    {
        if(!isdigit(choice2) || (choice2 < '1' || choice2 > '5'))
        {
            throw "Invalid choice, choose a NUMBER from 1 to 5";
        }
    }
    catch(const char *error)
    {
        cerr << error << '\n';
    }
    
    // Perform actions based on the user's choice of pet
    switch (choice2)
    {
        case '1':
            stringVirtualpet = &penguin;
            stringVirtualpet->setColor();
            penguin.feelingWarm();
            doActions(*stringVirtualpet);
            break;
        case '2':
            intVirtualpet = &doggo;
            intVirtualpet->setColor();
            doggo.goForAWalk();
            doActions(*intVirtualpet);
            break;
        case '3':
            intVirtualpet = &kitten;
            intVirtualpet->setColor();
            kitten.chaseYarn();
            doActions(*intVirtualpet);
            break;
        case '4':
            stringVirtualpet = &panda;
            stringVirtualpet->setColor();
            panda.climbTree();
            doActions(*stringVirtualpet);
            break;
        case '5':
            stringVirtualpet = &frog;
            stringVirtualpet->setColor();
            frog.catchInsect();
            doActions(*stringVirtualpet);
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            
    }
    

    }



    return 0;
}


