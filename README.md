# KIT SIMOBO – Sistema de Monitoramento e Controle de Nível

Projeto desenvolvido como Trabalho de Conclusão de Curso no Instituto Federal de São Paulo - Campus São José dos Campos, no curso Técnico Integrado em Automação Industrial.

## 👨‍🔧 Autores

- Breno F. Nascimento - SJ3011712  
- Fernando S. Ribeiro - SJ3011313

## 🎯 Objetivo

Criar um kit didático de fácil transporte e baixo custo que permita:
- Monitorar o nível de fluidos em um recipiente.
- Controlar esse nível com o uso de atuadores.
- Exibir os dados em tempo real em um display LCD.
- Visualizar o funcionamento via supervisório.

---

## 🛠️ Componentes Utilizados

| Componente           | Quantidade | Valor Médio |
|----------------------|------------|-------------|
| Sensores Digitais    | 2          | R$ 60       |
| Sensor Ultrassônico  | 1          | R$ 20       |
| Arduino UNO          | 1          | R$ 70       |
| Caixas Plásticas     | 2          | R$ 40       |
| Teclado Matricial    | 1          | R$ 10       |
| Bomba RS-385 12V     | 1          | R$ 45       |
| Módulo Relé          | 1          | R$ 10       |
| **Total**            | **9**      | **R$ 255**  |

---

## 🧪 Funcionalidades

- 📈 **Monitoramento de nível** com sensores boia e ultrassônico.
- 💡 **Exibição em display LCD** do valor atual em porcentagem.
- 🔄 **Controle do nível** com bomba d'água e relé.
- 🧠 **Programação com Arduino** para gerenciamento de sensores e atuadores.

---

## 🖥️ Estrutura do Projeto

### ⚙️ Montagem Física
- Instalação de sensores no recipiente.
- Fiação conectada ao Arduino.
- Caixa com componentes impressa em 3D.
- Base em madeira para melhor fixação.

**Exemplo de montagem:**  
![Instalação dos sensores](https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/sensores.jpg)  
![Sensor ultrassônico instalado]((https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/)sensor_ultrassonico.jpg)  
![Bomba e relé]((https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/)bomba_rele.jpg)  
![Layout final](https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/layout_final.png)

### 💻 Programação

- Lógica para sensores digitais (on/off) e sensor ultrassônico (analógico).
- Cálculo de porcentagem do nível.
- Controle da bomba via botão.
- Exibição de mensagens como “nível crítico” e “nível máximo”.

**Trecho da programação:**  
![Programação 1](https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/programacao1.jpg)  
![Programação 2](https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/programacao2.jpg)
![Programação 3](https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/programacao3.jpg)
![Programação 4](https://github.com/fernandosantos09/simobo/blob/main/PJI/Relat%C3%B3rio/programacao4.jpg)
---

## 📊 Resultados

- Monitoramento em tempo real funcional.
- Controle de nível efetivo com bomba.
- Exibição correta no LCD.
- Estrutura robusta e de fácil transporte.

---

## 📈 Discussões

- Boa relação custo-benefício dos componentes.
- Kit permite modificações futuras e expansão para novos sistemas.
- Possibilita aprendizado teórico e prático em automação.

---

## ✅ Conclusão

O projeto atingiu todos os objetivos propostos, sendo uma solução prática, acessível e didática. Proporciona aprendizado completo sobre sensores, atuadores e programação. O kit está pronto para uso em instituições de ensino e pode ser melhorado continuamente.

---

## 🚀 Sugestões Futuras

- Produção em escala como kit didático para escolas técnicas.
- Integração com sistemas de mistura ou múltiplos tanques.
- Conectividade com interfaces web ou mobile para controle remoto.

---

## 📚 Referências

- Wendling, Marcelo. **Sensores.** UNESP, 2010.
- Patsko, F. **Transdutores e sensores.** 2006.
- Tinkercad. [https://tinkercad.com](https://tinkercad.com)
- Arduino SA. **Documentação oficial.**
- Macedo, J. C. **Sistema de monitoramento do nível de amônia.** UNIFACVEST, 2016.
- E outros autores citados no relatório.

---

## 🏫 Agradecimentos

Aos professores orientadores Valéria Trigueiro, Lucas Furtado e Matheus Mascarenhas.  
Ao IFSP - Campus São José dos Campos, pelo suporte técnico e acadêmico.

---


