## Estrutura básica

### Primeira linha

A primeira linha indica qual interpretador deve rodar o script:

```bash
#!/bin/bash
```

Sem ele, o sistema pode tentar executar o script com o shell errado.

### Comentários

```bash
#!/bin/bash
# Isto é um comentário
echo "Olá"   # comentário no fim da linha também funciona
```

---

## Como executar um script

Existem duas formas principais:

```bash
# 1) Passando o script como argumento do bash (não precisa de permissão de execução):
bash meu_script.sh

# 2) Executando diretamente (precisa de permissão de execução/aplicativo):
chmod +x meu_script.sh
./meu_script.sh
```

### Tornar o script acessível de qualquer lugar (PATH)

O `PATH` é a lista de diretórios onde o shell procura por comandos. Para rodar seus scripts de qualquer pasta apenas pelo nome, adicione o diretório deles ao `PATH`:

```bash
echo $PATH                  # ver o PATH atual

PATH=$HOME/scripts:$PATH    # adiciona ~/scripts no início da busca

echo $PATH                  # conferir
```

> Essa alteração vale só para a sessão atual. Para torná-la permanente, coloque a linha do `PATH=...` no seu `~/.bashrc`.

---

## Variáveis

### Atribuição e uso

- A atribuição usa `=` **sem espaços** ao redor. `nome = "x"` dá erro.
- Para **usar** o valor, coloque `$` antes do nome.

```bash
#!/bin/bash
NOME="WILMAR"
echo "Seu nome é $NOME"
```

### Tamanho de uma string

```bash
expr length palavra        # retorna a quantidade de caracteres
```

Exemplo — medir o tamanho de uma senha digitada:

```bash
#!/bin/bash
echo "Digite a senha: "
read -s senha

comp=$(expr length "$senha")
echo
echo "A senha tem $comp caracteres."
```

> Em bash puro também dá para usar `${#senha}` para o mesmo efeito: `comp=${#senha}`.

---

## Entrada do usuário (`read`)

O comando `read` lê uma linha digitada pelo usuário e guarda numa variável.

### Forma básica

```bash
echo -n "Escreva seu nome: "
read nome
echo "Seu nome é: $nome"
```

### Opções úteis do `read`

| Opção | O que faz |
|-------|-----------|
| `-p`  | Mostra o *prompt* na mesma linha, sem precisar de `echo` |
| `-s`  | **Silencioso**: não exibe o que é digitado (ideal para senhas) |
| `-sp` | Combina os dois: prompt + entrada oculta |

```bash
#!/bin/bash
# read -p  -> prompt na mesma linha do input
# read -sp -> senha/caracteres não aparecem na tela

read -p 'username: ' user_var
read -sp 'password: ' pass_var
echo
echo "username: $user_var"
echo "password: $pass_var"
```

---

## Argumentos de linha de comando

Quando você roda `./script arg1 arg2 arg3`, esses valores ficam disponíveis em variáveis especiais:

| Variável | Significado |
|----------|-------------|
| `$0` | Nome do próprio script |
| `$1 … $n` | Argumentos na ordem (1º em `$1`, 2º em `$2`, …) |
| `$#` | Quantidade de argumentos (não conta o `$0`) |
| `$@` | Todos os argumentos (como lista de elementos separados) |
| `$*` | Todos os argumentos (como uma string única) |

> Se você tentar acessar um argumento que não foi passado (ex.: `$3` quando só vieram dois), ele vale string vazia.

### Exemplo simples

```bash
#!/bin/bash
echo "Nome do script: $0"
echo "Argumentos: $1 $2 $3"
echo "Quantidade: $#"
```

### Guardar os argumentos em um array

`"$@"` pode ser capturado dentro de um array, e o acesso é por índice (começando em 0):

```bash
#!/bin/bash
echo "$1 $2 $3"

# guarda todos os argumentos num array
args=("$@")

# acessa pelo índice: ${ARRAY[INDICE]}
echo "${args[0]} ${args[1]} ${args[2]}"

# número de argumentos
echo "$#"
```

### Percorrer todos os argumentos

```bash
#!/bin/bash
if [ $# -lt 1 ]; then
    echo "Precisa fornecer pelo menos 1 argumento!"
    exit 1
fi

echo "Número de argumentos: $#"

i=0
for argumento in "$@"; do
    i=$(($i + 1))
    echo "Argumento $i: $argumento"
done
```

`exit 1` encerra o script com código de erro 1. `exit 0` (ou `exit` sozinho) encerra com sucesso.

---

## Operadores

### Operadores de string

| Operador | Descrição |
|----------|-----------|
| `=`  | As strings são iguais |
| `!=` | As strings são diferentes |
| `-n` | Verdadeiro se a string **não** é vazia |
| `-z` | Verdadeiro se a string **é** vazia |

```bash
if [ "$nome" = "ana" ]; then echo "É a Ana"; fi
if [ -z "$senha" ]; then echo "Senha vazia!"; fi
```

### Operadores numéricos

| Operador | Equivalente | Descrição |
|----------|-------------|-----------|
| `-eq` | `=`  | Iguais |
| `-ne` | `≠`  | Diferentes |
| `-gt` | `>`  | Maior que |
| `-lt` | `<`  | Menor que |
| `-ge` | `>=` | Maior ou igual |
| `-le` | `<=` | Menor ou igual |

Dentro de `[ ]` use **sempre** as versões com letras (`-eq`, `-gt`, …) para números. Os símbolos `>` e `<` só funcionam dentro de `(( ))` ou `[[ ]]`.

### Operadores de arquivo

| Operador | Verdadeiro se  |
|----------|----------------|
| `-e` | o arquivo **existe** |
| `-d` | é um diretório |
| `-r` | tem permissão de leitura |
| `-w` | tem permissão de escrita |
| `-x` | tem permissão de execução |
| `-s` | tem tamanho maior que zero (não está vazio) |

```bash
#!/bin/bash
echo -e "Digite o nome do arquivo: \c"
read file_name

if [ -f "$file_name" ]; then
    echo "$file_name encontrado"
else
    echo "$file_name não encontrado"
fi
```

### Operadores lógicos

| Operador | Alternativa | Descrição |
|----------|-------------|-----------|
| `!`  | —    | Negação (NOT) |
| `-a` | `&&` | E lógico (AND) |
| `-o` | `\|\|` | OU lógico (OR) |

```bash
# dentro de [ ]: usa -a / -o
if [ "$idade" -ge 18 -a "$idade" -lt 65 ]; then echo "Adulto"; fi

# dentro de [[ ]]: usa && / || (forma moderna, **recomendada**)
if [[ "$idade" -ge 18 && "$idade" -lt 65 ]]; then echo "Adulto"; fi
```

---

### As tres formas

| Forma | Uso típico | Observações |
|-------|------------|-------------|
| `[ condição ]` | A mais comum | **Precisa de espaços** internos: `[ $x -gt 2 ]` |
| `[[ condição ]]` | Bash **moderno** | Mais segura; permite `&&`, `\|\|`, `<`, `>`, padrões |
| `(( expressão ))` | Aritmética | Trabalha com números; `>` e `<` funcionam normalmente |

Regra de ouro do `[ ]`: **sempre coloque espaços** depois do `[` e antes do `]`. `[ $x -gt 2 ]` funciona; `[$x -gt 2]` dá erro.

### Exemplos comparando as formas

```bash
#!/bin/bash
count=10

# forma com [ ] e operador numérico
if [ $count -eq 10 ]; then
    echo "true"
fi
```

```bash
#!/bin/bash
count=10

# forma aritmética (( ))
if (( count > 9 )); then
    echo "true"
fi
```

```bash
#!/bin/bash
word=a

# [[ ]] permite comparação de strings com < (ordem alfabética)
if [[ $word < "b" ]]; then
    echo "vem antes de b"
elif [[ $word == "a" ]]; then
    echo "é igual a a"
else
    echo "false"
fi
```

Dentro de `(( ))` você nem precisa do `$` nas variáveis: `(( count > 9 ))` funciona igual a `(( $count > 9 ))`.

---

## Estruturas condicionais: `if` / `elif` / `else`

### Sintaxe

```bash
if condição
then
    instrução
    instrução
elif outra_condição
then
    instrução
else
    instrução
fi
```

O `then` pode ficar na linha de baixo (como acima) ou na mesma linha do `if`, desde que separado por `;`:

```bash
if [ condição ]; then
    ...
fi
```

### Exemplo 1 — comparação simples

```bash
#!/bin/bash
variavel=3
if (( variavel > 10 )); then
    echo "Você digitou número maior que 10"
else
    echo "Você digitou o número '$variavel'"
fi
```

### Exemplo 2 — com leitura do usuário

```bash
#!/bin/bash
echo "Digite um valor para comparar: "
read variavel

if (( variavel > 10 )); then
    echo "Você digitou um número maior que 10"
else
    echo "Você digitou o número '$variavel'"
fi
```

### Exemplo 3 — saudação conforme o horário

```bash
#!/bin/bash
HORARIO=$(date +%H)
echo "Hora local: $HORARIO horas"

if [ $HORARIO -lt 12 ]; then
    echo "Bom dia, $LOGNAME"
elif [ $HORARIO -ge 18 ]; then
    echo "Boa noite, $LOGNAME"
else
    echo "Boa tarde, $LOGNAME"
fi
```
`$(date +%H)` captura a hora atual (00–23). `$LOGNAME` é uma variável de ambiente com o nome do usuário logado.

### Exemplo 4 — idade

```bash
#!/bin/bash
echo -n "Digite sua idade: "
read idade

if [ $idade -lt 18 ]; then
    echo "Você é menor de idade."
else
    echo "Você é maior de idade."
fi
```

---

## `case`

O `case` é ideal quando você precisa comparar **uma variável** contra **vários valores possíveis** — mais limpo que uma cadeia enorme de `elif`.

```bash
#!/bin/bash
opcao=nao
case $opcao in
    Sim | sim ) echo "Você concordou!" ;;
    Nao | nao ) echo "Você NÃO concordou!" ;;
            * ) echo "Nem sim, nem não. Talvez?" ;;
esac
```

Pontos importantes da sintaxe:

- Cada padrão termina com `)` e cada bloco termina com `;;`.
- `|` separa **alternativas** para o mesmo bloco (`Sim | sim`).
- `*` é o "qualquer outra coisa" (default), sempre por último.
- Fecha com `esac` (que é "case" ao contrário).

Outro exemplo:

```bash
#!/bin/bash
echo -n "Em que planeta você mora? "
read planeta

case $planeta in
    "terra") echo "Você é terráqueo." ;;
    "marte") echo "Você é marciano." ;;
          *) echo "Planeta desconhecido!" ;;
esac
```

---

## Estruturas de repetição

### fors

**Forma 1 — lista explícita de valores:**

```bash
#!/bin/bash
for i in 1 2 3 4 5; do
    echo "$i"
done
```

**Forma 2 — intervalo com `{início..fim}`:**

```bash
#!/bin/bash
for i in {1..10}; do
    mkdir "$i"
done
```

**Forma 3 — escrevendo em arquivo (`>>` acrescenta no final):**

```bash
#!/bin/bash
for i in {1..10000}; do
    echo "$i" >> lista.txt
done
```

**Forma 4 — percorrendo uma lista de palavras:**

```bash
#!/bin/bash
for fruta in goiaba abacaxi banana; do
    echo "$fruta"
done
```

**Forma 5 — usando `seq` para gerar a sequência:**

```bash
#!/bin/bash
for i in $(seq 0 10); do
    quadrado=$(( i * i ))
    echo "$i ao quadrado é: $quadrado"
done
```

**`continue` para pular uma iteração:**

```bash
#!/bin/bash
# Apaga todos os .txt do diretório, exceto critico.txt
for arquivo in *.txt; do
    if [ "$arquivo" = "critico.txt" ]; then
        continue        # pula este e vai para o próximo
    fi
    rm "$arquivo"
done
```

Além de `continue` (pula para a próxima volta), existe `break` (sai do laço imediatamente).

### `while`

Repete **enquanto** a condição for verdadeira:

```bash
#!/bin/bash
i=1
while (( i < 10 )); do
    echo "$i"
    i=$(( i + 1 ))
done
```

Aqui usamos `i=$(( i + 1 ))` para incrementar. A forma antiga com `i=$(expr $i + 1)` faz o mesmo, mas `$(( ))` é nativo do bash e mais rápido.

---

## Funções

Funções agrupam comandos sob um nome, para reaproveitar código e organizar o script.

### Sintaxe

```bash
# forma 1
function nome() {
    comandos
}

# forma 2 (mais comum)
nome() {
    comandos
}
```

Importante: a função precisa ser **definida antes** de ser chamada na execução. Por isso é comum definir todas as funções primeiro e deixar a chamada principal (main) por último.

### Função simples

```bash
mostrar_boas_vindas() {
    echo "Bem-vindo ao meu script!"
}

mostrar_boas_vindas    # chama a função
```

### Função com argumentos

Dentro da função, os argumentos recebidos também ficam em `$1`, `$2`, … (igual aos argumentos do script):

```bash
mostrar_mensagem() {
    echo "A mensagem é: $1"
}

mostrar_mensagem "Olá, mundo!"
```

---

## `echo`, `-e`, `-n` e caracteres de escape

| Opção do `echo` | Efeito |
|-----------------|--------|
| `-n` | Não pula linha no final (cursor fica na mesma linha) |
| `-e` | Interpreta sequências de escape como `\n`, `\t`, `\c` |

Sequências de escape mais comuns (precisam do `-e`):

| Sequência | Significado |
|-----------|-------------|
| `\n` | Nova linha |
| `\t` | Tabulação |
| `\a` | Alerta sonoro (beep) |
| `\c` | Interrompe a saída ali (não imprime nada depois nem pula linha) |

```bash
echo -e "Digite o nome do arquivo: \c"   # mantém o cursor na mesma linha
echo -e "Linha 1\nLinha 2"               # quebra em duas linhas
```

---

## Exemplos completos

### Calculadora com menu (funções + `case` + recursão de menu)

```bash
#!/bin/bash
# Calculadora básica — operações com inteiros
# Soma, Subtração, Multiplicação e Divisão

clear

menu() {
    echo "         Calculadora Básica"
    echo "      Operação apenas com inteiros"
    echo "|-----------------------------------|"
    echo "| Escolha uma das opções abaixo:    |"
    echo "|-----------------------------------|"
    echo "| 1) Soma                           |"
    echo "| 2) Subtração                      |"
    echo "| 3) Multiplicação                  |"
    echo "| 4) Divisão                        |"
    echo "| 5) Sair                           |"
    echo "|-----------------------------------|"
    read opcao
    case $opcao in
        1) soma ;;
        2) subtra ;;
        3) mult ;;
        4) div ;;
        5) exit ;;
        *) echo "Opção inexistente" ; clear ; menu ;;
    esac
}

soma() {
    clear
    echo "Informe o primeiro número: "
    read num1
    echo "Informe o segundo número: "
    read num2
    echo "Resposta = $(expr $num1 "+" $num2)"
    menu
}

subtra() {
    clear
    echo "Informe o primeiro número: "
    read num1
    echo "Informe o segundo número: "
    read num2
    echo "Resposta = $(expr $num1 "-" $num2)"
    menu
}

mult() {
    clear
    echo "Informe o primeiro número: "
    read num1
    echo "Informe o segundo número: "
    read num2
    echo "Resposta = $(expr $num1 "*" $num2)"
    menu
}

div() {
    clear
    echo "Informe o primeiro número: "
    read num1
    echo "Informe o segundo número: "
    read num2
    echo "Resposta = $(expr $num1 "/" $num2)"
    menu
}

menu
```

O `*` da multiplicação aparece entre aspas (`"*"`) porque, solto, o shell o interpretaria como "todos os arquivos do diretório" (globbing). As aspas o tratam como texto literal para o `expr`.

---

## Referência rápida (cheat sheet)

### Variáveis e entrada

```bash
nome="valor"          # atribuição (sem espaços!)
echo "$nome"          # uso
echo "${nome}_x"      # delimitando o nome
${#nome}              # tamanho da string
read var              # lê entrada
read -p "msg: " var   # lê com prompt
read -s var           # lê sem exibir (senha)
```

### Argumentos

```bash
$0   # nome do script
$1   # primeiro argumento
$#   # quantidade de argumentos
$@   # todos (lista)
$*   # todos (string)
```

### Testes

```bash
[ $x -eq 5 ]        # numérico, forma clássica (espaços obrigatórios)
[[ $s == "ok" ]]    # string/padrões, bash moderno
(( x > 5 ))         # aritmética
```

### Operadores numéricos (dentro de `[ ]`)

```
-eq  -ne  -gt  -lt  -ge  -le
 =    ≠    >    <    >=   <=
```

### Estruturas

```bash
# if
if [ cond ]; then 
    ... 
elif [ cond ]; then 
    ... 
else 
    ... 
fi

# case
case $v in 
    p1) ... ;; 
    p2|p3) ... ;; 
    *) ... ;; 
esac

# for
for i in {1..5}; do 
... 
done

for i in $(seq 0 10); 
do 
    ... 
done

# while
while (( i < 10 )); do ...; i=$(( i + 1 )); done
```

### Lembretes que mais pegam

- `[ ]` **exige espaços** internos.
- Atribuição de variável **não tem espaços** no `=`.
- Em `[ ]` use `-gt`, `-lt`, … para números; `>` e `<` só em `(( ))` e `[[ ]]`.
- A função precisa ser definida **antes** de ser chamada.

---