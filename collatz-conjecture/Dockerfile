FROM gradle:latest
COPY . /app
WORKDIR /app
RUN gradle build
CMD ["./app/build/exe/main/debug/app"]