#include <string>
#include <sstream>
#include <map>

long parse_int(std::string number) {
    const std::map<std::string, int> numbersInEnglish{
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}, 
        {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
    };

    std::stringstream parseString(number);
    std::string parseWord = "";
    long answer[] = { 0, 0 };
    unsigned int label = 0;

    while (parseString >> parseWord)
    {
        int pos = 0;
        if ((pos = parseWord.find('-')) > 0)
        {
            int firstPart = numbersInEnglish.find({ parseWord.begin(), parseWord.begin() + pos })->second;
            int secondPart = numbersInEnglish.find({ parseWord.begin() + pos + 1, parseWord.end() })->second;
            answer[label] += (firstPart + secondPart);
        }
        else
        {
            auto it = numbersInEnglish.find(parseWord);
            if (parseWord != "and")
            {
                answer[label] = (*it).second / 100 ? answer[label] * (*it).second : answer[label] + (*it).second;
            }
            label = parseWord == "thousand" ? 1 : label;
        }
    }
    return answer[0] + answer[1];
}
