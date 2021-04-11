#include<text.h>

enum State {q0, q1, q2, q3, q4};

bool checkNum(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

Node::Node(string _key, string _val, Node *_next, Node *_down) 
    : key(_key), val(new valString(_val)), next(_next), down(_down), isDown(false) {}

Node::Node(string _key, const char* _val, Node *_next, Node *_down) 
    : key(_key), val(new valString(string(_val))), next(_next), down(_down), isDown(false) {}

Node::Node(string _key, int _val, Node *_next, Node *_down) 
    : key(_key), val(new valInt(_val)), next(_next), down(_down), isDown(false) {}

Node::Node(string _key, bool _val, Node *_next, Node *_down)
    : key(_key), val(new valBool(_val)), next(_next), down(_down), isDown(false) {}

void Node::setValue(string _val) {
    if (val->getType() == STR) {
        (dynamic_cast<valString*>(val))->setVal(_val);
    } else {
        delete val;
        val = new valString(_val);
    }
}

void Node::setValue(const char* _val) {
    if (val->getType() == STR) {
        (dynamic_cast<valString*>(val))->setVal(_val);
    } else {
        delete val;
        val = new valString(_val);
    }
}

void Node::setValue(int _val) {
    if (val->getType() == INT) {
        (dynamic_cast<valInt*>(val))->setVal(_val);
    } else {
        delete val;
        val = new valInt(_val);
    }   
}

void Node::setValue(bool _val) {
    if (val->getType() == BOOL) {
        (dynamic_cast<valBool*>(val))->setVal(_val);
    } else {
        delete val;
        val = new valBool(_val);
    }
}

IValue* Node::getValue() const {
    return val;
}

void Text::printCDN(ostream& ostr, Node* root, Node* curr, int level) const{
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) {
        ostr << "   ";
    }
    if (root == curr) ostr << ">";
    ostr << root->key << " : ";
    if (!root->isDown) {
        if (root->getValue()->getType() == STR){
            ostr << "\"" << dynamic_cast<valString*>(root->getValue())->getVal() << "\""<< endl;
        } else if (root->getValue()->getType() == INT) {
            ostr << dynamic_cast<valInt*>(root->getValue())->getVal() << endl;
        } else if (root->getValue()->getType() == BOOL) {
            ostr << boolalpha << dynamic_cast<valBool*>(root->getValue())->getVal() << endl;
        }
    } else {
        ostr << endl;
        printCDN(ostr, root->down, curr, level + 1);
    }
    printCDN(ostr, root->next, curr, level);
}

void Text::fprintCDN(ofstream& ofstr, Node *root, int level) const{
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) {
        ofstr << '\t';
    }
    ofstr << "\"" << root->key << "\" : ";
    if (root->isDown) {
        ofstr << "{" << endl;
        fprintCDN(ofstr, root->down, level + 1);
        for (int i = 0; i < level; i++) {
            ofstr << '\t';
        }
        ofstr << "}";
    } else {
        if (root->getValue()->getType() == STR){
            ofstr << "\"" << dynamic_cast<valString*>(root->getValue())->getVal() << "\"";
        } else if (root->getValue()->getType() == INT) {
            ofstr << dynamic_cast<valInt*>(root->getValue())->getVal();
        } else if (root->getValue()->getType() == BOOL) {
            ofstr << boolalpha << dynamic_cast<valBool*>(root->getValue())->getVal();
        }
    }
    if (root->next != nullptr) {
        ofstr <<  " ," << endl;
    } else {
        ofstr << endl;
    }
    fprintCDN(ofstr, root->next, level);
}

void Text::freadCDN(ifstream& ifstr, Node *&root, bool isNextLvl) {
    if (ifstr.eof()) return;
    string str;
    State state;
    if (isNextLvl) state = q1;
        else state = q0;
    while(true) {
        ifstr >> str;
        if (state == q0) {
            if (str.length() > 1 && str[0] == '\"' && str[str.length() - 1] == '\"') {
                root = new Node(str.substr(1, str.length() - 2), string(""));
                state = q2;
            } else {
                throw logic_error("Invalid file format");
            }
        } else if (state == q1) {
            if (str.length() > 1 && str[0] == '\"' && str[str.length() - 1] == '\"') {
                root = new Node(str.substr(1, str.length() - 2), string(""));
                state = q2;
            } else if (str == "}") {
                return;
            } else {
                throw logic_error("Invalid file format");
            }
        } else if (state == q2) {
            if (str == ":") {
                state = q3;
            } else {
                throw logic_error("Invalid file format");
            }
        } else if (state == q3) {
            if (str.length() > 1 && str[0] == '\"' && str[str.length() - 1] == '\"') {
                root->setValue(str.substr(1, str.length() - 2));
                state = q4;
            } else if (str == "true") {
                root->setValue(true);
                state = q4;
            } else if (str == "false") {
                root->setValue(false);
                state = q4;
            } else if (checkNum(str)) {
                root->setValue(atoi(str.c_str()));
                state = q4;
            } else if (str == "{") {
                root->isDown = true;
                freadCDN(ifstr, root->down, true);
                state = q4;
            } else {
                throw logic_error("Invalid file format");
            }
        } else if (state == q4) {
            if (str == ",") {
                freadCDN(ifstr, root->next, false);
                return;
            } else if (str == "}") {
                return;
            } else {
                throw logic_error("Invalid file format");
            }
        }
    }
}

