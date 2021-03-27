#include<text.h>

void Text::printCDN(ostream& ostr, Node* root, Node* curr, int level) const{
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) {
        ostr << " ";
    }
    if (root == curr) ostr << ">";
    ostr << root->val << endl;
    printCDN(ostr, root->down, curr, level + 1);
    printCDN(ostr, root->next, curr, level);
}

void Text::fprintCDN(ofstream& ofstr, Node* root, int level) const{
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) {
        ofstr << '\t';
    }
    ofstr << root->val << endl;
    fprintCDN(ofstr, root->down, level + 1);
    fprintCDN(ofstr, root->next, level);
}

void Text::freadCDN(ifstream& ifstr, Stack<Node*> *stack, Node* root, int level) {
    if (ifstr.eof()) return;
    string str;
    getline(ifstr, str);
    if (str == "" && ifstr.eof()) return;
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '\t') break;
        count++;
    }
    if (count > level) {
        root->down = new Node;
        root->down->val = str.substr(count, str.length()-count);
        stack->push(root);
        freadCDN(ifstr, stack, root->down, count); 
    } else if (count == level) {
        root->next = new Node;
        root->next->val = str.substr(count, str.length()-count);
        freadCDN(ifstr, stack, root->next, count); 
    } else {
        for (int i = 0; i < level - count - 1; i++) {
            if (!stack->empty()) stack->pop();
                else break;
        }
        if (!stack->empty()) {
            Node * tmp = stack->top();
            tmp->next = new Node;
            tmp->next->val = str.substr(count, str.length()-count);
            stack->pop();
            freadCDN(ifstr, stack, tmp->next, count); 
        } else {
            throw logic_error("file invalid");
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

void Text::addNext(string val) {
    if (root == nullptr) {
        root = curr = new Node(val);
        return;
    }
    Node *tmp = new Node(val, curr->next);
    curr->next = tmp;
}

void Text::addDown(string val) {
    if (root == nullptr) {
        root = curr = new Node(val);
        return;
    }
    Node *tmp = new Node(val, curr->down);
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
    if (curr == nullptr || curr->down == nullptr) return;
    delBranch(curr->down);
    curr->down = nullptr;
}

void Text::changeCurrString(string str) {
    if (curr == nullptr) throw logic_error("curr == nullptr");
    curr->val = str;
}

string Text::getCurrString() const {
    if (curr == nullptr) throw logic_error("curr == nullptr");
    return curr->val;
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
    //cout << path->size() << "  " << path->empty() << endl;
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
    text.fprintCDN(ofstr, text.root, 0);
    return ofstr;
}

ifstream& operator>>(ifstream& ifstr, Text& text) {
    if (!ifstr.eof()) {
        Stack<Node *> *stack = new Stack<Node *>;
        while (text.root != nullptr) {
            text.delCurr();
        }
        text.root = new Node;
        getline(ifstr, text.root->val);
        text.freadCDN(ifstr, stack, text.root, 0);
        text.curr = text.root;
        delete stack;
    }
    return ifstr;
}