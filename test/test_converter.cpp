#include "converter.h"

#include <gtest.h>


TEST(test_converter, test_roman_one)
{
  roman rm("I");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(1, v.value);
}

TEST(test_converter, test_roman_four)
{
  roman rm("IV");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(4, v.value);
}

TEST(test_converter, test_roman_five)
{
  roman rm("V");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(5, v.value);
}

TEST(test_converter, test_roman_six)
{
  roman rm("VI");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(6, v.value);
}

TEST(test_converter, test_roman_nine)
{
  roman rm("IX");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(9, v.value);
}

TEST(test_converter, test_roman_ten)
{
  roman rm("X");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(10, v.value);
}

TEST(test_converter, test_roman_eleven)
{
  roman rm("XI");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(11, v.value);
}

TEST(test_converter, test_roman_forty)
{
  roman rm("XL");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(40, v.value);
}

TEST(test_converter, test_roman_fifty)
{
  roman rm("L");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(50, v.value);
}

TEST(test_converter, test_roman_sixty)
{
  roman rm("LX");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(60, v.value);
}

TEST(test_converter, test_roman_ninety)
{
  roman rm("XC");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(90, v.value);
}

TEST(test_converter, test_roman_hundred)
{
  roman rm("C");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(100, v.value);
}

TEST(test_converter, test_roman_one_hundred_and_ten)
{
  roman rm("CX");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(110, v.value);
}

TEST(test_converter, test_roman_four_hundred)
{
  roman rm("CD");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(400, v.value);
}

TEST(test_converter, test_roman_five_hundred)
{
  roman rm("D");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(500, v.value);
}

TEST(test_converter, test_roman_six_hundreds)
{
  roman rm("DC");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(600, v.value);
}

TEST(test_converter, test_roman_nine_hundred)
{
  roman rm("CM");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(900, v.value);
}

TEST(test_converter, test_roman_thousand)
{
  roman rm("M");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(1000, v.value);
}

TEST(test_converter, test_roman_one_thousand_one_hundred)
{
  roman rm("MC");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(1100, v.value);
}

TEST(test_converter, test_roman_one_thousand_six_hundred_and_forty_seven)
{
  roman rm("MDCXLVII");
  converter conv(rm);
  arabic v  = conv.getArabic();
  EXPECT_EQ(1647, v.value);
}

TEST(test_converter, test_arabic_one)
{
  arabic ar(1);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("I", v.value);
}

TEST(test_converter, test_arabic_four)
{
  arabic ar(4);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("IV", v.value);
}

TEST(test_converter, test_arabic_five)
{
  arabic ar(5);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("V", v.value);
}

TEST(test_converter, test_arabic_six)
{
  arabic ar(6);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("VI", v.value);
}

TEST(test_converter, test_arabic_nine)
{
  arabic ar(9);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("IX", v.value);
}

TEST(test_converter, test_arabic_ten)
{
  arabic ar(10);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("X", v.value);
}

TEST(test_converter, test_arabic_eleven)
{
  arabic ar(11);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("XI", v.value);
}

TEST(test_converter, test_arabic_forty)
{
  arabic ar(40);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("XL", v.value);
}

TEST(test_converter, test_arabic_fifty)
{
  arabic ar(50);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("L", v.value);
}

TEST(test_converter, test_arabic_sixty)
{
  arabic ar(60);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("LX", v.value);
}

TEST(test_converter, test_arabic_ninety)
{
  arabic ar(90);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("XC", v.value);
}

TEST(test_converter, test_arabic_hundred)
{
  arabic ar(100);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("C", v.value);
}

TEST(test_converter, test_arabic_one_hundred_and_ten)
{
  arabic ar(110);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("CX", v.value);
}

TEST(test_converter, test_arabic_four_hundred)
{
  arabic ar(400);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("CD", v.value);
}

TEST(test_converter, test_arabic_five_hundred)
{
  arabic ar(500);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("D", v.value);
}

TEST(test_converter, test_arabic_six_hundreds)
{
  arabic ar(600);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("DC", v.value);
}

TEST(test_converter, test_arabic_nine_hundred)
{
  arabic ar(900);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("CM", v.value);
}

TEST(test_converter, test_arabic_thousand)
{
  arabic ar(1000);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("M", v.value);
}

