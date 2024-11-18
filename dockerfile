FROM rootproject/root
WORKDIR /app

RUN apt-get update && apt-get install -y bash

ENTRYPOINT ["/bin/bash"]
