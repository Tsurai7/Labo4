#include <iostream>
#include <ctime>
#include <iomanip>

bool fillTerritory(int** territory, int n, int i, int j, int regionID, int& remainingCells) {
    bool filled = true;
    if (territory[i][j] == 0 && remainingCells != 0) 
    {
        int random = rand() % 4;
        territory[i][j] = regionID;
        filled = false;
        remainingCells--;
        switch (random) {
        case 0:
            if (i - 1 >= 0)
                fillTerritory(territory, n, i - 1, j, regionID, remainingCells);
            break;
        case 1:
            if (i + 1 < n)
                fillTerritory(territory, n, i + 1, j, regionID, remainingCells);
            break;
        case 2:
            if (j - 1 >= 0)
                fillTerritory(territory, n, i, j - 1, regionID, remainingCells);
            break;
        case 3:
            if (j + 1 < n)
                fillTerritory(territory, n, i, j + 1, regionID, remainingCells);
            break;
        }
    }
    return filled;
}


void ElectionHandler() {
    srand(time(0));

    bool first = true;
    bool check = true;
    int* votes;
    int* winners;

    int size, numCandidates, remainingCells;
    int regionID = 1;

    std::cout << "Enter map size (>= 6): " << std::endl;
    std::cin >> size;
    std::cout << "Enter number of candidates (> 2): " << std::endl;
    std::cin >> numCandidates;

    votes = new int[numCandidates];
    for (int i = 0; i < numCandidates; i++) 
        votes[i] = 0;  

    int** territory = new int* [size];

    for (int i = 0; i < size; i++) 
        territory[i] = new int[size];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            territory[i][j] = 0;
    }

    while (check) {
        bool filled;
        remainingCells = rand() % 2 + 3;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (remainingCells != 0) {
                    filled = fillTerritory(territory, size, i, j, regionID, remainingCells);
                    if (filled == false) first = false;                   
                }
            }
        }
        first = true;
        regionID++;
        check = false;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (territory[i][j] == 0)  check = true;          
            }
        }
    }

    winners = new int[regionID - 2];

    for (int i = 0; i < regionID - 2; i++) 
        winners[i] = 0;   

    bool choice = true;
    regionID = 1;

    while (choice) {
        int vote;
        choice = false;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (territory[i][j] == regionID) {
                    vote = rand() % numCandidates;
                    votes[vote]++;
                }
            }
        }

        bool print = false;
        int temp, tempIndex = 0, result = votes[0];
        int count = 0;

        for (int i = 0; i < numCandidates; i++) {
            temp = votes[i];
            if (temp > result) {
                result = temp;
                tempIndex = i;
            }
        }

        for (int i = 0; i < numCandidates; i++) 
            if (votes[i] == result) count++;
                   

        if (count > 1) tempIndex = -1;
        

        winners[regionID - 1] = tempIndex;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (territory[i][j] == regionID) {
                    choice = true;
                    print = true;
                }
            }
        }

        if (print == true) {
            std::cout << "Votes for candidates in Region " << regionID << ": ";
            for (int i = 0; i < numCandidates; i++) 
                std::cout << "Candidate " << i + 1 << ": " << votes[i] << " ";
            
            std::cout << std::endl;
        }

        for (int i = 0; i < numCandidates; i++) 
            votes[i] = 0;
        
        regionID++;
    }

    for (int i = 0; i < regionID - 2; i++) {
        if (winners[i] == -1)
            std::cout << "Region: " << i + 1 << " - Vote lost" << std::endl;
        else
            std::cout << "Region: " << i + 1 << " - " << winners[i] + 1 << " Candidate is the winner" << std::endl;
    }

    int* list = new int[regionID - 2];
    for (int i = 0; i < regionID - 2; i++)
        list[i] = 0;
    

    int count1, maxcount, num, len;
    len = 0; maxcount = 1; num = 0;

    for (int i = 0; i < regionID - 2; i++) {
        count1 = 0;
        for (int j = i; j < regionID - 2; j++)
            if (winners[i] == winners[j] && winners[i] > 0) count1++;
            
        if (count1 == maxcount) {
            list[len] = i;
            len++;
        }
        if (count1 > maxcount) {
            maxcount = count1;
            num = i;
            len = 1;
            list[0] = i;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) 
            std::cout << std::setw(4) << territory[i][j];
        
        std::cout << std::endl;
    }

    std::cout << "And the winner is Candidate " << winners[list[0]] + 1 << std::endl;  
}