docker_build:
	docker build . --tag cern_docker

mount_volumn:
	docker run -it -v $(PWD)/files/:/app cern_docker

