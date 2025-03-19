//Invert Binary Tree
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        
        // Swap left and right subtrees
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        
        // Recur for left and right children
        invertTree(root.left);
        invertTree(root.right);
        
        return root;
    }
}
