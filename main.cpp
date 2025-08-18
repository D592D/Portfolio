#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <cctype> // Required for std::tolower

// Class to track and manage grocery item frequencies
class GroceryTracker {
private:
    std::map<std::string, int> itemFrequencies;
    const std::string inputFileName = "CS210_Project_Three_Input_File.txt";
    const std::string outputFileName = "frequency.dat";

    // Helper function to normalize an item name by converting to lowercase
    // and removing a trailing 's' for simple pluralization handling
    void normalizeItemName(std::string& item) {
        // Convert the entire string to lowercase
        for (char& c : item) {
            c = std::tolower(c);
        }

        // Remove a trailing 's' to normalize to a singular form
        if (item.length() > 1 && item.back() == 's') {
            item.pop_back();
        }
    }

    // Helper function to read data from the input file and populate the map
    bool loadData() {
        std::ifstream inputFile(inputFileName);
        if (!inputFile.is_open()) {
            std::cerr << "Error: Could not open input file " << inputFileName << std::endl;
            return false;
        }

        std::string item;
        while (std::getline(inputFile, item)) {
            // Normalize the item name before adding to the map
            normalizeItemName(item);
            // Increment the frequency of the item.
            itemFrequencies[item]++;
        }
        inputFile.close();
        return true;
    }

    // Helper function to write the frequency data to the backup file
    void writeBackupFile() {
        std::ofstream outputFile(outputFileName);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Could not create backup file " << outputFileName << std::endl;
            return;
        }

        for (const auto& pair : itemFrequencies) {
            outputFile << pair.first << " " << pair.second << std::endl;
        }
        outputFile.close();
    }

public:
    // Constructor to load data and create the backup file upon instantiation
    GroceryTracker() {
        if (loadData()) {
            writeBackupFile();
        }
    }

    // Menu Option 1: Search for a specific item's frequency
    void searchItemFrequency() {
        std::string itemToFind;
        std::cout << "Enter the item you wish to look for: ";
        std::cin >> itemToFind;

        // Normalize the user input to match the normalized keys in the map
        normalizeItemName(itemToFind);

        // Check if the item exists in the map
        if (itemFrequencies.count(itemToFind) > 0) {
            std::cout << itemToFind << " appeared " << itemFrequencies.at(itemToFind) << " time(s)." << std::endl;
        } else {
            std::cout << itemToFind << " was not found." << std::endl;
        }
    }

    // Menu Option 2: Print a list of all items and their frequencies
    void printFrequencies() {
        std::cout << "\nItem Frequencies:" << std::endl;
        for (const auto& pair : itemFrequencies) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    // Menu Option 3: Print a text-based histogram of item frequencies
    void printHistogram() {
        std::cout << "\nItem Frequency Histogram:" << std::endl;
        for (const auto& pair : itemFrequencies) {
            std::cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};

// Function to display the user menu
void displayMenu() {
    std::cout << "\n*** Corner Grocer Main Menu ***" << std::endl;
    std::cout << "1. Look up an item's frequency" << std::endl;
    std::cout << "2. Print a list of all items and their frequencies" << std::endl;
    std::cout << "3. Print a histogram of all item frequencies" << std::endl;
    std::cout << "4. Exit the program" << std::endl;
    std::cout << "Please enter your selection (1-4): ";
}

int main() {
    // Instantiate the GroceryTracker object. This automatically loads data and creates the backup file.
    GroceryTracker tracker;

    int choice = 0;
    while (choice != 4) {
        displayMenu();
        std::cin >> choice;

        // Input validation to handle non-integer input and invalid choices
        while (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid selection. Please enter a number between 1 and 4." << std::endl;
            displayMenu();
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                tracker.searchItemFrequency();
                break;
            case 2:
                tracker.printFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
        }
    }

    return 0;
}