#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Estrutura da Pilha
typedef struct {
    double dados[MAX_SIZE];
    int topo;
} Pilha;

// ============= FUNCOES DA PILHA =============

// Inicializa a pilha
void inicializaPilha(Pilha* p) {
    p->topo = -1;
}

// Verifica se a pilha esta vazia
int estaVazia(Pilha* p) {
    return p->topo == -1;
}

// Empilha um valor
void push(Pilha* p, double valor) {
    p->topo++;
    p->dados[p->topo] = valor;
}

// Desempilha um valor
double pop(Pilha* p) {
    double valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

// ============= FUNCOES AUXILIARES =============

// Verifica se eh um numero
int ehNumero(char* str) {
    int i = 0;
    
    // Pode comecar com - ou +
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
    }
    
    // Verifica se tem pelo menos um digito
    if (str[i] == '\0') {
        return 0;
    }
    
    // Verifica cada caractere
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            if (str[i] != '.') {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

// Faz a operacao matematica
double calcular(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// ============= FUNCAO PRINCIPAL =============

double avaliarRPN(char* expressao) {
    Pilha pilha;
    inicializaPilha(&pilha);
    
    // Separa a string em pedacos
    char* token = strtok(expressao, " ");
    
    while (token != NULL) {
        
        if (ehNumero(token)) {
            // eh numero: empilha
            double num = atof(token);
            push(&pilha, num);
            printf("Empilhou: %.1f\n", num);
        }
        else if (strlen(token) == 1 && 
                (token[0] == '+' || token[0] == '-' || 
                 token[0] == '*' || token[0] == '/')) {
            // eh operador: desempilha 2, calcula, empilha resultado
            
            if (pilha.topo < 1) {
                printf("Erro: faltam numeros!\n");
                return 0;
            }
            
            double b = pop(&pilha);
            double a = pop(&pilha);
            double resultado = calcular(a, b, token[0]);
            
            printf("%.1f %c %.1f = %.1f\n", a, token[0], b, resultado);
            
            push(&pilha, resultado);
        }
        else {
            printf("Erro: '%s' nao eh valido\n", token);
            return 0;
        }
        
        // Proximo token
        token = strtok(NULL, " ");
    }
    
    // No final deve ter apenas 1 numero na pilha
    if (pilha.topo != 0) {
        printf("Erro: expressao incompleta\n");
        return 0;
    }
    
    return pop(&pilha);
}

// ============= PROGRAMA PRINCIPAL =============

int main() {
    char entrada[200];
    
    printf("=== CALCULADORA RPN ===\n");
    printf("Digite uma expressao (exemplo: 3 4 +)\n");
    printf("Digite 'sair' para terminar\n\n");
    
    while (1) {
        printf("RPN> ");
        
        // Le a linha
        fgets(entrada, sizeof(entrada), stdin);
        
        // Remove a quebra de linha
        if (entrada[strlen(entrada)-1] == '\n') {
            entrada[strlen(entrada)-1] = '\0';
        }
        
        // Verifica se quer sair
        if (strcmp(entrada, "sair") == 0) {
            break;
        }
        
        // Pula linhas vazias
        if (strlen(entrada) == 0) {
            continue;
        }
        
        printf("\nCalculando: %s\n", entrada);
        
        double resultado = avaliarRPN(entrada);
        printf("Resultado: %.1f\n\n", resultado);
    }
    
    printf("Fim!\n");
    return 0;
}