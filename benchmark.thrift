namespace cpp benchmark

const i32 DEFAULT_ID = 42

struct TestStruct {
  1: i32 id,
  2: string message,
  3: list<i32> data
}

service BenchmarkService {
  void ping(),
  TestStruct echo(1: TestStruct input)
}
