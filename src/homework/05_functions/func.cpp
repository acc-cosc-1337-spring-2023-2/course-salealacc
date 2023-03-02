//add include statements
#include <string>
#include <func.h>

using std::string;

//add function code here
double get_gc_content(const string& dna) 
{
    int length = dna.length();

    if (!length) return 0;

    double gc_content = 0;
    for (auto ch: dna) {
        if (ch == 'G' || ch == 'C') {
            gc_content += 1;
        }
    }
    return gc_content/length;
}

string get_reverse_string(string dna) 
{
    string reversed = "";
    int length = dna.length();

    for (int i = 1; i <= length; i++) {
        reversed += dna[length - i];
    }

    return reversed;
}

string get_dna_complement(string dna) {
    string dna_complement = "";
    string rev_dna = get_reverse_string(dna);

    for(auto ch : rev_dna) {
        char complement;
        switch (ch) {
            case 'A':
                complement = 'T';
                break;
            case 'T':
                complement = 'A';
                break;
            case 'C':
                complement = 'G';
                break;
            case 'G':
                complement = 'C';
                break;
            default:
                complement = ch;
        }
        dna_complement += complement;
    }

    return dna_complement;
}