#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

void test_flag_minus(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST FLAG '-' (Left Justify) ===\n\n");
    
    printf("--- %%d con width e - ---\n");
    ret1 = printf("printf:    [%-5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-10d]\n", -42);
    ret2 = ft_printf("ft_printf: [%-10d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-15d]\n", 0);
    ret2 = ft_printf("ft_printf: [%-15d]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%s con width e - ---\n");
    ret1 = printf("printf:    [%-10s]\n", "test");
    ret2 = ft_printf("ft_printf: [%-10s]\n", "test");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-20s]\n", "Hello World");
    ret2 = ft_printf("ft_printf: [%-20s]\n", "Hello World");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-5s]\n", "testing");
    ret2 = ft_printf("ft_printf: [%-5s]\n", "testing");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%x con width e - ---\n");
    ret1 = printf("printf:    [%-10x]\n", 255);
    ret2 = ft_printf("ft_printf: [%-10x]\n", 255);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%c con width e - ---\n");
    ret1 = printf("printf:    [%-5c]\n", 'A');
    ret2 = ft_printf("ft_printf: [%-5c]\n", 'A');
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_flag_zero(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST FLAG '0' (Zero Padding) ===\n\n");
    
    printf("--- %%d con zero padding ---\n");
    ret1 = printf("printf:    [%05d]\n", 42);
    ret2 = ft_printf("ft_printf: [%05d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%010d]\n", -42);
    ret2 = ft_printf("ft_printf: [%010d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%08d]\n", 0);
    ret2 = ft_printf("ft_printf: [%08d]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%015d]\n", INT_MAX);
    ret2 = ft_printf("ft_printf: [%015d]\n", INT_MAX);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%015d]\n", INT_MIN);
    ret2 = ft_printf("ft_printf: [%015d]\n", INT_MIN);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%x con zero padding ---\n");
    ret1 = printf("printf:    [%08x]\n", 255);
    ret2 = ft_printf("ft_printf: [%08x]\n", 255);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%010X]\n", 0xDEADBEEF);
    ret2 = ft_printf("ft_printf: [%010X]\n", 0xDEADBEEF);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%u con zero padding ---\n");
    ret1 = printf("printf:    [%012u]\n", 12345);
    ret2 = ft_printf("ft_printf: [%012u]\n", 12345);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_flag_dot(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST FLAG '.' (Precision) ===\n\n");
    
    printf("--- %%d con precision ---\n");
    ret1 = printf("printf:    [%.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%.5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%.10d]\n", -42);
    ret2 = ft_printf("ft_printf: [%.10d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%.0d]\n", 0);
    ret2 = ft_printf("ft_printf: [%.0d]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%.3d]\n", 12345);
    ret2 = ft_printf("ft_printf: [%.3d]\n", 12345);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%s con precision ---\n");
    ret1 = printf("printf:    [%.3s]\n", "testing");
    ret2 = ft_printf("ft_printf: [%.3s]\n", "testing");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%.10s]\n", "test");
    ret2 = ft_printf("ft_printf: [%.10s]\n", "test");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%.0s]\n", "test");
    ret2 = ft_printf("ft_printf: [%.0s]\n", "test");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%x con precision ---\n");
    ret1 = printf("printf:    [%.8x]\n", 255);
    ret2 = ft_printf("ft_printf: [%.8x]\n", 255);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%.5X]\n", 42);
    ret2 = ft_printf("ft_printf: [%.5X]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_flag_hash(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST FLAG '#' (Alternate Form) ===\n\n");
    
    printf("--- %%x con # ---\n");
    ret1 = printf("printf:    [%#x]\n", 42);
    ret2 = ft_printf("ft_printf: [%#x]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%#x]\n", 0);
    ret2 = ft_printf("ft_printf: [%#x]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%#x]\n", 255);
    ret2 = ft_printf("ft_printf: [%#x]\n", 255);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%X con # ---\n");
    ret1 = printf("printf:    [%#X]\n", 42);
    ret2 = ft_printf("ft_printf: [%#X]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%#X]\n", 0);
    ret2 = ft_printf("ft_printf: [%#X]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%#X]\n", 0xDEADBEEF);
    ret2 = ft_printf("ft_printf: [%#X]\n", 0xDEADBEEF);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Multipli con # ---\n");
    ret1 = printf("printf:    [%#x] [%#X]\n", 42, 42);
    ret2 = ft_printf("ft_printf: [%#x] [%#X]\n", 42, 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_flag_space(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST FLAG ' ' (Space) ===\n\n");
    
    printf("--- %%d con space ---\n");
    ret1 = printf("printf:    [% d]\n", 42);
    ret2 = ft_printf("ft_printf: [% d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [% d]\n", -42);
    ret2 = ft_printf("ft_printf: [% d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [% d]\n", 0);
    ret2 = ft_printf("ft_printf: [% d]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%i con space ---\n");
    ret1 = printf("printf:    [% i]\n", 123);
    ret2 = ft_printf("ft_printf: [% i]\n", 123);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [% i]\n", -123);
    ret2 = ft_printf("ft_printf: [% i]\n", -123);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Multipli con space ---\n");
    ret1 = printf("printf:    [% d] [% d] [% d]\n", 42, -42, 0);
    ret2 = ft_printf("ft_printf: [% d] [% d] [% d]\n", 42, -42, 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_flag_plus(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST FLAG '+' (Sign) ===\n\n");
    
    printf("--- %%d con + ---\n");
    ret1 = printf("printf:    [%+d]\n", 42);
    ret2 = ft_printf("ft_printf: [%+d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%+d]\n", -42);
    ret2 = ft_printf("ft_printf: [%+d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%+d]\n", 0);
    ret2 = ft_printf("ft_printf: [%+d]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%+d]\n", INT_MAX);
    ret2 = ft_printf("ft_printf: [%+d]\n", INT_MAX);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%+d]\n", INT_MIN);
    ret2 = ft_printf("ft_printf: [%+d]\n", INT_MIN);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- %%i con + ---\n");
    ret1 = printf("printf:    [%+i]\n", 123);
    ret2 = ft_printf("ft_printf: [%+i]\n", 123);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Multipli con + ---\n");
    ret1 = printf("printf:    [%+d] [%+d] [%+d]\n", 42, -42, 0);
    ret2 = ft_printf("ft_printf: [%+d] [%+d] [%+d]\n", 42, -42, 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_width_combinations(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST WIDTH + FLAGS ===\n\n");
    
    printf("--- Width semplice ---\n");
    ret1 = printf("printf:    [%5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%10s]\n", "test");
    ret2 = ft_printf("ft_printf: [%10s]\n", "test");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%8x]\n", 255);
    ret2 = ft_printf("ft_printf: [%8x]\n", 255);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Width + zero ---\n");
    ret1 = printf("printf:    [%05d]\n", 42);
    ret2 = ft_printf("ft_printf: [%05d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%010d]\n", -42);
    ret2 = ft_printf("ft_printf: [%010d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Width + minus ---\n");
    ret1 = printf("printf:    [%-10d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-10d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-15s]\n", "test");
    ret2 = ft_printf("ft_printf: [%-15s]\n", "test");
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_precision_combinations(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST PRECISION + FLAGS ===\n\n");
    
    printf("--- Width + precision ---\n");
    ret1 = printf("printf:    [%10.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%10.5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    ret1 = printf("printf:    [%15.10s]\n", "testing");
    ret2 = ft_printf("ft_printf: [%15.10s]\n", "testing");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Zero + precision ---\n");
    ret1 = printf("printf:    [%010.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%010.5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Minus + precision ---\n");
    ret1 = printf("printf:    [%-10.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-10.5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_complex_combinations(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST COMBINAZIONI COMPLESSE ===\n\n");
    
    printf("--- Plus + width ---\n");
    ret1 = printf("printf:    [%+10d]\n", 42);
    ret2 = ft_printf("ft_printf: [%+10d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Plus + zero + width ---\n");
    ret1 = printf("printf:    [%+010d]\n", 42);
    ret2 = ft_printf("ft_printf: [%+010d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Plus + minus + width ---\n");
    ret1 = printf("printf:    [%-+10d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-+10d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Space + width ---\n");
    ret1 = printf("printf:    [% 10d]\n", 42);
    ret2 = ft_printf("ft_printf: [% 10d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Hash + width + hex ---\n");
    ret1 = printf("printf:    [%#10x]\n", 42);
    ret2 = ft_printf("ft_printf: [%#10x]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Hash + minus + width + hex ---\n");
    ret1 = printf("printf:    [%-#10x]\n", 42);
    ret2 = ft_printf("ft_printf: [%-#10x]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Hash + zero + width + hex ---\n");
    ret1 = printf("printf:    [%#010x]\n", 42);
    ret2 = ft_printf("ft_printf: [%#010x]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Width + precision + plus ---\n");
    ret1 = printf("printf:    [%+10.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%+10.5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Width + precision + space ---\n");
    ret1 = printf("printf:    [% 10.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [% 10.5d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Hash + precision + hex ---\n");
    ret1 = printf("printf:    [%#.8x]\n", 42);
    ret2 = ft_printf("ft_printf: [%#.8x]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Tutto insieme: minus + plus + width + precision ---\n");
    ret1 = printf("printf:    [%-+15.10d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-+15.10d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_edge_cases_bonus(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST CASI LIMITE BONUS ===\n\n");
    
    printf("--- Width minore del numero ---\n");
    ret1 = printf("printf:    [%3d]\n", 12345);
    ret2 = ft_printf("ft_printf: [%3d]\n", 12345);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Precision zero con zero ---\n");
    ret1 = printf("printf:    [%.0d]\n", 0);
    ret2 = ft_printf("ft_printf: [%.0d]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Plus e space insieme (plus vince) ---\n");
    ret1 = printf("printf:    [%+ d]\n", 42);
    ret2 = ft_printf("ft_printf: [%+ d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Zero e minus insieme (minus vince) ---\n");
    ret1 = printf("printf:    [%-05d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-05d]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Hash con zero ---\n");
    ret1 = printf("printf:    [%#x]\n", 0);
    ret2 = ft_printf("ft_printf: [%#x]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Precision con stringa NULL ---\n");
    ret1 = printf("printf:    [%.0s]\n", (char *)NULL);
    ret2 = ft_printf("ft_printf: [%.0s]\n", (char *)NULL);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Combinazione estrema ---\n");
    ret1 = printf("printf:    [%+#-020.15x]\n", 42);
    ret2 = ft_printf("ft_printf: [%+#-020.15x]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

int main(void)
{
    printf("========================================\n");
    printf("   FT_PRINTF BONUS FLAGS TEST\n");
    printf("========================================\n");
    
    test_flag_minus();
    test_flag_zero();
    test_flag_dot();
    test_flag_hash();
    test_flag_space();
    test_flag_plus();
    test_width_combinations();
    test_precision_combinations();
    test_complex_combinations();
    test_edge_cases_bonus();
    
    printf("\n========================================\n");
    printf("   FINE TEST BONUS\n");
    printf("========================================\n");
    
    return 0;
}