#include <list.h>

#include <gtest.h>


TEST(test_list, can_create_list)
{
    List<int> list;
    ASSERT_NO_THROW(List<int> list);
}

TEST(test_list, can_create_copy_list)
{
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    List<int> list2(list1);
    ASSERT_NO_THROW(List<int> list2(list1));
}

TEST(test_list, can_assign_list)
{
    List<int> list1;
    List<int> list2;
    list1.push_back(1);
    list1.push_back(2);
    ASSERT_NO_THROW(list2 = list1);
}

TEST(test_list, can_get_front)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(1, list.front());
}

TEST(test_list, cant_get_front_if_list_is_empty)
{
    List<int> list;
    ASSERT_ANY_THROW(list.front());
}

TEST(test_list, can_get_back)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(2, list.back());
}

TEST(test_list, cant_get_back_if_list_is_empty)
{
    List<int> list;
    ASSERT_ANY_THROW(list.back());
}

TEST(test_list, if_list_is_empty_function_empty_true)
{
    List<int> list;
    EXPECT_EQ(true, list.empty());
}

TEST(test_list, if_list_is_not_empty_function_empty_false)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(false, list.empty());
}

TEST(test_list, can_get_size)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(2, list.getSize());
}

TEST(test_list, can_push_back)
{
    List<int> list;
    list.push_back(1);
    list.push_back(105);
    EXPECT_EQ(105, list.back());
}

TEST(test_list, can_push_front)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    EXPECT_EQ(105, list.front());
}

TEST(test_list, can_pop_back)
{
    List<int> list;
    list.push_back(1);
    list.push_back(105);
    list.pop_back();
    EXPECT_EQ(1, list.back());
}

TEST(test_list, cant_pop_back_if_list_is_empty)
{
    List<int> list;
    ASSERT_ANY_THROW(list.pop_back());
}

TEST(test_list, can_pop_front)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    list.pop_front();
    EXPECT_EQ(1, list.front());
}

TEST(test_list, cant_pop_front_if_list_is_empty)
{
    List<int> list;
    ASSERT_ANY_THROW(list.pop_front());
}

TEST(test_listIterator, can_create_iterator)
{
    ASSERT_NO_THROW(listIterator<int> iter);
}

TEST(test_listIterator, can_get_iterator_to_begin)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.begin();
    EXPECT_EQ(105, iter.getValue());
}

TEST(test_listIterator, can_get_iterator_to_end)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.end();
    iter.prev();
    EXPECT_EQ(1, iter.getValue());
}

TEST(test_listIterator, can_assign_iterator)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter1 = list.end();
    listIterator<int> iter2 = iter1;
    iter2.prev();
    EXPECT_EQ(1, iter2.getValue());
}

TEST(test_listIterator, if_next_link_NULL_hasNext_false)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.end();
    EXPECT_EQ(false, iter.hasNext());
}

TEST(test_listIterator, if_next_link_not_NULL_hasNext_true)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.begin();
    EXPECT_EQ(true, iter.hasNext());
}

TEST(test_listIterator, if_prev_link_NULL_hasPrev_false)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.begin();
    EXPECT_EQ(false, iter.hasPrev());
}

TEST(test_listIterator, if_prev_link_not_NULL_hasPrev_true)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.end();
    EXPECT_EQ(true, iter.hasPrev());
}

TEST(test_listIterator, can_get_current_element)
{
    List<int> list;
    list.push_back(1);
    list.push_back(105);
    listIterator<int> iter = list.begin();
    EXPECT_EQ(1, iter.getValue());
}

TEST(test_listIterator, can_go_next_element)
{
    List<int> list;
    list.push_back(1);
    list.push_back(105);
    listIterator<int> iter = list.begin();
    iter.next();
    EXPECT_EQ(105, iter.getValue());
}

TEST(test_listIterator, throw_if_next_element_NULL)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.end();
    ASSERT_ANY_THROW(iter.next());
}

TEST(test_listIterator, can_get_current_element_prev)
{
    List<int> list;
    list.push_back(1);
    list.push_back(105);
    listIterator<int> iter = list.end();
    iter.prev();
    EXPECT_EQ(105, iter.getValue());
}

TEST(test_listIterator, can_go_prev_element)
{
    List<int> list;
    list.push_back(1);
    list.push_back(105);
    listIterator<int> iter = list.end();
    iter.prev();
    iter.prev();
    EXPECT_EQ(1, iter.getValue());
}

TEST(test_listIterator, throw_if_prev_element_NULL)
{
    List<int> list;
    list.push_front(1);
    list.push_front(105);
    listIterator<int> iter = list.begin();
    ASSERT_ANY_THROW(iter.prev());
}

TEST(test_listIterator, can_insert_element)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    listIterator<int> iter = list.begin();
    iter.next();
    iter.next();
    iter = list.insert(iter, 10);
    EXPECT_EQ(10, iter.getValue());
}

TEST(test_listIterator, can_insert_element_first)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    listIterator<int> iter = list.begin();
    iter = list.insert(iter, 10);
    EXPECT_EQ(10, iter.getValue());
}

TEST(test_listIterator, can_insert_element_last)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    listIterator<int> iter = list.end();
    iter = list.insert(iter, 10);
    EXPECT_EQ(10, iter.getValue());
}

TEST(test_listIterator, can_erase_element)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    listIterator<int> iter = list.begin();
    iter.next();
    iter.next();
    iter = list.erase(iter);
    EXPECT_EQ(4, iter.getValue());
}

TEST(test_listIterator, can_erase_element_first)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    listIterator<int> iter = list.begin();
    iter = list.erase(iter);
    EXPECT_EQ(2, iter.getValue());
}

TEST(test_listIterator, can_erase_element_last)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    listIterator<int> iter = list.end();
    iter.prev();
    iter = list.erase(iter);
    EXPECT_EQ(3, iter.getValue());
}

TEST(test_listIterator, throw_if_erase_iterator_to_end)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    listIterator<int> iter = list.end();
    ASSERT_ANY_THROW(list.erase(iter));
}

TEST(test_listIterator, throw_if_erase_in_empty_list)
{
    List<int> list;
    listIterator<int> iter = list.begin();
    ASSERT_ANY_THROW(list.erase(iter));
}