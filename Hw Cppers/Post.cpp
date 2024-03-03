# include <iostream>
# include <string>
# include <stdexcept>
# include "Post.h"

using std::string, std::vector;

using namespace std;

Post::Post(unsigned int postId, string userName, string postText) : postId(postId), userName(userName), postText(postText) {
    if (postId == 0 || userName == "" || postText == "") {
        throw std::invalid_argument("post constructor: invalid parameter values");
    }
}

unsigned int Post::getPostId() {
    return postId;
}

string Post::getPostUser() {
    return userName;
}

string Post::getPostText() {
    return postText;
}

vector<string> Post::findTags() {
    // TODO: extracts candidate tags based on occurrences of # in the post

    vector<string> tags;

    string copy = postText; 

    string stop = "?.!, ";
    
    while (copy.find('#') != -1)
    {
        int start = copy.find('#');

        int end = start;

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(copy.find('#'))
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }
        
        for (int i = start; i < copy.length(); i++)
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(copy.length() > 5)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }

            if (stop.find(copy.at(i)) != -1)
            {
                break;
            }

            end++;
        }

        string tag = copy.substr(start, end-start);

        string lower = "#";

        for (int i = 1; i < tag.length(); i++)
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(tag.length() > 5)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }

            lower += tolower(tag.at(i));
        }

        bool present = false;

        for (int i = 0; i < tags.size(); i++)
        {

            int count1 = 0;

            int count2 = 0;

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

            if (tags[i] == lower)
            {
                present = true;
            }
        }

        if (!present) tags.push_back(lower);

        copy.erase(start, end-start);
    }

    return tags;


}
