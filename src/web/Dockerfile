FROM gcc:latest
RUN mkdir -p /collatz
COPY . /collatz
WORKDIR /collatz
RUN g++ main.cpp -o main
CMD ["./main"]
