# include <iostream>
# include <string>
# include <stdexcept>
# include "Network.h"

using std::cout, std::cin, std::endl, std::string, std::vector;

using namespace std;

void printMenu() {
    cout << "Welcome to CPPeers" << endl;
    cout << "The options are: " << endl;
    cout << "1. load data file and add information" << endl;
    cout << "2. show posts by user" << endl;
    cout << "3. show posts with hashtag" << endl;
    cout << "4. show most popular hashtag" << endl;
    cout << "9. quit" << endl;
    cout << "--------> Enter your option: ";
}

void processLoad(Network& cppeers) {
    string fileName = "";
    cout << "Enter filename: ";
    cin >> fileName;
    cppeers.loadFromFile(fileName);
}

void processPostsByUser(Network& cppeers) {
    // TODO: implement

    string username;

    int count1 = 0;

    int count2 = 0;

    cout << "Enter username: ";

    cin >> username;

    vector<Post *> posts = cppeers.getPostsByUser(username);

    for (int i = 0; i < posts.size(); i++)
    {

        for(int i = 0; i < 10; ++i)
        {
            if(posts.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        string pst = posts[i]->getPostText();

        cout << pst << endl;
    }


}

void processPostsWithHashtags(Network& cppeers) {
    // TODO: implement

    string tag;

    int count1 = 0;

    int count2 = 0;

    cout << "Enter tagname: ";

    cin >> tag;

    vector<Post *> posts = cppeers.getPostsWithTag(tag);

    for (int i = 0; i < posts.size(); i++)
    {

        for(int i = 0; i < 10; ++i)
        {
            if(posts.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }
        
        cout << posts[i]->getPostText() << endl;
    }

}

void processMostPopularHashtag(Network& cppeers) {
    // TODO: implement

    vector<string> tags = cppeers.getMostPopularHashtag();

    int count1 = 0;

    int count2 = 0;

    for (int i = 0; i < tags.size(); i++)
    {

        for(int i = 0; i < 10; ++i)
        {
            if(tags.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        cout << tags[i] << endl;
    }

}

int main() {
     //TODO: uncomment at the end

     try {
         Network cppeers;

         int choice = 0;

         do {
             printMenu();
             cin >> choice;
             switch(choice) {
                 case 1: {
                     processLoad(cppeers);
                     break;
                 }
                 case 2: {
                     processPostsByUser(cppeers);
                     break;
                 }
                 case 3: {
                     processPostsWithHashtags(cppeers);
                     break;
                 }
                 case 4: {
                     processMostPopularHashtag(cppeers);
                     break;
                 }
             }
         } while (choice != 9);
     } catch (std::exception& exc) {
         std::cout << exc.what() << endl;
     }

    return 0;
}
