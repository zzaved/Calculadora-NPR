# Calculadora RPN - Notação Polonesa Reversa

## Descrição

Este projeto implementa uma calculadora que avalia expressões em **Notação Polonesa Reversa (RPN)** usando o Tipo Abstrato de Dados (TAD) Pilha em linguagem C.

## O que é RPN?

Na RPN, os operadores vêm **depois** dos operandos, eliminando a necessidade de parênteses.

**Exemplo:**
- Normal: `(3 + 4) × 5`
- RPN: `3 4 + 5 *`

## Como Funciona o Algoritmo

### Regra simples:
1. **Número** → empilha
2. **Operador** → desempilha 2 números, calcula, empilha o resultado

### Exemplo: `3 4 + 5 *`
1. `3` → pilha: [3]
2. `4` → pilha: [3, 4]  
3. `+` → desempilha 4 e 3, calcula 3+4=7, empilha 7 → pilha: [7]
4. `5` → pilha: [7, 5]
5. `*` → desempilha 5 e 7, calcula 7×5=35, empilha 35 → pilha: [35]
6. **Resultado: 35**

## Implementação

### 1. TAD Pilha

```c
typedef struct {
    double dados[MAX_SIZE];
    int topo;
} Pilha;

// Operações implementadas:
void inicializaPilha(Pilha* p);  // Inicializa pilha vazia
int estaVazia(Pilha* p);         // Verifica se está vazia  
void push(Pilha* p, double valor); // Empilha valor
double pop(Pilha* p);            // Desempilha valor
```

### 2. Leitura e Tokenização

- Usa `fgets()` para ler a expressão
- Usa `strtok()` para separar por espaços
- Identifica se cada token é número ou operador

### 3. Avaliação da Expressão

```c
double avaliarRPN(char* expressao) {
    // Inicializa pilha
    // Para cada token:
    //   Se número: empilha
    //   Se operador: desempilha 2, calcula, empilha resultado
    // Retorna resultado final
}
```

## Operações Suportadas

- **Adição** (`+`): `3 4 +` = 7
- **Subtração** (`-`): `10 3 -` = 7  
- **Multiplicação** (`*`): `5 6 *` = 30
- **Divisão** (`/`): `15 3 /` = 5

## Como Usar

### Compilar:
```bash
gcc -o calc calculadora_rpn.c
```

### Executar:
```bash
./calc
```

### Exemplos:
```
RPN> 3 4 +
Resultado: 7.0

RPN> 5 1 2 + 4 * + 3 -
Resultado: 14.0

RPN> sair
```

## Exemplos de Teste

| Expressão RPN | Equivale a | Resultado |
|---------------|------------|-----------|
| `3 4 +` | 3 + 4 | 7 |
| `5 1 2 + 4 * + 3 -` | 5 + (1+2)×4 - 3 | 14 |
| `15 7 1 1 + - / 3 *` | 15÷(7-(1+1))×3 | 9 |

## Estrutura do Código

1. **TAD Pilha**: Implementação com array estático
2. **Funções auxiliares**: Verificação de números e operadores
3. **Avaliador RPN**: Processa a expressão usando pilha
4. **Interface**: Loop para múltiplas expressões