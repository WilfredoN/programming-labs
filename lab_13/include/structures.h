#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_SERVICE_NAME_LENGTH 50
#define MAX_SERVICES_AMOUNT 10

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
} owner_t;

typedef struct
{
    char name[MAX_SERVICE_NAME_LENGTH];
    float price;
} service_t;

typedef struct
{
    char brand[MAX_NAME_LENGTH];
    char model[MAX_NAME_LENGTH];
    int year;
    owner_t owner;
    service_t services[MAX_SERVICES_AMOUNT];
    int length;
} vehicle_t;

typedef struct node_t
{
    vehicle_t data;
    struct node_t *next;
    struct node_t *prev;
} node_t;

typedef struct forward_list_t
{
    node_t *head;
    node_t *tail;
} forward_list_t;