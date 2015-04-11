TestStatus passing(void);
TestStatus failing(void);
TestStatus pending(void);

test_function_t test_function_array[] = {
  &passing,
  &failing,
  &pending
};
