#include<text.h>

#include<gtest.h>

TEST(Text, can_create_text)
{
    ASSERT_NO_THROW(Text t);
}

TEST(Text, can_add_new_string_to_the_current_level)
{
    Text t;
    t.addNext("Next");
    EXPECT_EQ("Next", t.getCurrString());
}

TEST(Text, can_add_new_string_to_the_sublevel)
{
    Text t;
    t.addNext("Next");
    t.addDown("Down");
    t.down();
    EXPECT_EQ("Down", t.getCurrString());
}

TEST(Text, can_get_current_string)
{
    Text t;
    t.addNext("Next");
    t.addDown("Down");
    t.addNext("Next1");
    t.next();
    EXPECT_EQ("Next1", t.getCurrString());
}

TEST(Text, cant_get_current_string_if_text_is_empty)
{
    Text t;
    ASSERT_ANY_THROW(t.getCurrString());
}

TEST(Text, can_change_current_string)
{
    Text t;
    t.addNext("Next");
    t.addDown("Down");
    t.addNext("Next1");
    t.next();
    t.changeCurrString("Next2");
    EXPECT_EQ("Next2", t.getCurrString());
}

TEST(Text, cant_change_current_string_if_text_is_empty)
{
    Text t;
    ASSERT_ANY_THROW(t.changeCurrString("Next"));
}

TEST(Text, can_delete_current_string)
{
    Text t;
    t.addNext("Next");
    t.addNext("Next1");
    t.next();
    t.delCurr();
    EXPECT_EQ("Next", t.getCurrString());
}

TEST(Text, can_delete_sublevel_from_current_string)
{
    Text t;
    t.addNext("Next");
    t.addDown("Down");
    t.delDown();
    ASSERT_ANY_THROW(t.down());
}

TEST(Text, can_go_to_next_string)
{
    Text t;
    t.addNext("Next");
    t.addNext("Next1");
    t.next();
    EXPECT_EQ("Next1", t.getCurrString());
}

TEST(Text, can_climb_up_the_text)
{
    Text t;
    t.addNext("Next");
    t.addNext("Next1");
    t.next();
    t.top();
    EXPECT_EQ("Next", t.getCurrString());
}

TEST(Text, can_go_down_to_sublevel)
{
    Text t;
    t.addNext("Next");
    t.addDown("Down");
    t.down();
    EXPECT_EQ("Down", t.getCurrString());
}

TEST(Text, can_check_isNext_true)
{
    Text t;
    t.addNext("Next");
    t.addNext("Next1");
    EXPECT_EQ(true, t.isNext());
}

TEST(Text, can_check_isNext_false)
{
    Text t;
    t.addNext("Next");
    EXPECT_EQ(false, t.isNext());
}

TEST(Text, can_check_isDown_true)
{
    Text t;
    t.addNext("Next");
    t.addDown("Down");
    EXPECT_EQ(true, t.isDown());
}

TEST(Text, can_check_isDown_false)
{
    Text t;
    t.addNext("Next");
    EXPECT_EQ(false, t.isDown());
}

TEST(Text, can_check_isTop_true)
{
    Text t;
    t.addNext("Next");
    t.addDown("Down");
    t.down();
    EXPECT_EQ(true, t.isTop());
}

TEST(Text, can_check_isTop_false)
{
    Text t;
    t.addNext("Next");
    EXPECT_EQ(false, t.isTop());
}