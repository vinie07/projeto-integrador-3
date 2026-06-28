# ============================================================
# Obitos por SRAG por ano
# coluna 1 = ano, 
# coluna 2 = total de obitos
# ============================================================

reset # limpar configurações do gnuplot antes de rodar para evitar erros

set encoding utf8 # usar acentos e caracteres especiais

# === SAIDA , o grafico sera salva em .png ===
    set terminal png
    set output "obitos.png"

# === APARENCIA ===
    set grid # ativa as linhas de grade no fundo do grafico
    set style fill pattern 3 # define o preenchimento das barras, 3 = tracejado diagonal
    # outras opcoes: solid (solido), pattern 1, 2, 4...
    set boxwidth 0.5 # largura de cada barra , 0.5 para evitar barras coladas

# === LEGENDAS ===
    set title  "Obitos por SRAG por Ano" # titulo exibido no topo do grafico
    set xlabel "Ano" # xlabel: legenda do eixo horizontal (X) ---
    set ylabel "Obitos" # legenda do eixo vertical (Y) | | |
    set key right top # posicao da legenda dentro do grafico , left/right/top/bottom

# === PLOT ===
# usando 1:2 diretamente (sem dividir por 1000) pois os valores de obitos sao menores e legiveis no eixo
# lc 1 = line colors roxo=1
    plot "obitos.csv" using 1:2 with boxes lc 1 t "Obitos"