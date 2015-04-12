TestStatus integer_push_test(void);
TestStatus list_push_test(void);

test_function_t test_function_array[] = {
  &integer_push_test,
  &list_push_test,
};
