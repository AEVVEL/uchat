CL_NAME = uchat
SV_NAME = uchat_server
CL_DIR = client
SV_DIR = server
all: install
install: dep
dep:
	@make -sC $(CL_DIR)
	@cp ./client/uchat .
	@make -sC $(SV_DIR)
	@cp ./server/uchat_server .
clean:
	@make clean -C $(CL_DIR)
	@make clean -C $(SV_DIR)
uninstall: clean
	@make uninstall -C $(CL_DIR)
	@make uninstall -C $(SV_DIR)
	@rm -rf $(CL_NAME)
	@rm -rf $(SV_NAME)
	
reinstall: uninstall install
db-up: install ./uchat_server  migration-up
db-ds: install ./uchat_server migration-ds