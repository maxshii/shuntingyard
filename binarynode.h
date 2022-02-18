/*
 * Class for a node of a binary tree. Contains data, a left pointer and a right pointer. 
 * Author: Max Shi
 * Last Modified: 2/14/2022
 */

class bnode
{
 public:
  bnode(char d);
  char data;
  bnode* left;
  bnode* right;
};

bnode::bnode(char d)
{
  data = d;
  left = NULL;
  right = NULL;
}
