# ubuntu:18.04 is the default image, the user can change it
FROM       ubuntu:18.04
# Update apt-get
RUN        apt-get update -y
# Install build toolchain, valgrind and let the user specify any additional dependencies
RUN        apt-get install -y build-essential valgrind <dependencies>
# Add all the project files to a temporary directory inside the container
ADD        . /valgrind_project_tmp/
# Switch to working from that directory, it's as if we did a permanent `cd` into it
WORKDIR    /valgrind_project_tmp/
# Run any pre-build commands, or run `:` by default, which is a no-op
#RUN        <pre-build commands>
# Run build command(s), which is set to `make all` by default
RUN        make all
# Run Valgrind on the binary as specified by the user, and optionally run other commands after that (default: `:` again)
ENTRYPOINT valgrind --leak-check=full --error-exitcode=1 ./qucksorter