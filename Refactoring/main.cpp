#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    Human(const string& name, const string& profession)
        : name_(name),
          profession(profession) {}

    virtual void Walk(const string& destination) const {
        cout << profession << " " << name_ << " walks to: " << destination << endl;
    }

    const string name_;
    const string profession;
};

class Student : public Human {
public:
    Student(const string& name, const string& favouriteSong)
        : Human(name, "Student"),
          FavouriteSong(favouriteSong) {}

    void Learn() {
        cout << profession << " " << name_ << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << profession << " " << name_ << " walks to: " << destination << endl;
        cout << profession << " " << name_ << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << profession << " " << name_ << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};

class Teacher : public Human {
public:
    Teacher(const string& name, const string& subject)
        : Human(name, "Teacher"),
          Subject(subject) {}

    void Teach() {
        cout << profession << " " << name_ << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};

class Policeman : public Human {
public:
    Policeman(const string& name)
        : Human(name, "Policeman"),
          profession_("Policeman"),
          Name_(name) {}

    void Check(const Human& h) {
        cout << profession_ << ": " << Name_ << " checks " << h.profession << ". " << h.profession << "'s name is: "
             << h.name_ << endl;
    }

private:
    const string profession_;
    const string Name_;
};

void VisitPlaces(const Human& h, const vector<string>& places) {
    for (const auto& p : places) {
        h.Walk(p);
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
