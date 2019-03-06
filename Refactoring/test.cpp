#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person{
public:
    Person(const string& name, const string& prof = "Unknown"): name(name), profession_(prof){};

    virtual void Walk(const string& destination) const {
        Log();
        cout<< " walks to: " << destination << endl;
    };


public:
    const string name;
    const string profession_ ;

protected:
    void Log() const{
        cout << profession_ <<": " << name;
    };
};


class Student : public Person{
public:
    Student(const string& name, const string& favouriteSong): Person(name,"Student"), favouriteSong(favouriteSong){};

    void SingSong() const {
        Log();
        cout << " sings a song: " << favouriteSong << endl;
    }

    void Walk(const string& destination) const override{
        Log();
        cout<< " walks to: " << destination << endl;
        SingSong();
    };

    void Learn() const {
        Log();
        cout << " learns" << endl;
    }

private:
    const string favouriteSong;

};

class Teacher : public Person{
public:
    Teacher(const string& name, const string& subject): Person(name,"Teacher"), subject(subject){};

    void Teach() const{
        Log();
        cout<< " teaches: " << subject << endl;
    }
private:
    const string subject;
};

class Policeman : public Person{
public:
    Policeman(const string& name): Person(name,"Policeman"){};

    void Check(const Person& p) const{
        Log();
        cout <<" checks "<<p.profession_<<". "<<p.profession_<<"'s name is "<<p.name<<endl;
    };

};


void VisitPlaces(const Person & per,  vector<string> places)
{
    for (auto p : places) {
        per.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    VisitPlaces(t, {"Moscow", "London"});

    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}


