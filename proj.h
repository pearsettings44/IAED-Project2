#ifndef MAIN_H
#define MAIN_H

/* primeiro projeto de IAED
 * autor: José Pereira - ist1103252
 */

#define MAX_NUM_AEROPORTOS 40 /* número máximo de areoportos */
#define MAX_NUM_VOOS 30000    /* número máximo de voos */

#define MAX_CODIGO_AEROPORTO 4 /* dimensão do código do aeroporto */
#define MAX_NOME_PAIS 31       /* dimensão do nome do pais */
#define MAX_NOME_CIDADE 51     /* dimensão do nome da cidade */

#define MAX_CODIGO_VOO 7 /* dimensão do código do voo */
#define MAX_DATA 11      /* dimensão da data */
#define MAX_HORA 6       /* dimensão da hora */

#define NAO_EXISTE -1 /* código de erro */

#define ANO_INICIO 2022  /* ano inicial do sistema */
#define DIAS_ANO 365     /* número de dias no ano */
#define HORAS_DIA 24     /* número de horas por dia */
#define MINUTOS_HORA 60  /* número de minutos numa hora */
#define MINUTOS_DIA 1440 /* número de minutos do dia */

#define TRUE 1  /* verdadeiro */
#define FALSE 0 /* falso */

#define MAX_CHAR 65535 /* Numero máximo de caracteres de uma instrução */

#define MIN_IDRESERVA 10 /* Numero minimo de caracteres de um id de Reserva */

#define NO_MEMORY "No memory.\n" /* Erro de memoria insuficiente */

#define ERROR_NOT_FOUND "not found\n"                               /* Erro not found */
#define ERROR_TO_MANY_RESERVATIONS "too many reservations\n"        /* Erro too many reservations */
#define ERROR_ALREADY_USED "%s: flight reservation already used\n"  /* Erro flight reservation already used */
#define ERROR_INVALID_PASSENGER_NUMBER "invalid passenger number\n" /* Erro invalid passenger number */
#define ERROR_INVALID_DATE "invalid date\n"                         /* Erro invalid date */
#define ERROR_FLIGHT_DOES_NOT_EXIST "%s: flight does not exist\n"   /* Erro flight does not exist */
#define ERROR_INVALID_CODE "invalid reservation code\n"             /* Erro invalid reservation code */
/* Tipos de Dados */

typedef struct
{
    char id[MAX_CODIGO_AEROPORTO];
    char pais[MAX_NOME_PAIS];
    char cidade[MAX_NOME_CIDADE];
    int numVoos;
} Aeroporto;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int hora;
    int minuto;
} Hora;

typedef struct
{
    char id[MAX_CODIGO_VOO];
    char partida[MAX_CODIGO_AEROPORTO];
    char chegada[MAX_CODIGO_AEROPORTO];
    Data data;
    Hora hora;
    Hora duracao;
    int capacidade;
    int ocupacao;
    int horaPartida;
    int horaChegada;
    int numReservas;
} Voo;

struct reserva
{
    char idVoo[MAX_CODIGO_VOO];
    Data data;
    char *idReserva;
    int numPassageiros;
    struct reserva *proximo;
};

typedef struct reserva Reserva;
typedef struct reserva *link;

/* Variaveis Globais */

extern int _numAeroportos;                        /* número de aeroportos introduzidos */
extern Aeroporto _aeroportos[MAX_NUM_AEROPORTOS]; /* vetor de aeroportos */

extern int _numVoos; /* número de voos introduzidos */

extern Voo _voos[MAX_NUM_VOOS]; /* vetor de voos */

extern Data _hoje; /* data atual do sistema */

extern const int _diasMesAc[]; /* dias acumulados por mês (jan=1) */

extern int _numReservas; /* número de reservas introduzidas */

extern link cabeca; /* Cabeça da lista simplesmente ligada */

extern int acontecimento;

/* Funções de leitura */
Hora leHora();
Data leData();
int leProximaPalavra(char str[]);
void lePalavraAteFimDeLinha(char str[]);
void leAteFimDeLinha();

/* Funções de data e hora */
void mostraData(Data d);
void mostraHora(Hora h);
int converteDataNum(Data d);
int converteHoraNum(Hora h);
int converteDataHoraNum(Data d, Hora h);
Hora converteNumHora(int num);
Data converteNumData(int num);
int validaData(Data d);
int validaHora(Hora h);

/* Funções de aeroportos */
int aeroportoInvalido(char id[]);
int encontraAeroporto(char id[]);
void mostraAeroporto(int index);
int cmpAeroportos(int a, int b);
void listaTodosAeroportos();

/* Funções de voos */
void mostraVoo(int index);
void mostraVooPartida(int index);
void mostraVooChegada(int index);
int encontraVoo(char id[], Data);
int validaIDVoo(char id[]);
int validaVoo(Voo v);
void criaVoo(Voo v);
int cmpVoosPartida(int a, int b);
int cmpVoosChegada(int a, int b);
int encontraVooSemData(char id[]);
void apagaVoo(char id[]);
int reservasTotalVoo(char id[]);

/* Função do algoritmo de ordenação BubbleSort */
void bubbleSort(int indexes[], int size, int (*cmpFunc)(int a, int b));

/* Funções da lista simplesmente ligada */
link novo(char *buffer, char idVoo[], Data d, int numPassageiros);
void print(link cabeca, char idVoo[], Data d);
link insereOrdenado(link cabeca, char *idReserva, char idVoo[], Data d,
                    int numPassageiros);
link procura(link cabeca, char *idReserva);
link apaga(link cabeca, char *idReserva);
link procuraApagaIDVoo(link cabeca, char idVoo[]);
void apagaTodasReservas(link cabeca);

/* Funções de reservas */
int validaPassageiros(int numPassageiros);
int validaIdReserva(char idReserva[]);
void adicionaReservaAux(char idReserva[], char idVoo[], Data d,
                        int numPassageiros);
void apagaReserva(char idReserva[]);
#endif