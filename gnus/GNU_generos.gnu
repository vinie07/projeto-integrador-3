# ============================================================
# Casos por genero por ano
# coluna 1 = ano,
# coluna 2 = masculino,
# coluna 3 = feminino
# ============================================================

reset # limpar configurações do gnuplot antes de rodar para evitar erros

set encoding utf8 # usar acentos e caracteres especiais

# === SAIDA , o grafico sera salva em .png ===
set terminal png
set output "generos.png"

# === APARENCIA ===
set grid # ativa as linhas de grade no fundo do grafico
set style fill pattern 3 # define o preenchimento das barras, 3 = tracejado diagonal
# outras opcoes: solid (solido), pattern 1, 2, 4...
set boxwidth 0.4 # largura de cada barra , 0.4/0.5 para evitar barras coladas

# === LEGENDAS ===
set title  "Casos de SRAG por Genero e Ano" # titulo exibido no topo do grafico
set xlabel "Ano" # xlabel: legenda do eixo horizontal (X) ---
set ylabel "Casos (em milhares)" # legenda do eixo vertical (Y) | | |
set key right top # posicao da legenda dentro do grafico , left/right/top/bottom

# === PLOT ===
# Tecnica para +1 barras = barra lado a lado
# ($1-0.2) = desloca masculino/coluna1 0.2 unidades para a esquerda
# ($1+0.2) = desloca feminino/coluna2  0.2 unidades para a direita
# assim as duas barras ficam separadas dentro do mesmo ano
# virgula (,) separa as duas series no mesmo plot
# lc 8 = preto (masculino)
# lc 3 = azul  (feminino)
plot "generos.csv" using ($1-0.2):($2/1000) with boxes lc 0 t "Masculino", \
     "generos.csv" using ($1+0.2):($3/1000) with boxes lc 10 t "Feminino"
