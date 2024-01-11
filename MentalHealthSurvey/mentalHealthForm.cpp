#include <iostream>
#include <string>

class MentalHealthSurvey {
public:
    void startSurvey();
    void askQuestion(const std::string& question, std::string& answer);
    void askQuestion(const std::string& question, int& answer);
    void displayResults();
    void suggestCopingStrategies();

private:
    std::string name;
    int age;
    std::string gender;
    std::string country;
    std::string state;
    std::string education;
    std::string employment;
    std::string familyHistory;
    std::string treatment;
    std::string workInterference;
    std::string triggerPoints;
    int sleepHabits;
    std::string copingStrategies;

    // Scoring variables
    int anxietyScore;
    int depressionScore;
    int stressScore;

    void assessMentalHealth();
};

void MentalHealthSurvey::startSurvey() {
    // Get user input
    askQuestion("Name: ", name);
    askQuestion("Age: ", age);
    askQuestion("Gender: ", gender);
    askQuestion("Country: ", country);
    askQuestion("State: ", state);
    askQuestion("Education (select one option):\n1. Primary Education\n2. Secondary Education\n3. Undergraduate\n4. Post Graduate\n", education);
    askQuestion("Employment (select one option):\n1. Employed\n2. Unemployed\n3. Student\n", employment);
    askQuestion("Family History of Mental Health Issues (Yes/No): ", familyHistory);
    askQuestion("Are you currently undergoing any treatment for mental health (Yes/No): ", treatment);
    askQuestion("How much does work interfere with your mental health (Low/Medium/High): ", workInterference);
    askQuestion("Do you experience trigger points that worsen your mental health (Yes/No): ", triggerPoints);
    askQuestion("Average hours of sleep per day: ", sleepHabits);
    askQuestion("Coping Strategies with Mental Health (briefly describe): ", copingStrategies);

    // Assess mental health based on user responses
    assessMentalHealth();

    // Suggest coping strategies based on the assessment
    suggestCopingStrategies();

    // Display collected data and results
    displayResults();
}

void MentalHealthSurvey::askQuestion(const std::string& question, std::string& answer) {
    std::cout << question;
    std::getline(std::cin >> std::ws, answer); // Use std::ws to discard leading whitespaces
}

void MentalHealthSurvey::askQuestion(const std::string& question, int& answer) {
    std::cout << question;
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character in the input buffer
}

void MentalHealthSurvey::assessMentalHealth() {
    // Implement a more detailed scoring system (this is just an example, not a real mental health assessment)
    // The higher the score, the more severe the condition might be
    anxietyScore = (triggerPoints == "Yes") ? 3 : 0;
    depressionScore = (familyHistory == "Yes") ? 2 : 0;
    stressScore = 0;

    // Assess stress based on work interference
    if (workInterference == "High") {
        stressScore += 3;
    }
    else if (workInterference == "Medium") {
        stressScore += 2;
    }
    else if (workInterference == "Low") {
        stressScore += 1;
    }

    // Adjust scores based on sleep habits
    if (sleepHabits < 5) {
        anxietyScore += 2;
        stressScore += 2;
    }
    else if (sleepHabits > 8) {
        depressionScore += 1;
        stressScore += 2;
    }

    // Additional factors can be considered for a more accurate assessment
}

void MentalHealthSurvey::suggestCopingStrategies() {
    std::cout << "\nCoping Strategies Suggestions:\n";

    // Suggestions based on assessment scores
    if (anxietyScore > 0) {
        std::cout << "- Practice deep breathing exercises and mindfulness techniques.\n";
        std::cout << "- Consider talking to a friend, family member, or mental health professional about your feelings.\n";
    }

    if (depressionScore > 0) {
        std::cout << "- Engage in activities you enjoy, even if they seem challenging at the moment.\n";
        std::cout << "- Establish a routine with small, achievable goals.\n";
    }

    if (stressScore > 0) {
        std::cout << "- Prioritize self-care, including adequate sleep and regular physical activity.\n";
        std::cout << "- Explore stress-reduction techniques such as meditation or yoga.\n";
    }

    // Additional coping strategies based on specific user responses
    // You can customize this part further based on your survey questions

    std::cout << "\nRemember, seeking professional help is always an option if needed.\n";
}

void MentalHealthSurvey::displayResults() {
    // Display collected data
    std::cout << "\nCollected Data:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Gender: " << gender << "\n";
    std::cout << "Country: " << country << "\n";
    std::cout << "State: " << state << "\n";
    std::cout << "Education: " << education << "\n";
    std::cout << "Employment: " << employment << "\n";
    std::cout << "Family History: " << familyHistory << "\n";
    std::cout << "Treatment for Mental Health: " << treatment << "\n";
    std::cout << "Work Interference of Mental Health: " << workInterference << "\n";
    std::cout << "Trigger Points: " << triggerPoints << "\n";
    std::cout << "Sleep Habits: " << sleepHabits << " hours\n";
    std::cout << "Coping Strategies: " << copingStrategies << "\n";

    // Display mental health assessment
    std::cout << "\nMental Health Assessment:\n";
    std::cout << "Anxiety Score: " << anxietyScore << "\n";
    std::cout << "Depression Score: " << depressionScore << "\n";
    std::cout << "Stress Score: " << stressScore << "\n";

    // Provide a detailed summary based on scores (this is just an example)
    std::cout << "\nSummary:\n";
    if (anxietyScore + depressionScore + stressScore >= 6) {
        std::cout << "It's highly recommended to consult with a mental health professional for a detailed assessment and support.\n";
    }
    else if (anxietyScore + depressionScore + stressScore >= 3) {
        std::cout << "Consider reaching out to a mental health professional for support and guidance.\n";
    }
    else {
        std::cout << "Your mental health seems to be in good condition. Keep practicing healthy habits and seek support if needed.\n";
    }
}

int main() {
    MentalHealthSurvey survey;
    survey.startSurvey();

    return 0;
}