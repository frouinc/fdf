#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

%.o : %.c
	@gcc -g -o $@ -c $< $(CFLAGS)
	@echo "\033[K\033[34mMlx :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

%.o : %.m
	@gcc -g -o $@ -c $< $(CFLAGS)
	@echo "\033[K\033[34mMlx :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NOM):	$(OBJ)
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\033[K\033[32m=============MLX================\033[0m"
	@echo "\033[34mCompiling\033[0m" [ $(NOM) ] "\033[K\033[32mSuccessful\033[00m"
	@echo "\033[32m================================\033[00m"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "\033[K\033[31m=============MLX=============\033[0m"
	@echo "\033[31mRemoving\033[00m" [ $(NOM) ] "\033[32mComplete\033[00m"
	@echo "\033[K\033[31m=============================\033[0m"

re: clean all
