TestStatus integer_push_test(void);
TestStatus list_push_test(void);
TestStatus shuffle_test(void);
TestStatus flatten_1_test(void);
TestStatus flatten_2_test(void);
TestStatus flatten_3_test(void);
TestStatus int_array_test(void);
TestStatus shift_test(void);
TestStatus pop_test(void);
TestStatus unshift_test(void);
TestStatus shift_many_test(void);
TestStatus shuffle_flatten_test(void);

test_function_t test_function_array[] = {
  &integer_push_test,
  &list_push_test,
  &shuffle_test,
  &flatten_1_test,
  &flatten_2_test,
  &flatten_3_test,
  &int_array_test,
  &shift_test,
  &pop_test,
  &unshift_test,
  &shift_many_test,
  &shuffle_flatten_test,
};
