#ifndef MINHA_BIBLIOTECA_HPP
#define MINHA_BIBLIOTECA_HPP

// === TEXTO E STRINGS ===
#include <string>         // Para std::string (textos)
#include <string_view>    // Para std::string_view (visualização de texto leve - C++17)

// === COLEÇÕES E ARRAYS (CONTAINERS) ===
#include <vector>         // Para std::vector (arrays dinâmicos)
#include <array>          // Para std::array (arrays de tamanho fixo)
#include <list>           // Para std::list (lista duplamente encadeada)
#include <map>            // Para std::map (dicionários chave-valor ordenados)
#include <unordered_map>  // Para std::unordered_map (tabela hash rápida)
#include <set>            // Para std::set (conjuntos de elementos únicos)

// === MATEMÁTICA E TIPOS DE DADOS ===
#include <cstdint>        // Para tipos com tamanho fixo (int32_t, uint64_t)
#include <cmath>          // Para funções matemáticas (pow, sqrt, sin)
#include <numeric>        // Para operações numéricas em lote (std::accumulate)

// === ENTRADA, SAÍDA E ARQUIVOS ===
#include <iostream>       // Para std::cout, std::cin, std::endl
#include <fstream>        // Para std::ifstream e std::ofstream (ler/escrever arquivos)
#include <sstream>        // Para std::stringstream (manipular strings como fluxos)

// === COMPORTAMENTOS, ERROS E MEMÓRIA ===
#include <algorithm>      // Para std::sort, std::find, std::reverse
#include <memory>         // Para ponteiros inteligentes (std::unique_ptr, std::shared_ptr)
#include <stdexcept>      // Para tratamento de erros e exceções (std::runtime_error)
#include <utility>        // Para utilitários gerais como std::pair e std::move
#include <chrono>         // Para medição de tempo e relógios (std::chrono)



#endif // MINHA_BIBLIOTECA_HPP