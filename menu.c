#include <stdio.h>
#include <stdlib.h>
#include "invtools.h"
#include "product.h"
#include "productcategory.h"
#include "menu.h"

int printProduct(int index)
{
  printf("\n");
  printf("\tID: %d\n", stock[index].id);
  printf("\tNombre: %s", stock[index].name);
  printf("\tUnidad de medida: %s", stock[index].measureUnit);
  printf("\tCategoria: %s", stock[index].category);
  printf("\tFecha de registro: %s", stock[index].creationDate);
  printf("\t\nPrecio de adquisicion: %.2f\n", stock[index].basePrice);
  printf("\tPrecio de ventas: %.2f\n", stock[index].sellingPrice);
  printf("\tPorcentaje superior: %f\n", stock[index].upperPercentage);
  printf("\tPorcentaje inferior: %f\n\n", stock[index].lowerPercentage);
}


int printProductCategory(int index)
{
  printf("\n");
  printf("\tID: %d\n", productCategories[index].id);
  printf("\tNombre: %s", productCategories[index].name);
}


void m_deleteProductCategory()
{

  int productCategory_id;
  char decision;

  printf("==================================================\n");
  printf("ELIMINACION DE CATEGORIAS DE PRODUCTOS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el ID de la categoria de producto a eliminar: ");
  scanf("%d", &productCategory_id);

  int search = searchProdCategory(productCategory_id);
  if(search >= 0)
  {
    printProductCategory(search);
    printf("==================================================\n");
    printf("ESTA SEGURO QUE DESEA ELIMINAR ESTA CATEGORIA?[Y/N]: ");
    scanf(" %c", &decision);
    if(decision == 'y' || decision =='Y')
    {
      productCategories[search] = emptyProductCategory;
      clearScreen();
      printf("Categoria eliminada exitosamente\n");
    }
    else
    {
      menu();
    }
  }
  else
  {
    clearScreen();
    printf("Categoria no encontrada\n\n");

  }

  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();

}

void m_deleteProduct()
{

  int product_id;
  char decision;
  printf("==================================================\n");
  printf("ELIMINACION DE PRODUCTOS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el ID del producto a eliminar: ");
  scanf("%d", &product_id);

  int search = searchProduct(product_id);
  if(search >= 0)
  {
    printProduct(search);
    printf("==================================================\n");
    printf("ESTA SEGURO QUE DESEA ELIMINAR ESTE PRODUCTO?[Y/N]: ");
    scanf(" %c", &decision);
    if(decision == 'y' || decision =='Y')
    {
      stock[search] = EmptyProduct;
      clearScreen();
      printf("Producto eliminado exitosamente\n");
    }
    else
    {
      menu();
    }
  }
  else
  {
    clearScreen();
    printf("Producto no encontrado\n\n");

  }

  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();

}

void m_searchProduct()
{

  int product_id;
  printf("==================================================\n");
  printf("BUSQUEDA DE PRODUCTOS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el numero de ID del numero: ");
  scanf("%d", &product_id);

  int search = searchProduct(product_id);
  if(search >= 0)
  {
    printProduct(search);
  }
  else
  {
    clearScreen();
    printf("Producto no encontrado\n\n");

  }


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();


}


void m_searchProductCategory()
{

  int id;
  printf("==================================================\n");
  printf("BUSQUEDA DE CATEGORIAS EN INVENTARIO");
  printf("\n==================================================\n");


  printf("Favor escriba el ID de la categoria a consultar: ");
  scanf("%d", &id);

  int search = searchProdCategory(id);
  if(search >= 0)
  {
    printProductCategory(search);
  }
  else
  {
    clearScreen();
    printf("Categoria no encontrado\n\n");

  }


  printf("\n==================================================\n");
  printf("Presione una tecla para continuar");
  printf("\n==================================================\n");
  clear_newlines();
  getchar();
  menu();


}

void m_addProduct()
{
  clearScreen();

  int id;
  char name[MAX_NAME];
  float basePrice;
  char measureUnit[5];
  char category[50];
  char creationDate[10];
  float sellingPrice;
  float upperPercentage;
  float lowerPercentage;

  printf("==================================================\n");
  printf("ADICION DE PRODUCTOS A INVENTARIO");
  printf("\n==================================================\n");

  printf("ID: ");
  scanf("%d", &id);
  clear_newlines();
  printf("\nNombre: ");
  fgets(name, 50, stdin);
  printf("Unidad de medida: ");
  fgets(measureUnit, 5, stdin);
  printf("Categoria: ");
  fgets(category, 50, stdin);
  printf("Fecha de registro(yyyy-mm-dd): ");
  fgets(creationDate, 10, stdin);
  clear_newlines();
  printf("Precio de adquisicion: ");
  scanf("%f", &basePrice);
  printf("Precio de venta: ");
  clear_newlines();
  scanf("%f", &sellingPrice);
  printf("Porcentaje superior: ");
  scanf("%f", &upperPercentage);
  printf("Porcentaje inferior: ");
  scanf("%f", &lowerPercentage);


  if(addProduct(id,basePrice, sellingPrice, upperPercentage, lowerPercentage, name, measureUnit, category, creationDate) < 0)
  {
    printf("\n==================================================\n");
    printf("Hubo un error agregando el producto");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  else
  {
    printf("\n==================================================\n");
    printf("Producto agregado exitosamente!");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  menu();
}

void m_addProdCategory()
{
  clearScreen();

  int id;
  char name[MAX_NAME];

  printf("==================================================\n");
  printf("ADICION DE CATEGORIAS A INVENTARIO");
  printf("\n==================================================\n");

  printf("ID: ");
  scanf("%d", &id);
  clear_newlines();
  printf("\nNombre: ");
  fgets(name, 50, stdin);

  if(addProdCategory(id,name) < 0)
  {
    printf("\n==================================================\n");
    printf("Hubo un error agregando la categoria");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  else
  {
    printf("\n==================================================\n");
    printf("Categoria agregada exitosamente!");
    printf("\n==================================================\n");
    printf("Presione una tecla para continuar");
    clear_newlines();
    getchar();
  }
  menu();
}


void menu()
{
  int option;

  clearScreen();
  printf("==================================================\n");
  printf("\t\tInventario MEDASOFT\n");
  printf("==================================================\n");
  printf("1.  Agregar producto\n");
  printf("2.  Buscar producto\n");
  printf("3.  Eliminar producto\n");
  printf("4.  Agregar Categoria\n");
  printf("5.  Mostrar Categorias\n");
  printf("6.  Eliminar Categoria\n");
  printf("0.  Salir\n");
  scanf("%d", &option);

  if(option == 1)
  {
    clearScreen();
    m_addProduct();
  }
  else if(option == 2)
  {
    clearScreen();
    m_searchProduct();
  }
  else if(option == 3)
  {
    clearScreen();
    m_addProdCategory();
  }

  else if(option == 4)
  {
    clearScreen();
    m_addProdCategory();
  }

  else if(option == 5)
  {
    clearScreen();
    m_searchProductCategory();
  }
  else if(option == 6)
  {
    clearScreen();
    m_deleteProductCategory();
  }
  else if(option == 0)
  {
    exit(0);
  }
}
