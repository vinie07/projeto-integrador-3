# ============================================================
# Internacoes por SRAG por ano
# coluna 1 = ano
# coluna 2 = internacoes
# ============================================================

reset # limpar configurações do gnuplot antes de rodar para evitar erros

set encoding utf8 # usar acentos e caracteres especiais

# === SAIDA , o grafico sera salva em .png ===
set terminal png
set output "internacoes.png"

# === APARENCIA ===
set grid # ativa as linhas de grade no fundo do grafico
set style fill pattern 3 # define o preenchimento das barras, 3 = tracejado diagonal
# outras opcoes: solid (solido), pattern 1, 2, 4...
set boxwidth 0.5 # largura de cada barra , 0.5 para evitar barras coladas

# === LEGENDAS ===
set title  "Internacoes por SRAG por Ano" # titulo exibido no topo do grafico
set xlabel "Ano" # xlabel: legenda do eixo horizontal (X) ---
set ylabel "Internacoes (em milhares)" # legenda do eixo vertical (Y) | | |
set key right top # posicao da legenda dentro do grafico , left/right/top/bottom

# === PLOT ===
# lc 5 = line color/s amarelo=5
plot "internacoes.csv" using 1:($2/1000) with boxes lc 5 t "Internacoes"