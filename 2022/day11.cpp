#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <sstream>

// #define ROUND_NUM 20
//

struct Monkey
{
    int counter, divisor, if_true, if_false, operator_val;
    char operation; // has 5 possible states : a, s, m, d, p
    std::vector<int> queue;
    
    Monkey() : counter(0) {}

    void set_queue_vals(std::string str) {
      std::string segment;
      std::stringstream strstream(str);
      while (std::getline(strstream, segment, ',')) {
        queue.push_back(stoi(segment.substr(1))); // cut off leading whitespace
      }
      // std::cout << "not queue\n";
    }

    static char get_operation(std::string str)
    {
        if (str[25] == 'o')
        {
            return 'p';
        }
        
        switch (str[23])
        {
            case '+':
                return 'a';
            case '-':
                return 's';
            case '*':
                return 'm';
            default:
                return 'd';
        }
    }
};

std::vector<Monkey> monkeys;

void fill_monkeys_vec()
{
    std::ifstream from_file("data/day11.input");
    std::string str;
    char op;
    while (getline(from_file, str))
    {
        monkeys.push_back(*new Monkey());

        getline(from_file, str);
        monkeys.back().set_queue_vals(str.substr(17));
        
        getline(from_file, str);
        op = Monkey::get_operation(str);
        monkeys.back().operation = op;
        if (op != 'p')
        {
            monkeys.back().operator_val = stoi(str.substr(25));
        }
        // std::cout << "not operator val\n";
        
        getline(from_file, str);
        monkeys.back().divisor = stoi(str.substr(21)); // ...hardcoded
        // std::cout << "not divisor\n";
        
        getline(from_file, str);
        monkeys.back().if_true = stoi(str.substr(29));
        // std::cout << "not if_true\n";
        
        getline(from_file, str);
        monkeys.back().if_false = stoi(str.substr(30));
        // std::cout << monkeys.back().if_true << ' ' << monkeys.back().if_false << '\n';
        
        getline(from_file, str);
    }
}

void process_round()
{
    int worry_lvl;
    for (auto monkey : monkeys)
    {
        for (int obj : monkey.queue) // process objects from queue
        // for (int i = 0; i < monkey.queue.size(); ++i)
        {
            std::cout << monkey.queue.size() << '\n';
            // worry_lvl = monkey.queue.pop_back();
            // int obj = monkey.queue.back();
            monkey.counter++;
            switch(monkey.operation)
            {
                case 'a':
                    worry_lvl = obj + monkey.operator_val;
                    // worry_lvl += monkey.operator_val;
                    break;
                case 's':
                    worry_lvl = obj - monkey.operator_val;
                    // worry_lvl -= monkey.operator_val;
                    break;
                case 'm':
                    worry_lvl = obj * monkey.operator_val;
                    // worry_lvl *= monkey.operator_val;
                    break;
                case 'd':
                    worry_lvl = obj / monkey.operator_val;
                    break;
                case 'p':
                    worry_lvl = obj * obj;
            }

            monkeys[(!worry_lvl % monkey.divisor) ? monkey.if_true : monkey.if_false].queue.push_back(obj);
        }

        monkey.queue.clear();
    }   
}

void part1()
{
    fill_monkeys_vec();
    int const ROUND_NUM = 20;
    // for (int i = 0; i < ROUND_NUM; ++i, process_round());

    int max1 = 0, max2 = 0;
    for (auto monkey : monkeys) // find two max values
    {
        if (monkey.counter > max2)
        {
            max1 = max2;
            max2 = monkey.counter;
        }
    }
        
    std::cout << max1 * max2 << '\n';
}

int main()
{
    part1();
    return 0;
}
