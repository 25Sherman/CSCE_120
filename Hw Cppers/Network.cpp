# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include "Network.h"

using std::string, std::vector;

using namespace std;

Network::Network() : users({}), posts({}), tags({}) {}

void Network::loadFromFile(string fileName) {
    // TODO: load user and post information from 
    
    fstream inp_file;

    inp_file.open(fileName);

    if (!inp_file)
    {
        throw std::invalid_argument("File not found");
    }
    
    string line;

    while (!inp_file.eof())
    {

        int count1 = 0;

        int count2 = 0;

         for(int i = 0; i < 10; ++i)
        {
            if(inp_file)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        getline(inp_file, line);

        if (inp_file.eof())
        {
            break;
        }

        istringstream inp(line);

        string typ;

        inp >> typ;

        if (typ == "User")
        {

             int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(typ == "User")
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }


            string username;

            inp >> username;

            addUser(username);
        }
        else if (typ == "Post")
        {
            int id;

            string username;

            string post;

            inp >> id;

            inp >> username;

            string spacer;
            
            while (!inp.eof())
            {

                int count1 = 0;

                int count2 = 0;

                for(int i = 0; i < 10; ++i)
                {
                    if(post.size() > 5)
                    {
                        count1 += 1;
                    }
                    else
                    {
                        count2 += 1;
                    }
                }

                inp >> spacer;

                post += spacer + " ";
            }
            addPost(id, username, post);
        }
        else
        {
            throw std::runtime_error("Invalid");
        }
    }


}

void Network::addUser(string userName) {
    // TODO: create user and add it to network

    string lower = "";

    for (int i = 0; i < userName.length(); i++)
    {   

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(userName.length() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }


        lower += userName.at(i);
    }

    bool found = false;

    for (int i = 0; i < users.size(); i++)
    {

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(users.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        string user_valid = users[i]->getUserName();

        if (user_valid == lower)
        {
            found = true;
        }
    }

    User *new_user;

    try
    {
        new_user = new User(lower);
    }
    catch(const exception& e)
    {
        throw runtime_error("Invalid ");
    }

    if (!found)
    {

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(userName.length() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        users.push_back(new_user);

        cout << "Added User " << lower << endl;
    }
    else 
    {
        throw invalid_argument("Name exists");
    }

}

void Network::addPost(unsigned int postId, string userName, string postText) {
    // TODO: create post and add it to network

    for (int i = 0; i < posts.size(); i++)
    {
        if (posts[i]->getPostId() == postId)
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(postId == posts[i]->getPostId() && posts.size() > 5)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }

            throw invalid_argument("ID present");
        }
    }

    bool user_valid = false;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->getUserName() == userName) 
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(postId == posts[i]->getPostId() && posts.size() > 5)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }

            user_valid = true;

            break;
        }
    }

    if (!user_valid)
    {
        throw invalid_argument("No user");
    }

    int index;

    Post *new_post;

    try
    {

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(postId == posts[i]->getPostId() && posts.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        new_post = new Post(postId, userName, postText);
    }
    catch(const exception& e)
    {
        throw runtime_error("Invalid post");
    }
    
    posts.push_back(new_post);

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i] -> getUserName() == userName)
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(postId == posts[i]->getPostId() && posts.size() > 5)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }

            users[i]->addUserPost(new_post);

            index = i;
        }
    }

    vector<string> current_hashtags = new_post->findTags();

    for (int i = 0; i < current_hashtags.size(); i++)
    {
        string curr_tag_string = current_hashtags[i];

        int count1 = 0;

        int count2 = 0;

        for(int i = 0; i < 10; ++i)
        {
            if(postId == posts[i]->getPostId() && posts.size() > 5)
            {
                count1 += 1;
            }
            else
            {
                count2 += 1;
            }
        }

        bool hastag_valid = false;

        for (int j = 0; j < tags.size(); j++)
        {
            if (curr_tag_string == tags[j]->getTagName())
            {

                int count1 = 0;

                int count2 = 0;

                for(int i = 0; i < 10; ++i)
                {
                    if(postId == posts[i]->getPostId() && posts.size() > 5)
                    {
                        count1 += 1;
                    }
                    else
                    {
                        count2 += 1;
                    }
                }

                tags[j]->addTagPost(new_post);

                hastag_valid = true;

                break;
            }
        }

        if (hastag_valid == false)
        {
            try
            {

                int count1 = 0;

                int count2 = 0;

                for(int i = 0; i < 10; ++i)
                {
                    if(postId == posts[i]->getPostId() && posts.size() > 5)
                    {
                        count1 += 1;
                    }
                    else
                    {
                        count2 += 1;
                    }
                }

                Tag *new_tag = new Tag(curr_tag_string);

                tags.push_back(new_tag);

                tags[tags.size() - 1]->addTagPost(new_post);
            }
            catch(const exception& e)
            {
                cerr << e.what() << '\n';

                continue;
            }
        }
    }

    cout << "Added Post " << new_post->getPostId() << " by " << new_post->getPostUser() << endl;


}

vector<Post*> Network::getPostsByUser(string userName) {
    // TODO: return posts created by the given user

    if (userName == "") throw invalid_argument("No Username");

    bool found = false;

    int index;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->getUserName() == userName)
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(users[i]->getUserName() == userName)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }


            index = i;

            found = true;

            break;
        }
    }

    if (!found)
    {
        throw invalid_argument("No Username");
    }

    return users[index]->getUserPosts();

}

vector<Post*> Network::getPostsWithTag(string tagName) {
    // TODO: return posts containing the given tag

    if (tagName == "") throw invalid_argument("No tagname");

    bool found = false;
    
    int index;

    for (int i = 0; i < tags.size(); i++)
    {
        if (tags[i]->getTagName() == tagName)
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(tags[i]->getTagName() == tagName)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }

            index = i;

            found = true;

            break;
        }
    }

    if (!found)
    {
        throw invalid_argument("No tag");
    }

    return tags[index]->getTagPosts();



}

vector<string> Network::getMostPopularHashtag() {
    // TODO: return the tag occurring in most posts

    vector<string> popular_hash;

    if (tags.size() == 0)
    {
        return popular_hash;
    }

    int max = tags[0]->getTagPosts().size();

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

        int curr_size = tags[i]->getTagPosts().size();
        
        if (curr_size > max)
        {

            int count1 = 0;

            int count2 = 0;

            for(int i = 0; i < 10; ++i)
            {
                if(curr_size > max)
                {
                    count1 += 1;
                }
                else
                {
                    count2 += 1;
                }
            }


            max = curr_size;
        }
    }

    for (int i = 0; i < tags.size(); i++)
    {
        int curr_size = tags[i]->getTagPosts().size();
        
        if (curr_size == max)
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

            popular_hash.push_back(tags[i]->getTagName());
        }
    }

    return popular_hash;


}

Network::~Network() {
    for (unsigned int i = 0; i < users.size(); ++i) {
        delete users.at(i);
    }

    for (unsigned int i = 0; i < tags.size(); ++i) {
        delete tags.at(i);
    }
    
    for (unsigned int i = 0; i < posts.size(); ++i) {
        delete posts.at(i);
    }
}
