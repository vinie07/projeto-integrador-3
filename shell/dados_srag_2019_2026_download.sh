#!/bin/bash
# --- LINKS ---
    # 2019 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2019/INFLUD19-23-03-2026.csv
    # 2020 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2020/INFLUD20-23-03-2026.csv
    # 2021 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2021/INFLUD21-23-03-2026.csv
    # 2022 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2022/INFLUD22-23-03-2026.csv
    # 2023 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2023/INFLUD23-23-03-2026.csv
    # 2024 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2024/INFLUD24-23-03-2026.csv
    # 2025 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2025/INFLUD25-15-06-2026.csv
    # 2026 - https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2026/INFLUD26-15-06-2026.csv
# -------------

# --- LINKS VARIAVEIS ---
ano_2019="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2019/INFLUD19-23-03-2026.csv"
ano_2020="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2020/INFLUD20-23-03-2026.csv"
ano_2021="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2021/INFLUD21-23-03-2026.csv"
ano_2022="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2022/INFLUD22-23-03-2026.csv"
ano_2023="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2023/INFLUD23-23-03-2026.csv"
ano_2024="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2024/INFLUD24-23-03-2026.csv"
ano_2025="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2025/INFLUD25-15-06-2026.csv"
ano_2026="https://s3.sa-east-1.amazonaws.com/ckan.saude.gov.br/SRAG/2026/INFLUD26-15-06-2026.csv"

depois=2019

# --- PARTE 1 - BAIXAR ARQUIVOS ---
# Para baixar , usamos wget/curl , que é unix
    # url = link do proximo indice
    # Na primeira rodada/indice/loop = 2019(contendo o link de 2019)
       for url in "$ano_2019" "$ano_2020" "$ano_2021" "$ano_2022" "$ano_2023" "$ano_2024" "$ano_2025" "$ano_2026"; do
           wget "$url" -O "srag_$depois.csv"
           depois=$(( depois + 1 ))
           echo "[$(date)] Baixando srag_$depois.csv..." >> log.txt
       done
    
# --- PARTE 2 - Juntar sem repetir cabeçalhos --- 
# No primeiro arquivo, pegar o cabeçalho dele
# Depois disso, não é mais necessario pegar pois ja temos o cabeçalho
# Dito isso, pulamos essa linha com -n +2 (pular para 2 linha)
    
   #"INFLUD20-23-03-2019"
    
    #url = contador do anos
    depois=2019
    contador=0 #contador = serve para saber se é o primeiro loop ou nao
    for url in "$ano_2019" "$ano_2020" "$ano_2021" "$ano_2022" "$ano_2023" "$ano_2024" "$ano_2025" "$ano_2026" ;do
        if (( contador==0 )); then
            head -1 srag_$depois.csv > arquivo.csv
        else
            tail -n +2 srag_$depois.csv >> arquivo.csv
        fi
        depois=$(( depois + 1 ))
        contador=$(( contador + 1 ))
        echo "[$(date)] srag_$depois.csv..." >> log.txt
    done

# --- PARTE 3 ---











# --- APRENDIZADOS ---
# 1. variavel SEM ESPAÇO
# 2. declarar variavel sem $ , depois usar $
# 3. wget tem que usar "$", pois ele pensa que ano_x é literalmente ano_x e tente pesquisar
# 4. == 