a.out: ft_printf.o lib_ft.o
	gcc -o a.out ft_printf.o lib_ft.o

clean:
	rm -f *.o a.out