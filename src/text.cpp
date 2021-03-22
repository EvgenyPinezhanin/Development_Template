#include<text.h>

void Text::printCurrDownNext(ostream& ostr, Link* root, Link* curr, int level) const{
    if (root == nullptr) return;
    for (int i = 0; i < level; i++) {
        ostr << " ";
    }
    if (root == curr) ostr << ">";
    ostr << root->val << endl;
    printCurrDownNext(ostr, root->down, curr, level + 1);
    printCurrDownNext(ostr, root->next, curr, level);
}

Text::Text() {
    //root = curr = nullptr;
    Link *n1 = new Link("Down");
    Link *n2 = new Link("Next");
    Link *root_node = new Link("root", n2, n1);
    root = curr = root_node;
};

void Text::addNext(string val) {
    if (root == nullptr) {
        root = curr = new Link(val);
        return;
    }
    Link *tmp = new Link(val, curr->next);
    curr->next = tmp;
}

void Text::addDown(string val) {
    if (root == nullptr) {
        root = curr = new Link(val);
        return;
    }
    Link *tmp = new Link(val, curr->down);
    curr->down = tmp;
}

void Text::delCurr() {
    if (curr == nullptr) throw "curr == nullptr";
    delDown();
    Link *tmpCurr = curr;
    if (!path.empty()) {
        if (path.top()->next == curr) {
            path.top()->next = curr->next;
            curr = path.top();
            path.pop();
        } else if (path.top()->down == curr) {
            path.top()->down = curr->next;
            if (curr->next != nullptr) curr = curr->next;
            else  {
                curr = path.top();
                path.pop();
            }
        }
    } else {
        curr = curr->next;
    }
    delete tmpCurr;
}

void Text::delDown() {
    if (curr == nullptr) throw "curr == nullptr";
    if (curr->down == nullptr) return;
    path.push(curr);
    curr = curr->down;
    while (!path.empty()) {
        if (curr == path.top()) break;
        delCurr();
    }
}

void Text::next() {
    if (curr == nullptr) throw "curr == nullptr";
    if (curr->next == nullptr) throw "curr->next == nullptr";
    path.push(curr);
    curr = curr->next;
}

void Text::down() {
    if (curr == nullptr) throw "curr == nullptr";
    if (curr->down == nullptr) throw "curr->down == nullptr";
    path.push(curr);
    curr = curr->down;
}

void Text::top() {
    if (curr == nullptr) throw "curr == nullptr";
    if (path.empty()) throw "path.empty()";
    curr = path.top();
    path.pop();
}

ostream& operator<<(ostream& ostr, const Text& text) {
    text.printCurrDownNext(ostr, text.root, text.curr, 0);
    return ostr;
}