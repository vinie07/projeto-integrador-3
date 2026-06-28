# ============================================================
# Casos por estado
# coluna 1 = sigla do estado
# coluna 2 = casos
# ============================================================

reset # limpar configurações do gnuplot antes de rodar para evitar erros

set encoding utf8 # usar acentos e caracteres especiais

# === SAIDA , o grafico sera salva em .png ===
    set terminal png
    set output "estados.png"

# === APARENCIA ===
    set grid # ativa as linhas de grade no fundo do grafico
    set style fill pattern 3 # define o preenchimento das barras, 3 = tracejado diagonal
    # outras opcoes: solid (solido), pattern 1, 2, 4...
    set boxwidth 0.5 # largura de cada barra , 0.5 para evitar barras coladas
    set xtics rotate by -45 # inclina os rotulos do eixo X em abc(-45) graus
    # para deixar mais legivel no grafico

# === LEGENDAS ===
    set title  "Casos de SRAG por Estado" # titulo exibido no topo do grafico
    set xlabel "Estado (Sigla)" # xlabel: legenda do eixo horizontal (X) ---
    set ylabel "Casos (por milhares)" # legenda do eixo vertical (Y) | | |
    set key right top # posicao da legenda dentro do grafico , left/right/top/bottom

# === PLOT ===
# using 2:xtic(1):
#   2 = coluna 2 (numero de casos) no eixo Y
#   xtic(1) = usa coluna 1 (sigla do estado) como rotulo do eixo X
#               sem isso, o GNUplot nao sabe colocar texto no eixo X
    plot "estados.csv" using ($2/1000):xtic(1) with boxes lc 3 t "Casos"
