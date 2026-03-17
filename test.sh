name: Run SJF Tests

on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v3
    - name: Compile
      run: gcc sjf.c -o sjf

    - name: Run Test Cases
      run: |
        for i in 1 2
        do
          ./sjf < testcases/input$i.txt > out$i.txt
          diff out$i.txt testcases/output$i.txt
        done
