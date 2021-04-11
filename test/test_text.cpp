#include<text.h>

#include<gtest.h>

TEST(Text, can_create_text)
{
    ASSERT_NO_THROW(Text t);
}

TEST(Text, can_add_new_string_to_the_current_level)
{
    Text t;
    t.addNext("key", "Next");
    valString *strVal = dynamic_cast<valString*>(t.getCurrValue());
    EXPECT_EQ("Next", strVal->getVal());
    EXPECT_EQ("key", t.getCurrKey());
}

TEST(Text, can_add_new_int_to_the_current_level)
{
    Text t;
    t.addNext("key", 152);
    valInt *intVal = dynamic_cast<valInt*>(t.getCurrValue());
    EXPECT_EQ(152, intVal->getVal());
    EXPECT_EQ("key", t.getCurrKey());
}

TEST(Text, can_add_new_bool_to_the_current_level)
{
    Text t;
    t.addNext("key", true);
    valBool *boolVal = dynamic_cast<valBool*>(t.getCurrValue());
    EXPECT_EQ(true, boolVal->getVal());
    EXPECT_EQ("key", t.getCurrKey());
}

TEST(Text, can_add_new_string_to_the_sublevel)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", "Down");
    t.down();
    valString *strVal = dynamic_cast<valString*>(t.getCurrValue());
    EXPECT_EQ("Down", strVal->getVal());
    EXPECT_EQ("key1", t.getCurrKey());
}

TEST(Text, can_add_new_int_to_the_sublevel)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", 465);
    t.down();
    valInt *intVal = dynamic_cast<valInt*>(t.getCurrValue());
    EXPECT_EQ(465, intVal->getVal());
    EXPECT_EQ("key1", t.getCurrKey());
}

TEST(Text, can_add_new_bool_to_the_sublevel)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.down();
    valBool *boolVal = dynamic_cast<valBool*>(t.getCurrValue());
    EXPECT_EQ(false, boolVal->getVal());
    EXPECT_EQ("key1", t.getCurrKey());
}

TEST(Text, can_get_current_value)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.addNext("key2", 134);
    t.next();
    valInt *intVal = dynamic_cast<valInt*>(t.getCurrValue());
    EXPECT_EQ(134, intVal->getVal());
    EXPECT_EQ("key2", t.getCurrKey());
}

TEST(Text, cant_get_current_value_if_text_is_empty)
{
    Text t;
    ASSERT_ANY_THROW(t.getCurrValue());
}

TEST(Text, can_change_current_value_the_same_type)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.addNext("key2", 134);
    t.next();
    t.changeCurrValue(23465);
    EXPECT_EQ(23465, dynamic_cast<valInt*>(t.getCurrValue())->getVal());
}

TEST(Text, can_change_current_value_the_another_type)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.addNext("key2", 134);
    t.next();
    t.changeCurrValue("string");
    EXPECT_EQ("string", dynamic_cast<valString*>(t.getCurrValue())->getVal());
}

TEST(Text, cant_change_current_value_if_text_is_empty)
{
    Text t;
    ASSERT_ANY_THROW(t.changeCurrValue("Next"));
}

TEST(Text, can_get_current_key)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.addNext("key2", 134);
    t.next();
    EXPECT_EQ("key2", t.getCurrKey());
}

TEST(Text, cant_get_current_key_if_text_is_empty)
{
    Text t;
    ASSERT_ANY_THROW(t.getCurrKey());
}

TEST(Text, can_change_current_key)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.addNext("key2", 134);
    t.next();
    t.changeCurrKey("newKey");
    EXPECT_EQ("newKey", t.getCurrKey());
}

TEST(Text, cant_change_current_key_if_text_is_empty)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.addNext("key2", 134);
    t.next();
    t.changeCurrKey("newKey");
    EXPECT_EQ("newKey", t.getCurrKey());
}

TEST(Text, can_delete_current_value)
{
    Text t;
    t.addNext("key", "Next");
    t.addNext("key1", false);
    t.next();
    t.delCurr();
    EXPECT_EQ("Next", dynamic_cast<valString*>(t.getCurrValue())->getVal());
}

TEST(Text, can_delete_sublevel_from_current_string)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.delDown();
    ASSERT_ANY_THROW(t.down());
}

TEST(Text, empty_func_return_true_if_text_is_empty)
{
    Text t;
    EXPECT_EQ(true, t.empty());
}

TEST(Text, empty_func_return_false_if_text_is_not_empty)
{
    Text t;
    EXPECT_EQ(true, t.empty());
}

TEST(Text, can_go_to_next_string)
{
    Text t;
    t.addNext("key", "Next");
    t.addNext("key1", false);
    t.next();
    EXPECT_EQ(false, dynamic_cast<valBool*>(t.getCurrValue())->getVal());
}

TEST(Text, can_climb_up_the_text)
{
    Text t;
    t.addNext("key", "Next");
    t.addNext("key1", false);
    t.next();
    t.top();
    EXPECT_EQ("Next", dynamic_cast<valString*>(t.getCurrValue())->getVal());
}

TEST(Text, can_go_down_to_sublevel)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.down();
    EXPECT_EQ(false, dynamic_cast<valBool*>(t.getCurrValue())->getVal());
}

TEST(Text, can_check_isNext_true)
{
    Text t;
    t.addNext("key", "Next");
    t.addNext("key1", false);
    EXPECT_EQ(true, t.isNext());
}

TEST(Text, can_check_isNext_false)
{
    Text t;
    t.addNext("key", "Next");
    EXPECT_EQ(false, t.isNext());
}

TEST(Text, can_check_isDown_true)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    EXPECT_EQ(true, t.isDown());
}

TEST(Text, can_check_isDown_false)
{
    Text t;
    t.addNext("key", "Next");
    EXPECT_EQ(false, t.isDown());
}

TEST(Text, can_check_isTop_true)
{
    Text t;
    t.addNext("key", "Next");
    t.addDown("key1", false);
    t.down();
    EXPECT_EQ(true, t.isTop());
}

TEST(Text, can_check_isTop_false)
{
    Text t;
    t.addNext("key", "Next");
    EXPECT_EQ(false, t.isTop());
}