TEST(test_converter, test_arabic_one_thousand_one_hundred)
{
  arabic ar(1100);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("MC", v.value);
}

TEST(test_converter, test_arabic_one_thousand_six_hundred_and_forty_seven)
{
  arabic ar(1647);
  converter conv(ar);
  roman v  = conv.getRoman();
  EXPECT_EQ("MDCXLVII", v.value);
}

TEST(test_converter, test_setArabic)
{
  arabic ar(2547);
  converter conv;
  conv.setArabic(ar);
  roman v = conv.getRoman();
  EXPECT_EQ("MMDXLVII", v.value);
}

TEST(test_converter, test_setRoman)
{
  roman rm("MMMCDLXXXI");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(3481, v.value);
}

TEST(test_converter, throw_getArabic_if_the_Arabic_is_not_ready)
{
  converter conv;
  ASSERT_ANY_THROW(conv.getArabic());
}

TEST(test_converter, throw_getRoman_if_the_Roman_is_not_ready)
{
  converter conv;
  ASSERT_ANY_THROW(conv.getRoman());
}

TEST(test_converter, can_convert_Roman_if_lowercase_letters)
{
  roman rm("MmMCDlxXi");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(3471, v.value);
}

TEST(test_converter, throw_if_invalid_characters)
{
  roman rm("Mm5MhCDlvaxXi");
  converter conv;
  ASSERT_ANY_THROW(conv.setRoman(rm));
}

TEST(test_converter, throw_if_Arabic_greater_than_3999)
{
  arabic ar(34567);
  converter conv;
  ASSERT_ANY_THROW(conv.setArabic(ar));
}

TEST(test_converter, can_convert_Roman_if_incorrect_number_form_1_IC)
{
  roman rm("IC");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(99, v.value);
}

TEST(test_converter, can_convert_Roman_if_incorrect_number_form_1_VD)
{
  roman rm("VD");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(495, v.value);
}

TEST(test_converter, can_convert_Roman_if_incorrect_number_form_1_XD)
{
  roman rm("XD");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(490, v.value);
}

TEST(test_converter, can_convert_Roman_if_incorrect_number_form_1_LC)
{
  roman rm("LC");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(50, v.value);
}

TEST(test_converter, can_convert_Roman_if_incorrect_number_form_1_DM)
{
  roman rm("DM");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(500, v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_1_ID)
{
  roman rm("ID");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("CDXCIX", v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_1_VM)
{
  roman rm("VM");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("CMXCV", v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_1_XM)
{
  roman rm("XM");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("CMXC", v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_1_LD)
{
  roman rm("LD");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("CDL", v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_1_DM)
{
  roman rm("DM");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("D", v.value);
}

TEST(test_converter, convert_Roman_if_incorrect_number_form_2_twelve_I)
{
  roman rm("IIIIIIIIIIII");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(12, v.value);
}

TEST(test_converter, convert_Roman_if_incorrect_number_form_2_ten_V)
{
  roman rm("VVVVVVVVVV");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(50, v.value);
}

TEST(test_converter, convert_Roman_if_incorrect_number_form_2_five_X)
{
  roman rm("XXXXX");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(50, v.value);
}

TEST(test_converter, convert_Roman_if_incorrect_number_form_2_fifteen_L)
{
  roman rm("LLLLLLLLLLLLLLL");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(750, v.value);
}

TEST(test_converter, convert_Roman_if_incorrect_number_form_2_twenty_C)
{
  roman rm("CCCCCCCCCCCCCCCCCCCC");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(2000, v.value);
}

TEST(test_converter, convert_Roman_if_incorrect_number_form_2_four_D)
{
  roman rm("DDDD");
  converter conv;
  conv.setRoman(rm);
  arabic v = conv.getArabic();
  EXPECT_EQ(2000, v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_2_V)
{
  roman rm("VVVVVVVVVVVVVVV");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("LXXV", v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_2_D)
{
  roman rm("DDDD");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("MM", v.value);
}

TEST(test_converter, convert_converts_Roman_to_the_correct_form_2_I)
{
  roman rm("IIIIIIIIIIIII");
  converter conv;
  conv.setRoman(rm);
  roman v = conv.getRoman();
  EXPECT_EQ("XIII", v.value);
}