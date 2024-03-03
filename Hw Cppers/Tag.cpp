# include <string>
# include <stdexcept>
# include "Tag.h"

using std::string, std::vector;

using namespace std;

Tag::Tag(string tagName): tagName(tagName) {
    // TODO: implement constructor checks

    string symbols = "!,.?";

    if (tagName.length() < 2 || tagName.at(0) != '#')
    {

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(tagName.at(0) != '#')
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        throw invalid_argument("Not long enough");
    }

    if (symbols.find(tagName.at(tagName.length() -1)) != -1)
    {

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(tagName.length() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        throw invalid_argument("Invalid tag");
    }
    
    for (int i = 1; i < tagName.size(); i++)
    {
        int ascii = (int)tagName.at(i);

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(tagName.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        if (i == 1 && !(ascii >= 97 && ascii <= 122))
        {
            throw invalid_argument("Invalid tag");
        }
        
        if (!(ascii >= 97 && ascii <= 122)) throw invalid_argument("Invalid tag");
    }



}

string Tag::getTagName() {
    // TODO: implement getter
    return tagName;
}

vector<Post*>& Tag::getTagPosts() {
    // TODO: implement getter
    return tagPosts;
}

void Tag::addTagPost(Post* post) {
    // TODO: add post to tag posts
    if (post == nullptr)
    {
        throw invalid_argument("Invalid");
    }

    tagPosts.push_back(post);
}
