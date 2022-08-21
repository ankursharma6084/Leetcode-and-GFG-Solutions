/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    public :
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);    
        
            else if(key > root->val) root->right = deleteNode(root->right, key);       
        
            else{
                if(!root->left && !root->right) return NULL;          
                
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    
					                                              
                TreeNode* temp = root->left;                      
                while(temp->right != NULL) temp = temp->right;     
                
                root->val = temp->val;                           
                root->left = deleteNode(root->left, temp->val);  
                
            }
        
        return root;
    }   
    
    TreeNode* solve(TreeNode* root, int key)
    {
        if(root == NULL) return NULL ;
        
        if(root->val == key)
        {
            if(root->right == NULL && root->left == NULL) return root = NULL ;
            
            else if(root->right == NULL) {
                return root = root->left ;
            }
            
            else if(root->left == NULL) return root = root->right ;
            
            else{
                TreeNode* nn = root->left ;
                TreeNode* prev = NULL ;
                while(nn->right != NULL)
                {
                    prev = nn ;
                    nn = nn->right ;
                }
                
                swap(root->val , nn->val) ;
                
                if(prev == NULL)
                    root->left = nn->left ;
                else prev->right = nn->left ;
                return root ;
            }
        }
        
        else if(root->val > key)
        {
           root->left = solve(root->left , key) ;
           return root ;
        }
        
        else root->right = solve(root->right , key) ;
        return root ;
    } 
    
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
              
//         return solve(root , key) ;
//     }
};