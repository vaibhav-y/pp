#ifndef TREECODEC_BFS
#define TREECODEC_BFS

#include <TreeNode.h>
#include <queue>
#include <string>

namespace p0449 {
namespace bfs {
class Codec {
private:
  static constexpr size_t DATA_SZ = sizeof(int);
  static constexpr size_t FLAG_SZ = sizeof(char);
  static constexpr size_t ELEM_SZ = DATA_SZ + FLAG_SZ;

  void writeInt(char *buffer, int value) {
    memcpy(buffer, (char *)&value, DATA_SZ);
  }
  int readInt(const char *buffer) {
    int value;
    memcpy((char *)&value, buffer, DATA_SZ);
    return value;
  }
  std::ostream &flushBuffer(std::ostream &os, char *buffer) {
    os << std::string(&buffer[0], Codec::ELEM_SZ);
    memset(buffer, 0, Codec::ELEM_SZ);
    return os;
  }

public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::stringstream stream;
    std::queue<TreeNode *> nodes;
    nodes.push(root);
    char buffer[Codec::ELEM_SZ];
    memset(buffer, 0, Codec::ELEM_SZ);

    while (!nodes.empty()) {
      root = nodes.front();
      nodes.pop();
      if (root) {
        writeInt(buffer, root->val);
        nodes.push(root->left);
        nodes.push(root->right);
        // Additionally, set the most significant byte
        // to signal that this came from a non-null source
        memset(buffer + Codec::DATA_SZ, 1, Codec::FLAG_SZ);
      }
      flushBuffer(stream, buffer);
    }
    return stream.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(std::string data) {
    if (data.size() == 0) {
      return nullptr;
    }

    const char *stream = data.c_str();
    TreeNode *root = new TreeNode(readInt(stream));

    std::queue<TreeNode *> nodes;
    nodes.push(root);

    char flag = 0;
    size_t offset = Codec::ELEM_SZ;

    while (offset < data.size()) {
      TreeNode *node = nodes.front();
      nodes.pop();

      // Read the left child
      memcpy(&flag, stream + offset + Codec::DATA_SZ, Codec::FLAG_SZ);
      if (flag) {
        node->left = new TreeNode(readInt(stream + offset));
        nodes.push(node->left);
      }
      offset += Codec::ELEM_SZ;

      // Read right child
      memcpy(&flag, stream + offset + Codec::DATA_SZ, Codec::FLAG_SZ);
      if (flag) {
        node->right = new TreeNode(readInt(stream + offset));
        nodes.push(node->right);
      }
      offset += Codec::ELEM_SZ;
    }
    return root;
  }
};
} // namespace bfs
} // namespace p0449

#endif
