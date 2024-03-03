# include <string>
# include <stdexcept>
# include "User.h"

using std::string, std::vector;

using namespace std;

User::User(string userName):userName(userName) {
    // TODO: implement constructor checks

    if (userName == "")
    { 
        throw invalid_argument("Invalid");
    }

    for (int i = 0; i < userName.size(); i++)
    {
        
        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(userName.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        int ascii = (int)userName.at(i);

        if (i == 0 && !(ascii >= 97 && ascii <= 122))
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(userName.size() > 5)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }

            throw invalid_argument("Invalid");
        }
        
        if (ascii >= 65 && ascii <= 90) 
        {
            throw invalid_argument("Invalid");
        }
    }

    if (!((int)userName.at(0) >= 97 && (int)userName.at(0) <= 122))
    {

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(userName.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        throw invalid_argument("Invalid");
    }


}

string User::getUserName() {
    // TODO: implement getter

    return userName;

}

vector<Post*>& User::getUserPosts() {
    // TODO: implement getter

    return userPosts;
}

void User::addUserPost(Post* post) {
    // TODO: add post to user posts

     if (post == nullptr)
     {
        throw invalid_argument("Null ptr");
    }

    userPosts.push_back(post);
}