void Text::delBranch(Node *n) {
    if (n == nullptr) return;
    delBranch(n->next);
    delBranch(n->down);
    delete n;
}

Text::Text() {
    root = curr = nullptr;
    path = new Stack<Node*>;
};

Text::~Text() {
    while (root != nullptr) {
        delCurr();
    }
    delete path;
}

void Text::addNext(string _key, string _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->next);
    curr->next = tmp;
}

void Text::addNext(string _key, const char* _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->next);
    curr->next = tmp;
}

void Text::addNext(string _key, int _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->next);
    curr->next = tmp;
}

void Text::addNext(string _key, bool _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->next);
    curr->next = tmp;
}

void Text::addDown(string _key, string _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->down);
    curr->isDown = true;
    curr->down = tmp;
}

void Text::addDown(string _key, const char* _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->down);
    curr->isDown = true;
    curr->down = tmp;
}

void Text::addDown(string _key, int _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->down);
    curr->isDown = true;
    curr->down = tmp;
}

void Text::addDown(string _key, bool _val) {
    if (root == nullptr) {
        root = curr = new Node(_key, _val);
        return;
    }
    Node *tmp = new Node(_key, _val, curr->down);
    curr->isDown = true;
    curr->down = tmp;
}

void Text::delCurr() {
    if (curr == nullptr) return;
    delDown();
    Node *tmp = curr;
    if (!path->empty()) {
        top();
        if (curr->next == tmp) {
            curr->next = tmp->next;
        } else if (curr->down == tmp) {
            curr->down = tmp->next;
        }
    } else {
        root = curr = tmp->next;
    }
    delete tmp;
}

void Text::delDown() {
    curr->isDown = false;
    if (curr == nullptr || curr->down == nullptr) return;
    delBranch(curr->down);
    curr->down = nullptr;
}

void Text::changeCurrKey(string str) const{
    if (curr == nullptr) throw logic_error("curr == nullptr");
    curr->key = str;
}

void Text::changeCurrValue(string _val) const{
    if (curr == nullptr) throw logic_error("curr == nullptr");
    curr->setValue(_val);
}

void Text::changeCurrValue(const char* _val) const{
    if (curr == nullptr) throw logic_error("curr == nullptr");
    curr->setValue(_val);
}

void Text::changeCurrValue(int _val) const{
    if (curr == nullptr) throw logic_error("curr == nullptr");
    curr->setValue(_val);
}

void Text::changeCurrValue(bool _val) const{
    if (curr == nullptr) throw logic_error("curr == nullptr");
    curr->setValue(_val);
}

string Text::getCurrKey() const {
    if (curr == nullptr) throw logic_error("curr == nullptr");
    return curr->key;
}

IValue* Text::getCurrValue() const {
    if (curr == nullptr) throw logic_error("curr == nullptr");
    return curr->getValue();
}

bool Text::empty() const {
    return !root;
}

bool Text::isNext() const {
    if (curr == nullptr) return false;
    if (curr->next != nullptr) return true;
    return false;
}

bool Text::isDown() const {
    if (curr == nullptr) return false;
    if (curr->down != nullptr) return true;
    return false;
}

bool Text::isTop() const {
    if (curr == nullptr) return false;
    if (!path->empty()) return true;
    return false;
}

void Text::next() {
    if (!isNext()) throw logic_error("isNext == false");
    path->push(curr);
    curr = curr->next;
}

void Text::down() {
    if (!isDown()) throw logic_error("isDown == false");
    path->push(curr);
    curr = curr->down;
}

void Text::top() {
    if (!isTop()) throw logic_error("isTop == false");
    curr = path->top();
    path->pop();
}

ostream& operator<<(ostream& ostr, const Text& text) {
    text.printCDN(ostr, text.root, text.curr, 0);
    return ostr;
}

ofstream& operator<<(ofstream& ofstr, const Text& text) {
    ofstr << "{" << endl;
    text.fprintCDN(ofstr, text.root, 1);
    ofstr << "}" << endl;
    return ofstr;
}

ifstream& operator>>(ifstream& ifstr, Text& text) {
    if (!ifstr.eof()) {
        while (text.root != nullptr) {
            text.delCurr();
        }
        string str;
        ifstr >> str;
        text.freadCDN(ifstr, text.root, true);
        text.curr = text.root;
    }
    return ifstr;
}