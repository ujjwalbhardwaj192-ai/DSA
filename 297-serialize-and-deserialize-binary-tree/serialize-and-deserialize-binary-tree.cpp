class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";

        queue<TreeNode*> q;
        q.push(root);

        string ans = "";

                while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) {
                ans.append("null,");
                continue;
            }

            ans.append(to_string(front->val));
            ans.append(",");

            q.push(front->left);
            q.push(front->right);
        }



        return ans;
    }


    TreeNode* level(vector<string>& v) {

        if (v.empty() || v[0] == "null")
            return NULL;

        TreeNode* root = new TreeNode(stoi(v[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < v.size()) {

            TreeNode* front = q.front();
            q.pop();

            // Left child
            if (v[i] != "null") {
                front->left = new TreeNode(stoi(v[i]));
                q.push(front->left);
            }
            i++;

            // Right child
            if (i < v.size() && v[i] != "null") {
                front->right = new TreeNode(stoi(v[i]));
                q.push(front->right);
            }
            i++;
        }

        return root;
    }


    TreeNode* deserialize(string data) {

        if (data == "")
            return NULL;

        vector<string> v;
        string s;

        stringstream ss(data);

        while (getline(ss, s, ',')) {
            if (!s.empty())
                v.push_back(s);
        }

        return level(v);
    }
};