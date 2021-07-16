class Pair{
public:
    int max_sum;
    int max_path;
    Pair(){
    }
};
class Solution {
public:

    //O(N) time complexity
    Pair max_path_sum(TreeNode*root){
        Pair res;
        if(!root){
            return res;
        }
        Pair left=max_path_sum(root->left);
        Pair right=max_path_sum(root->right);
        //if the node is the leaf node
        if(!root->left and !root->right){
            res.max_sum=root->val;
            res.max_path=root->val;
            return res;
        }
        //if left and right child of that node exists
        if(root->left and root->right){
            res.max_sum=max(max(left.max_sum,right.max_sum),max(left.max_path+root->val,max(right.max_path+root->val,max(left.max_path+right.max_path+root->val,root->val))));
            res.max_path=max(max(left.max_path+root->val,right.max_path+root->val),root->val);
            return res;
        }
        //if only left child exists
        if(root->left){
            res.max_sum=max(max(left.max_sum,root->val+left.max_path),root->val);
            res.max_path=max(left.max_path+root->val,root->val);
            return res;
        }
        //if only right child exists
        res.max_sum=max(max(right.max_sum,root->val+right.max_path),root->val);
        res.max_path=max(right.max_path+root->val,root->val);
        return res;
    }
    int maxPathSum(TreeNode* root){
        return max_path_sum(root).max_sum;
    }
};