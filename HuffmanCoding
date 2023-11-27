#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

class HuffmanNode {
public:
    char symbol;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char symbol, int frequency) : symbol(symbol), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
class CompareNodes {
public:
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

HuffmanNode* buildHuffmanTree(int frequencies[]) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    // Create a node for each symbol and add it to the priority queue
    for (int i = 0; i < 256; ++i) { 
        if (frequencies[i] > 0) {
            HuffmanNode* node = new HuffmanNode(static_cast<char>(i), frequencies[i]);
            pq.push(node);
        }
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* combined = new HuffmanNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        pq.push(combined);
    }
    return pq.top(); // The root of the Huffman tree
}

//Generate Huffman codes
void generateHuffmanCodes(HuffmanNode* root, string code, string huffmanCodes[]) {
    if (root != nullptr) {
        if (root->symbol != '\0') {
            huffmanCodes[static_cast<int>(root->symbol)] = code;
        }

        generateHuffmanCodes(root->left, code + "0", huffmanCodes);
        generateHuffmanCodes(root->right, code + "1", huffmanCodes);
    }
}

int main() {
    int symbolFrequencies[256] = { 0 };

    /*
    string text = "";
    cout << "Input text";
    cin >> text;
    map<char, int> charCount;
    for (char ch : text) {
        charCount[ch]++;
    }

    for (const auto& pair : charCount) {
        symbolFrequencies[pair.first] = pair.second; // first - key, second - value
    }
    */

    symbolFrequencies['A'] = 5;
    symbolFrequencies['B'] = 9;
    symbolFrequencies['C'] = 12;
    symbolFrequencies['D'] = 13;
    symbolFrequencies['E'] = 16;
    symbolFrequencies['F'] = 45;

    // Build the Huffman tree
    HuffmanNode* huffmanTreeRoot = buildHuffmanTree(symbolFrequencies);

    // Generate Huffman codes
    string huffmanCodes[256];
    generateHuffmanCodes(huffmanTreeRoot, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (int i = 0; i < 256; ++i) {
        if (!huffmanCodes[i].empty()) {
            cout << static_cast<char>(i) << ": " << huffmanCodes[i] << endl;
        }
    }
    return 0;
}
