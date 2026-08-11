void index_m2(array* a, double maior, double menor){
    IO_printf("Dentre os valores do arranjo:\n");
    indexArray(a);
    IO_printf("\nO maior valor e: %lf\nE o menor e: %lf\n", maior, menor);
}

void index_m3(array* a, double media){
    IO_printf("Dentre os valores do arranjo:\n");
    indexArray(a);
    IO_printf("\nA media sem extremos e: %lf\n", media);
}