#include <check_bst.h>
#include <create_bst.h>

#include <gtest/gtest.h>

#include <vector>
#include <initializer_list>
#include <utility>

TEST(BSTIterator, EmptyTree)
{
	BinarySearchTree<int, int> testTree;

	EXPECT_TRUE(testTree.begin() == testTree.end());
}

TEST(BSTIterator, SimpleTree)
{
	BinarySearchTree<int, int> testTree;

    testTree.insert(std::make_pair(2, 20));
    testTree.insert(std::make_pair(1, 10));
    testTree.insert(std::make_pair(3, 30));

    std::vector<int> expected = {1, 2, 3};

    BinarySearchTree<int, int>::iterator it = testTree.begin();
    for(size_t i = 0; i < expected.size(); i++){
        ASSERT_TRUE(testTree.begin() != testTree.end());
        EXPECT_EQ(it->first, expected[i]);
        EXPECT_EQ(it->second, expected[i] * 10);
        ++it;
    }
	EXPECT_TRUE(it == testTree.end());
}

TEST(BSTIterator, ComplexTree)
{
	BinarySearchTree<int, int> testTree;

    testTree.insert(std::make_pair(5, 50));
    testTree.insert(std::make_pair(1, 10));
    testTree.insert(std::make_pair(3, 30));
    testTree.insert(std::make_pair(2, 20));
    testTree.insert(std::make_pair(7, 70));
    testTree.insert(std::make_pair(6, 60));
    testTree.insert(std::make_pair(4, 40));

    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};

    BinarySearchTree<int, int>::iterator it = testTree.begin();
    for(size_t i = 0; i < expected.size(); i++){
        ASSERT_TRUE(testTree.begin() != testTree.end());
        EXPECT_EQ(it->first, expected[i]);
        EXPECT_EQ(it->second, expected[i] * 10);
        ++it;
    }
	EXPECT_TRUE(it == testTree.end());
}


TEST(BSTPredecessor, SimpleTree)
{
	BinarySearchTree<int, int> testTree;

    testTree.insert(std::make_pair(2, 20));
    testTree.insert(std::make_pair(1, 10));
    testTree.insert(std::make_pair(3, 30));

    std::vector<int> expected = {1, 2, 3};

    ASSERT_TRUE(testTree.root_ != nullptr);
    Node<int, int>* node = testTree.root_->getRight();

    for(int i = (int)expected.size() - 1; i >= 0; i--){
        ASSERT_TRUE(node != nullptr);
        EXPECT_EQ(node->getKey(), expected[i]);
        EXPECT_EQ(node->getValue(), expected[i] * 10);
        node = BinarySearchTree<int, int>::predecessor(node);
    }
	EXPECT_TRUE(node == nullptr);
}

TEST(BSTPredecessor, ComplexTree)
{
	BinarySearchTree<int, int> testTree;

    testTree.insert(std::make_pair(5, 50));
    testTree.insert(std::make_pair(1, 10));
    testTree.insert(std::make_pair(3, 30));
    testTree.insert(std::make_pair(2, 20));
    testTree.insert(std::make_pair(7, 70));
    testTree.insert(std::make_pair(6, 60));
    testTree.insert(std::make_pair(4, 40));

    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};

    ASSERT_TRUE(testTree.root_ != nullptr);
    Node<int, int>* node = testTree.root_->getRight();

    for(int i = (int)expected.size() - 1; i >= 0; i--){
        ASSERT_TRUE(node != nullptr);
        EXPECT_EQ(node->getKey(), expected[i]);
        EXPECT_EQ(node->getValue(), expected[i] * 10);
        node = BinarySearchTree<int, int>::predecessor(node);
    }
	EXPECT_TRUE(node == nullptr);
}
