TestStatus integer_push_test(void);
TestStatus list_push_test(void);
TestStatus shuffle_test(void);
TestStatus flatten_test(void);
TestStatus int_array_test(void);

test_function_t test_function_array[] = {
  &integer_push_test,
  &list_push_test,
  &shuffle_test,
  &flatten_test,
  &int_array_test,
};
