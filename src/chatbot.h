#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot &) = delete;
    ChatBot &operator=(const ChatBot &) = delete;
      
    ChatBot(ChatBot &&source) // 4 : move constructor
    {
        std::cout << "MOVING ChatBot instance " << &source << " to instance " << this << std::endl;
        _image = source._image;
        source._image = nullptr;
        _currentNode = source._currentNode;
        _rootNode = source._rootNode;
        _chatLogic = source._chatLogic;
    }
    
    ChatBot &operator=(ChatBot &&source) // 5 : move assignment operator
    {
        std::cout << "MOVING (assign) ChatBot instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;

        delete _image;

        _image = source._image;
        _currentNode = source._currentNode;
        _rootNode = source._rootNode;
        _chatLogic = source._chatLogic;

        source._image = nullptr;

        return *this;
    }
    
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */