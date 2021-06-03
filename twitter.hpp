#ifndef TWITTER_HPP
#define TWITTER_HPP

#include <iostream>
#include <string>
using namespace std;

// Insert code here for the Tweet class from Project 2
class Tweet
{
protected:
    string username;//member variables
    string message;
    int charLength;



public:
    string getUsername()//username getter
{
    return username;
}

    string getMessage()//message getter
{
    return message;    
}

int getLength()//length getter
{
    return charLength;    
}

void setUsername(string u)//username setter
{
    username = u;  
}

void setMessage(string m)//message setter
{
    message = m;
}

Tweet()//default constructor
{
    username = "";
    message = "";
    charLength = 0;
}

Tweet(string u, string m)//2nd default constuctor
{
    username = u;
    message = m;
    charLength = m.length();
}


virtual void display()//display function
{
    cout << "@" << username <<":" << message <<endl;
}
};



// Insert code here for the MultiTweet class that inherits from Tweet
class MultiTweet:public Tweet 
{
private:
    string subMessages[100];
    int size;
public:

    void splitTweets();
    void setMessage(string m)
    {
        message = m; 
    }
    void setUsername(string u)
    {
        username = u;
    }
    string getMessage()
    {
        return message;
    }
    string getUsername()
    {
        return username;
    }
    int getCharlength()
    {
        return charLength;
    }
    int getSize()
    {
        return size;
    }
    MultiTweet(string u,string m) 
    {
        username = u;
        message = m;
        size = 0;
        splitTweets();
    }
    
    

virtual void display();

};
// Insert code here for the TweetStream class
class TweetStream
{
private:
  string userName;
  Tweet* tweets;
  int size;
  
public:
  TweetStream(string u)
  {
      userName = u;
      size = 0; 
      tweets = new Tweet[100];
  }
  
  void setUsername(string u)
  {
      userName = u;
  }
  
  int getSize()
  {
      return size;
  }
  
  string getUsername()
  {
      return userName;
  }
  
void addMessage(string m);
    
void display();
   
};
 
#endif
