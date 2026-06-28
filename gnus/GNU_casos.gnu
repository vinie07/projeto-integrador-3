# ============================================================
# Casos de SRAG por ano
# coluna 1 = ano, 
# coluna 2 = total de casos
# ============================================================

reset # limpar configurações do gnuplot antes de rodar para evitar erros

set encoding utf8 # usar acentos e caracteres especiais

# === SAIDA , o grafico sera salva em .png ===
set terminal png
set output "casos.png"

# === APARENCIA ===
set grid # ativa as linhas de grade no fundo do grafico
set style fill pattern 3 # define o preenchimento das barras, 3 = tracejado diagonal
# outras opcoes: solid (solido), pattern 1, 2, 4...
set boxwidth 0.5 # largura de cada barra , 0.5 para evitar barras coladas

# === LEGENDAS ===
set title "Casos de SRAG por Ano" # titulo exibido no topo do grafico
set xlabel "Ano" # xlabel: legenda do eixo horizontal (X) ---
set ylabel "Casos (em milhares)" # legenda do eixo vertical (Y) | | |
set key right top # posicao da legenda dentro do grafico , left/right/top/bottom

# === PLOT ===
# "ano.csv" = nome do arquivo a ser aberto .gnu
# using 1:($2/1000)
#   -> coluna 1 no eixo X, 
#   -> coluna 2 dividida por 1000 no eixo Y (evita notacao cientifica)
# with boxes = estilo de grafico em barras
# lc 8 = line color 8 = preto
# t "..." =  nome exibido na legenda
plot "ano.csv" using 1:($2/1000) with boxes lc 8 t "Casos"
