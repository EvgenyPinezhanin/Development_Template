#include <Collection.h>

#include <gtest.h>

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_get_size_of_queue)
{
    Queue<int> q;
    EXPECT_EQ(0, q.size());
}

TEST(Queue, created_queue_is_empty)
{
    Queue<int> q;
    EXPECT_EQ(true, q.empty());
}

TEST(Queue, can_push_element_to_queue)
{
	Queue<int> q;
    q.push(5);
    q.push(10);

	EXPECT_EQ(2, q.size());
}

TEST(Queue, can_get_front_element_to_queue)
{
	Queue<int> q;
    q.push(5);
    q.push(10);

	EXPECT_EQ(5, q.front());
}

TEST(Queue, can_get_back_element_to_queue)
{
	Queue<int> q;
    q.push(5);
    q.push(10);

	EXPECT_EQ(10, q.back());
}

TEST(Queue, can_pop_element_from_not_empty_queue)
{
	Queue<int> q;
    q.push(3);

	ASSERT_NO_THROW(q.pop());
}

TEST(Queue, cant_pop_element_from_empty_queue)
{
	Queue<int> q;

	ASSERT_ANY_THROW(q.pop());
}

TEST(Stack, can_create_stack)
{
    ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_get_size_of_stack)
{
    Stack<int> s;
    EXPECT_EQ(0, s.size());
}

TEST(Stack, created_stack_is_empty)
{
    Stack<int> s;
    EXPECT_EQ(true, s.empty());
}

TEST(Stack, can_push_element_to_stack)
{
	Stack<int> s;
    s.push(10);
    s.push(45);

	EXPECT_EQ(2, s.size());
}

TEST(Stack, can_get_top_element_to_stack)
{
	Stack<int> s;
    s.push(10);
    s.push(45);

	EXPECT_EQ(45, s.top());
}

TEST(Stack, can_pop_element_from_not_empty_stack)
{
	Stack<int> s;
    s.push(3);

	ASSERT_NO_THROW(s.pop());
}

TEST(Stack, cant_pop_element_from_empty_stack)
{
	Stack<int> s;

	ASSERT_ANY_THROW(s.pop());
}