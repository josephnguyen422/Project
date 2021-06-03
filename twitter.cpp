#include "twitter.hpp"

// Insert code here to implement MultiTweet functions
// splitTweets and display
void MultiTweet::splitTweets()//split tweet function
    {
    int begin = 0;//where split begins and ends
    int end = 273;
    while(charLength > 280){//this code run only is message is greater than 280 characters
    
    int period = message.rfind(".",end);//locates position of a period mark closest to the 280th character
    int question = message.rfind("?",end);//locates position of a question mark closest to the 280th character
    int space = message.rfind(" ",end);//locates position of a space closest to the 280th character
    int exclamation = message.rfind("!",end);//locates position of an exclamation mark closest to the 280th character
    int hyphen = message.rfind("-",end);
    int semicolon = message.rfind(";",end);
    int comma = message.rfind(",",end);

	if (period > question && period > space && period > exclamation && period > hyphen && period > semicolon && period > comma)
	{
		end = period;
	}
	if (question > period && question > space && question > exclamation && question > hyphen && question > semicolon && question > comma)
	{
		end = question;
	}
	if (space > period && space > question && space > exclamation && space > hyphen && space > semicolon && space > comma)
	{
		end = space;
	}
	if (exclamation > period && exclamation > question && exclamation > space && exclamation > hyphen && exclamation > semicolon && exclamation > comma)
	{
		end = exclamation;
    }
    if (hyphen > period && hyphen > question && hyphen > space && hyphen > exclamation && hyphen > semicolon && hyphen > comma)
	{
		end = hyphen;
    }
    if (semicolon > period && semicolon > question && semicolon > space && hyphen > exclamation && hyphen > semicolon && hyphen > comma)
	{
		end = semicolon;
    }
    if (comma > period && comma > question && comma > space && comma > exclamation && comma > semicolon && comma > hyphen)
	{
		end = comma;
    }
    
    
    
    
    subMessages[size] = message.substr(begin, end);
	charLength = charLength - 273;
	size++;//increment each time
    end = end + 273;//where the split happens is changed
    begin = end - 273;
    
    
    
}
    //used to display last part of the message
    subMessages[size] = message.substr(end - 273, charLength);
}
void MultiTweet::display()
{
    for (int x = 0; x < size; x++)
    {
        cout << "@" << username << subMessages[x] << endl;
    }
}

// Insert code here to implement TweetStrem functions
// addMessage and display
void TweetStream::addMessage(string m)
{
    if (m.length() < 280)
    {
     Tweet obj = Tweet(userName,m);
     tweets[size] = obj;
     size++;
    }
    else
    {
        MultiTweet obj = MultiTweet(userName,m);
        tweets[size] = obj;
        size++;
    }
}
void TweetStream::display()
    {
        for (int x = 0; x <= size; x++)
        tweets[x].display();     
    }
