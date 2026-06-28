https://www.youtube.com/watch?v=9QUtcfyBFhE&list=PLaYBfUc8SG7W4cTZprVWjbtwrottWuk8c

* * *

# [https://www2.fct.unesp.br/docentes/carto/galo/web/gnuplot/pdf/2024\_Galo\_Gnuplot\_Tutorial.pdf](https://www2.fct.unesp.br/docentes/carto/galo/web/gnuplot/pdf/2024_Galo_Gnuplot_Tutorial.pdf)

# plot

comando basico usado para fazer a visualização `plot`

plot sin(x)

![image.png](assets/48cbc44dfa5d1c0402739555d5294b78dde10467b8b515899e9f8d598cc4e6ea.png)

plot log(x)

![image.png](assets/65088468f451eb27883b61e05d64a2889a9f7d5dace285851d7c4edb59e14555.png)

* * *

# Ativação da grade

`set grid` antes do plot.

Para desativar : `set nogrid`

```
set grid
plot log(x)
```

![image.png](assets/e4612699efb693728103832e620b59dbf292750f9191ff0f3b34ff8685d38c31.png)

* * *

# Coordenadas x,y,z(3d)

`set xrange`

`set yrange`

`set zrange`

```
set xrange [0:3]
plot log(x)
 OU
plot [0:3] log(x)
```

![image.png](assets/6dcfd6da821e065ac68815b940fbf0e4c239f355fd346f30974e66f851f2c791.png)

* * *

# Mais de uma visualização

`, ou rep`

```
set grid
plot sin(x),\
cos(x/3),\
x/14-1
	OU
set grid
plot(x)
rep cos(x/3)
rep x/14-1
```

![image.png](assets/3b06646c6576ec02422d7f3945d4e303af094c9b9e230a9265e52e21881cc8d2.png)

* * *

# Modificação de atributos

# Cor, tipos de pontos e linhas

`test`

![image.png](assets/efd85cdcdfd2a3d16dbc8e478f9e8a24c26b3d09127aa82c96f24825b5ca8e64.png)

# Linhas

```
plot sin(x/2) ...
with points
with lines
with linespoints
with dots
with impulses
```

# Cores

`lc`

```
plot sin(x/2) with points/lines/linespoints/dots/impulses...
lc 3 = azul
lc 5 = amarelo
lc 1 = roxo
lc 8 = preto
lc 9 = ultra-roxo
```

* * *

# Entidades pontuais

`pt`

```
plot [0:pi/2] sin(x/2) with points lc 10 pt 6
rep cos(4*x) with impulses lc 3
```

observação: primeira linha tem o numero **10 representando a cor** e **6 representa o tipo do ponto**

Primeiro numero = lc → cor

Segundo numero = pt →tipo de ponto

![image.png](assets/fd704872e84c75cd0d162262affb23ae84f73d74acdecc201a08b078cf18248d.png)

* * *

# Unica função usando diferentes opções

```
OPÇAO 1:
set xrange [-2*pi:2*pi]
plot sin(x/2)

OPÇÃO 2:
set xrange [-2*pi: 2*pi]
f(x)=sin(x/2)
plot f(x)

OPÇÃO 3:
set xrange [-2*pi:2*pi]
f(x,b)=sin(x/b)
plot f(x,2)

OPÇÃO 4:
set xrange [-2*pi:2*pi]
f(x)=sin(x*a)
plot f(x), a=0.5

OPÇÃO 5:
set xrange [-2*pi:2*pi]
f(x,a)=sin(a*x)
plot f(x,0.5)
```

![image.png](assets/0021d533775a6d11b4c3e17d122f5b015c37cc7bfe168785809c984b6bbd7770.png)

* * *

# Ver varias funç~ões simultaneamente no mesmo dominio

É feito um `script`

```
set xrange [-10:10]
f1(x)=180
f2(x)=13*x-200
f3(x)=4-2*x*x-3*x
f4(x)=0.5*x*x*x-34*x+2*x*x-22
plot f1(x)
rep f2(x)
rep f3(x)
rep f4(x)
```

Ou , uma opção mais geral para visualizar os polinomios seria escrever um polinomio de grau 3.

`y = f(x) = a + bx + cx² + dx³`

onde a,b,c,d são constantes.

```
reset
set xrange[-10:10]
f(x,a,b,c,d)=a+b*x+c*x**2+d*x**3
```

