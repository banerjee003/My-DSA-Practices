class Solution {
public:

    set<string> parse(string& expression, int& i) {

        // Result of the current expression
        set<string> result;

        // This represents concatenation.
        // Start with empty string because:
        // "" + "a" = "a"
        set<string> current = {""};

        while (i < expression.size() && expression[i] != '}') {

            if (expression[i] == '{') {

                // Move past '{'
                i++;

                // Parse everything inside the braces
                set<string> inside = parse(expression, i);

                // Move past '}'
                i++;

                // Concatenate current × inside
                set<string> temp;

                for (string a : current) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                current = temp;

            }
            else if (expression[i] == ',') {

                // Everything accumulated so far is one
                // union component.
                for (string word : current) {
                    result.insert(word);
                }

                // Start parsing the next union component
                current = {""};

                i++;
            }
            else {

                // A normal lowercase letter
                string letter(1, expression[i]);

                set<string> temp;

                for (string a : current) {
                    temp.insert(a + letter);
                }

                current = temp;

                i++;
            }
        }

        // Add the final component
        for (string word : current) {
            result.insert(word);
        }

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};