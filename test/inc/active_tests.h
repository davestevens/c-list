TestStatus integer_push_test(void);
TestStatus list_push_test(void);
TestStatus shuffle_test(void);
TestStatus flatten_test(void);
TestStatus int_array_test(void);
TestStatus shift_test(void);
TestStatus pop_test(void);
TestStatus unshift_test(void);
TestStatus shift_multiple_test(void);

test_function_t test_function_array[] = {
  &integer_push_test,
  &list_push_test,
  &shuffle_test,
  &flatten_test,
  &int_array_test,
  &shift_test,
  &pop_test,
  &unshift_test,
  &shift_multiple_test,
};