![2249ef804600335668eb930a5a0ed48a278700796249213cf34d25680620e627.png](assets/a01fe2a5e194a28f0d8716a7a0a8238d645e5096a167841ea45935910c9fd611.png)

* * *

# Leitura e visualização de dados a partir de arquivos/texto/legenda

![image.png](assets/763c42da2674ff690d494a482203285e42511d188e38d5dedc181ad2a48677b5.png)

```
reset
plot "desniv.txt"
```

![image.png](assets/dbae542c21ad563a6f021644fa8232e21115785fcfe324ef6f5d3d96f38b5eec.png)

É possivel explicitar as colunas que se quer utilizar, usando a opção `string`

```
reset
plot "desniv.txt" using 1:2
OU
reset
plot "desniv.txt" using ($1) : ($2)
```

* * *

# Inserção de titulo e texto nos eixos x e y

```
set title "texto que corresponde ao titulo"
set xlabel "texto que corresponde a abscissa"
set ylabel "texto que corresponde a ordenada"
```

```
reset
set grid
set xrange[0:25]
set title "Função Parabolica \n Teste 1"
set xlabel "X - Tempo (s)"
set ylabel "Y - Aceleração (m/s2)"
f(x)=0.1*x**2-5*x+20
plot f(x) with lines lc 8
```

![image.png](assets/9b1ba49bcab86372c4a4ea7325d82b2c9c3ad11f26ee776f9f086756a9d63565.png)

# Modificação do espaçamento da grade

```
set xtics ix
set ytics iy
```

```
reset
set grid
set xtics 2
seet ytics 5
set xrange [0:25]
set title "Função Parabolica \n teste 1"
set xlabel "x - tempo (s)"
set ylabel "y - aceleração (m/s2)"
f(x)=0.1*x**2-5*x+20
plot f(x) with lines lc 8
```

![image.png](assets/7c0b7b922c8e381e7d37d9be92dc0093ba603b98765f1522a994eb8679e6c575.png)

```
...
set grid
set xtics 2
set mxtics 2
set ytics 5
set mytics 2
set xrange [0:25] ...
```

![image.png](assets/3cc11703b8fff26005d94e52b74ddd787eb0f107780bfd1da8f0d2dfc4aaae25.png)

# Modificação da legenda

opção t seguido do texto a ser escrito , na **mesma linha** do plot ou rep

```
reset
set grid
set xtics 2
set mxtics 2
set tics 40
set mytics 2
set xrange[0:25]
set title "Função Parabolica \n Teste 1"
set xlabel "X - Tempo (s)"
set ylabel "Y - Aceleração (m/s2)"
f(x,a,b,c)=a+b*x+c*x**2
plot f(x,120,-5,0.1) t"Função 1" with points lc 3 pt 5
rep f(x,80,+10,-0.15) t"Função 2" with lines lc 8
```

![image.png](assets/10ff2aab06737a35aa914b5c758fbf714eab875abdd01c4f120718720ee5b8e1.png)

# Modificar localização da legenda

```
set key left bootom (canto inferior esquerdo)
set key right bottom (canto inferior direito)
set key left top (canto superior esquerdo)
set key right top (canto superior direito)
```

* * *

# Criação de Scripts em arquivos

Escrever o script em arquivo e depois carregar no aplicativo

1.  abrir aplicativo
    
2.  load “nome.gnu”
    

* * *

# Operador ternário

```
<Expressao E> ? < Opção A> : < Opção B >
```

![image.png](assets/5e5acf5e4a4207eb2af4680d60871035216d3f015e4e79c36368d07f8719b6f4.png)

```
reset
set xtics 1
set grid
set xrange [0:10]

f(x)=2*x-60
g(x)=-x**2+2*x-2
f(x)=(4<=x && x<=7) ? f(x):g(x)

plot f(x) t "Função Composta"
Pause -1 "Fechar ?"
```

* * *

# Superficies

É uma visualização de curvas planas . splot

![image.png](assets/4e5903808ce353a7ceefd68b9cafbc163eab2a69fcb362cae0fc18ffdd697c5f.png)

```
reset
set grid
set format z "%4.2f"
f(x,y)=log(sqrt ( x*x + y*y) )
splot f(x,y)
```

![image.png](assets/5197ed377237993313ec39a6fdac2ad2380be0a2c1587fa3ff17e79ce96c6c2f.png)

* * *

# Acentuação em portugues

```
set encoding utf8
```

qualquer coisa a mais → help encoding