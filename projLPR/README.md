# Sistema de Controle de Eventos

Projeto final da disciplina de Linguagem de Programação em C.

## Integrantes

- Ariane Parolin
- Luiza Oliveira
- Otavio Sanchez
- Lucas Siqueira

## Conteúdos Utilizados

- Menu interativo
- Estruturas de repetição (while, for)
- Estruturas condicionais (if, switch)
- Vetores
- Funções
- Cores no terminal
- Validação de dados

## Funcionalidades

1. Cadastrar Evento
2. Listar Eventos
3. Buscar Evento
4. Alterar Evento
5. Excluir Evento
6. Inscrever Participante
7. Relatório de Participantes
8. Sair

## Dados do Evento

Cada evento possui:

- Código
- Nome
- Local
- Data
- Quantidade de vagas
- Quantidade de inscritos

## Validações

- Não permite código duplicado
- Não permite texto em campos numéricos
- Não permite datas anteriores à data atual
- Não permite quantidade de vagas menor ou igual a zero

## Tecnologias

- Linguagem C
- GCC (MinGW)
- Visual Studio Code

## Como Executar

Compilar:

```bash
gcc main.c -o main
```

Executar:

```bash
.\main.exe
```

---

Projeto desenvolvido para fins acadêmicos na disciplina de Linguagem de Programação.