#include <stdio.h>
#include "ft_printf.h"

void test_mandatory(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST MANDATORY ===\n\n");
    
    // Test %c
    printf("--- Test %%c ---\n");
    ret1 = printf("printf:    [%c]\n", 'A');
    ret2 = ft_printf("ft_printf: [%c]\n", 'A');
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    // Test %s
    printf("--- Test %%s ---\n");
    ret1 = printf("printf:    [%s]\n", "Hello World");
    ret2 = ft_printf("ft_printf: [%s]\n", "Hello World");
    printf("Return: %d vs %d\n", ret1, ret2);
    // ret1 = printf("printf:    [%s]\n", (char *)NULL);
    ret2 = ft_printf("ft_printf: [%s]\n", (char *)NULL);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    // Test %p
    printf("--- Test %%p ---\n");
    void *ptr = &ret1;
    ret1 = printf("printf:    [%p]\n", ptr);
    ret2 = ft_printf("ft_printf: [%p]\n", ptr);
    printf("Return: %d vs %d\n", ret1, ret2);
    ret1 = printf("printf:    [%p]\n", NULL);
    ret2 = ft_printf("ft_printf: [%p]\n", NULL);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    // Test %d e %i
    printf("--- Test %%d e %%i ---\n");
    ret1 = printf("printf:    [%d] [%i]\n", 42, -42);
    ret2 = ft_printf("ft_printf: [%d] [%i]\n", 42, -42);
    printf("Return: %d vs %d\n", ret1, ret2);
    // ret1 = printf("printf:    [%d] [%i]\n", 0, -2147483648);
    ret2 = ft_printf("ft_printf: [%d] [%i]\n", 0, -2147483648);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    // Test %u
    printf("--- Test %%u ---\n");
    ret1 = printf("printf:    [%u]\n", 42);
    ret2 = ft_printf("ft_printf: [%u]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    ret1 = printf("printf:    [%u]\n", -1);
    ret2 = ft_printf("ft_printf: [%u]\n", -1);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    // Test %x e %X
    printf("--- Test %%x e %%X ---\n");
    ret1 = printf("printf:    [%x] [%X]\n", 255, 255);
    ret2 = ft_printf("ft_printf: [%x] [%X]\n", 255, 255);
    printf("Return: %d vs %d\n", ret1, ret2);
    ret1 = printf("printf:    [%x] [%X]\n", 0, -1);
    ret2 = ft_printf("ft_printf: [%x] [%X]\n", 0, -1);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    // Test %%
    printf("--- Test %%%% ---\n");
    ret1 = printf("printf:    [%%]\n");
    ret2 = ft_printf("ft_printf: [%%]\n");
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_bonus_width(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST BONUS - WIDTH ===\n\n");
    
    printf("--- Width con %%d ---\n");
    ret1 = printf("printf:    [%5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%5d]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%10d]\n", -42);
    ret2 = ft_printf("ft_printf: [%10d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Width con %%s ---\n");
    ret1 = printf("printf:    [%10s]\n", "test");
    ret2 = ft_printf("ft_printf: [%10s]\n", "test");
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%3s]\n", "testing");
    ret2 = ft_printf("ft_printf: [%3s]\n", "testing");
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_bonus_flags(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST BONUS - FLAGS ===\n\n");
    
    printf("--- Flag '-' (left justify) ---\n");
    ret1 = printf("printf:    [%-10d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-10d]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-10s]\n", "test");
    ret2 = ft_printf("ft_printf: [%-10s]\n", "test");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Flag '0' (zero padding) ---\n");
    ret1 = printf("printf:    [%010d]\n", 42);
    ret2 = ft_printf("ft_printf: [%010d]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%010d]\n", -42);
    ret2 = ft_printf("ft_printf: [%010d]\n", -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Flag '.' (precision) ---\n");
    ret1 = printf("printf:    [%.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%.5d]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%.3s]\n", "testing");
    ret2 = ft_printf("ft_printf: [%.3s]\n", "testing");
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Flag '#' (alternate form) ---\n");
    ret1 = printf("printf:    [%#x] [%#X]\n", 42, 42);
    ret2 = ft_printf("ft_printf: [%#x] [%#X]\n", 42, 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%#x]\n", 0);
    ret2 = ft_printf("ft_printf: [%#x]\n", 0);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Flag ' ' (space) ---\n");
    ret1 = printf("printf:    [% d] [% d]\n", 42, -42);
    ret2 = ft_printf("ft_printf: [% d] [% d]\n", 42, -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
    
    printf("--- Flag '+' (sign) ---\n");
    ret1 = printf("printf:    [%+d] [%+d]\n", 42, -42);
    ret2 = ft_printf("ft_printf: [%+d] [%+d]\n", 42, -42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

void test_bonus_combinations(void)
{
    int ret1, ret2;
    
    printf("\n=== TEST BONUS - COMBINAZIONI ===\n\n");
    
    printf("--- Combinazioni multiple ---\n");
    ret1 = printf("printf:    [%+10d]\n", 42);
    ret2 = ft_printf("ft_printf: [%+10d]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-+10d]\n", 42);
    ret2 = ft_printf("ft_printf: [%-+10d]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    // ret1 = printf("printf:    [%010.5d]\n", 42);
    ret2 = ft_printf("ft_printf: [%010.5d]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%#10x]\n", 42);
    ret2 = ft_printf("ft_printf: [%#10x]\n", 42);
    printf("Return: %d vs %d\n", ret1, ret2);
    
    ret1 = printf("printf:    [%-#10x]\n", 42);
    ret2 = ft_printf("ft_printf: [%-#10x]\n", 42);
    printf("Return: %d vs %d\n\n", ret1, ret2);
}

int main(void)
{
    printf("========================================\n");
    printf("   FT_PRINTF TEST SUITE CON BONUS\n");
    printf("========================================\n");
    
    test_mandatory();
    test_bonus_width();
    test_bonus_flags();
    test_bonus_combinations();
    
    printf("\n========================================\n");
    printf("   FINE TEST\n");
    printf("========================================\n");
    
    return 0;
}