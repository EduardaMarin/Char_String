#include <Arduino.h>
#include <string.h> //*strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //*atoi

void textoChar();
void textoString();

void setup()
{
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop() {}

void textoChar()
{
  // Texto Literal
  // Use const char* quando o texto nao sera alterado
  const char cidade[] = "Sao Paulo"; // esta trabalhando com um endereco de memoria
  Serial.println(cidade);

  // Descobrindo o tamanho do texto
  // Strelen conta quantos caracteres antes do 0
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("comprimetoTexto: ");
  Serial.println(tamanhoTextoCidade);

  // Descobrindo o tmanho ocupado
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaco utilizado: ");
  Serial.println(tamanhoVariavelCidade);

  char vetorTexto[8] = {'E', 'd', 'u', 'a', 'r', 'd', 'a', '\0'};
  Serial.println(vetorTexto);

  //*Comparar texto
  const char* cidade1 = "Sao Caetano";
  const char* cidade2 = "Sao Caetano";

  if (strcmp(cidade1, cidade2) == 0)
  Serial.println("Os textos soa iguais");

  else
  Serial.println("Os textos sao diferentes");

  // strcmp analiza a ordem lexica das palavras, se a primeira palavra vem antes 
  //que a segunda o valor retornado sera menos que zero, se a primeira vem apos
  //a segunda o retorno sera maior que zero

  //! =================================================
  //! TEXTO EDITAVEL COM char[
  //! =================================================

  char nomeAluno[20] = "Eduards";
Serial.println(nomeAluno);

// Alterando caracteres individualmente
nomeAluno[6] = 'a';
Serial.println (nomeAluno);

//Copiando o texto para dentro do vetor
//!Cuidado: o vetor precisa ter espaco suficiente

strcpy(nomeAluno, "Felipe");
Serial.println(nomeAluno);

// Concatenando de texto ao final
char frase[40] = "Ola ";
strcat(frase, "Mundo!");
Serial.println(frase);

// Procurando um caractere no texto
char* posicaoLetra = strchr(frase, 'M');

if(posicaoLetra != NULL)
{
Serial.println("Letra enconrada");
Serial.println(posicaoLetra);
}

else
{
  Serial.println("Letra nao encontrada");
}

// Convertendo texto numerico para inteiro
char idadeTexto[] = "45"; //52, 53, \0
int idade = atoi(idadeTexto);
Serial.println(idade);

}

void textoString()
{
  // ============================================
// USANDO String
// ============================================

String nome = "Eduarda";
String curso = "Desnvolvimento de Sistemas";
String mensagem = "Ola";

// Concatenando String
mensagem = mensagem + "," + nome + "! Bem-vindo ao curso de " + curso + ".";
Serial.println(mensagem);

// Tamanho da String
int tamanhoMensagem = mensagem. length();
Serial.print("Tamanho da String em letras: ");
Serial.println(tamanhoMensagem);

// Acessando um caractere em uma posicao especifica
char primeiraLetra = mensagem.charAt(0);
Serial.print("Primeira Letra: ");
Serial.println(primeiraLetra);

// Tambem e possivel acessar com colchetes
char segundaLetra = mensagem[1];
Serial.println(segundaLetra);

// Procurando um texto dentro da string
int posicaoTextoProcurado = mensagem.indexOf("curso");
Serial.println(posicaoTextoProcurado);

// Extraindo um texto dentro da String
int inicioNomeCurso = posicaoTextoProcurado + 9; //posicao da palavra curso + 9 caracteres
Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1)); // - 1 tira o ponto final

// Substituindo um texto dentro da String
mensagem.replace( "Ola,", "Oi,tudo bom? ");
Serial.println(mensagem);

// Convertendo para maiusculas
mensagem.toUpperCase();
Serial.println(mensagem);

// Convertendo tudo para minusculo
mensagem.toLowerCase();
Serial.println (mensagem);

// Convertendo texto numerico para inteiro
String textoNumero = "123";
int numero = textoNumero.toInt();
Serial.println(numero * 2);

// verificando se a String esta vazia
String textovazio = "";
if(textovazio.length()  == 0) Serial.println("O texto esta vazio");

// Convertendo String para const char*
// Isso e util quando alguma biblioteca espera texto estilo C
const char* textoComoChar =  mensagem.c_str();
Serial.println(textoComoChar);



}