void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
    vector<Person> females;
    copy_if(begin(persons), end(persons), back_inserter(females),
            [](const Person& person) {
                return person.gender == Gender::FEMALE;
            });
    cout << "Median age for females = " << ComputeMedianAge(begin(females), end(females)) << endl;
    vector<Person> males;
    copy_if(begin(persons), end(persons), back_inserter(males),
            [](const Person& person) {
                return person.gender == Gender::MALE;
            });
    cout << "Median age for males = " << ComputeMedianAge(begin(males), end(males)) << endl;
    vector<Person> emp_f;
    copy_if(begin(persons), end(persons), back_inserter(emp_f),
            [](const Person& person) {
                return person.gender == Gender::FEMALE && person.is_employed == true;
            });
    cout << "Median age for employed females = " << ComputeMedianAge(begin(emp_f), end(emp_f)) << endl;
    vector<Person> unemp_f;
    copy_if(begin(persons), end(persons), back_inserter(unemp_f),
            [](const Person& person) {
                return person.gender == Gender::FEMALE && person.is_employed == false;
            });
    cout << "Median age for unemployed females = " << ComputeMedianAge(begin(unemp_f), end(unemp_f)) << endl;
    vector<Person> emp_males;
    copy_if(begin(persons), end(persons), back_inserter(emp_males),
            [](const Person& person) {
                return person.gender == Gender::MALE && person.is_employed == true;
            });
    cout << "Median age for employed males = " << ComputeMedianAge(begin(emp_males), end(emp_males)) << endl;
    vector<Person> unemp_males;
    copy_if(begin(persons), end(persons), back_inserter(unemp_males),
            [](const Person& person) {
                return person.gender == Gender::MALE && person.is_employed == false;
            });
    cout << "Median age for unemployed males = " << ComputeMedianAge(begin(unemp_males), end(unemp_males)) << endl;
}