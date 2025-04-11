# Algoritmos e Tipos Abstratos de Dados

## Lab 6 - Desenvolvimento de um ADT (Vector3D)

Este repositório foi criado a partir de:

- <https://github.com/estsetubal-atad/CProgram_Template> 

Consulte o README se tiver dúvidas sobre a sua utilização.

----

**Objetivos**:

- Consolidar metodologia para ADTs na linguagem C nas vertentes:

    - Especificação, Implementação e Utilização.

**Referências**:

- Capítulo 2 do livro “Tipos Abstratos de Dados – Linguagem C. Bruno Silva”, disponível no Moodle.

    - Especificação, uso e implementação do ADT `Complex` contido nesse capítulo.

---

:exclamation: Existe um *bash script* incluído, i.e., `mem_check.sh` que permite lançar o *valgrind* de forma correta. Quando necessário, execute no terminal `$> bash mem_check.sh`.

### 1 | Introdução

O objetivo deste laboratório é o de consolidar a metodologia proposta para a especificação, implementação e uso de tipos abstratos de dados na Linguagem C. Para tal será solicitado a obtenção e uso do ADT `Vector3D`, cujo propósito é permitir a manipulação de vetores num espaço cartesiano tri-dimensional.

Notas :bulb::

- Durante as etapas serão solicitados simultaneamente a execução de exercícios nas três vertentes anteriores;

- Deverá obedecer à nomenclatura proposta, nomeadamente a utilização do prefixo `vector3d...` para os nomes das operações e `VECTOR3D_...` para os códigos de erro;

- A especificação do ADT deve ser acompanhada pela documentação doxygen.

### 2 | Definição de estrutura de dados

1. Defina a estrutura de dados necessária para guardar a informação de uma instância de um vector;

2. Implemente as funções `vector3dCreate` e `vector3dPrint`, seguindo a documentação fornecida.

3. Teste o programa fornecido inicialmente, verificando a sua correção.

4. Verifique a correção da gestão de memória com o *valgrind*.

### 3 | Gestão de memória e teste

5. Implemente a função `vector3dDestroy` e utilize-a para libertar a memória da instância do vector declarado no programa inicial. Verifique a correção da gestão de memória com o *valgrind*.

6. Declare duas novas instâncias de `PtVector3d` e imprima os seus conteúdos. 

    - Uma inicializada através de `vector3dCreate`; a outra inicializada a `NULL`.

    - Verifique a correção da gestão de memória com o *valgrind*. 

### 4 | Implementação de funções (1/3)

7. Implemente as funções "acessoras" `vector3dX`, `vector3dY` e `vector3dZ` que permitem obter (através de passagem por referência) os valores individuais as componentes de um vector.

8. No ficheiro `main.c` declare e implemente a seguinte função:

    - `void printComponentsOf(PtVector3d vec)` - "extrai" as componentes individuais de `vec` (através das funções do ponto 7) e imprime-as no formato `"x = <val> | y = <val> | z = <val>"`.

    - Caso `vec` seja inválido, apresente `"Vector NULL. Não é possível apresentar as componentes."`. Esta **verificação deve ser feita através da verificação do código de erro devolvido** por, e.g.., `vector3dX`. Podia ser feito através de `vec != NULL`, mas esse não é o objetivo aqui.

9. Teste a função anterior no `main`, passando uma instância válida e a outra inicializada a `NULL`.

### 5 | Implementação de funções (2/3)

10. Implemente e teste a função `vector3dMultiplyByScalar` de acordo com a sua documentação. 

    - O resultado esperado para `<2, 1, -4> * 3` é `<6, 3, -12>`.

11. Implemente e teste a função `vector3dAdd` de acordo com a sua documentação. 

    - O resultado esperado para `<2, 1, -4> + <1, 0, 3>` é `<3, 1, -1>`.

12. Implemente e teste a função `vector3dMagnitude` de acordo com a sua documentação. 

    - O resultado esperado para `||<2, 1, -4>||` é `4.58`.

13. Verifique a correção da gestão de memória com o *valgrind*. 

### 6 | Implementação de funções (3/3)

14. Implemente e teste a função `vector3dNormalize` de acordo com a sua documentação. 

    - O resultado esperado para `norm(<2, 1, -4>)` é `<0.44, 0.22, -0.87>`.

    - No `main`, verifique que a *magnitude*  do vector resultante é `1` (que é o propósito da normalização).

15. Verifique a correção da gestão de memória com o *valgrind*.  

### Adicional (autónomo)

16. Adicione à especificação do ADT a seguinte função e implemente-a:

    ```cpp
    /**
     * @brief Checks whether two vectors are orthogonal
     * 
     * @param vec1 [in] PtVector3d pointer
     * @param vec2 [in] PtVector3d pointer
     * @return true if they are orthogonal
     * @return false if they are not orthogonal
     * @return false if vec1 is NULL or vec2 is NULL
     */
    bool vector3dOrthogonals(PtVector3d vec1, PtVector3d vec2);
    ```

    Dois vectores são ortogonais se formarem entre ambos um ângulo de 90º no espaço cartesiado.  
    Uma das formas de o verificar é se o *produto interno* entre os dois vectores for zero.

    `<x1, y1, z1> * <x2, y2, z2> = x1 * x2 + y1 * y2 + z1 * z2`

17. Teste a correção deste operação sabendo que:

    - Os vectores `<1, 2, 3>` e `<3, 6, -5>` **são** ortogonais, e;
        
    - Os vectores `<2, 1, -4>` e `<3, 6, -5>` **não são** ortogonais.

---

<bruno.silva@estsetubal.ips.pt>
