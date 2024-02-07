//structs

typedef struct
{
        int year;
        int month;
        int day;
                         //struct #1
        int hour;
        int minute;
        int second;

} dateTime;

typedef struct
{
        int like;
        int love;
        int wow;
        int haha;       //struct #2
        int sad;
        int angry;

} reactions;

typedef struct trumpPost
{
        char *text;
        char *info;
        char *type;
        char *link;

        dateTime posted;
        reactions feelings;    //struct #3 (main)

        int react;
        int comment;
        int share;

        char learnedFrom[5];
        struct trumpPost *next;
        struct trumpPost *prev;
} post;

//dhlwseis protupwn sunartisewn

void NewPost(void);

void OldPost(void);

void Count(int c);

void TypeCount(char c);

void FindTIL(void);

void PrintAB(void);

void Print_R(int reps);

void DeleteNO(void);

void Save(void);

void Load(void);

int ONPostCheck(void);

//ka8olikes metablhtes

struct trumpPost *head=NULL, *tail=NULL;

char text[5000],*array[50],*DateTime[6];

int dtime[6],reaction,comments,shares,likes,loves,wows,hahas,sads,angrys;

int lentext,leninfo,lentype,lenlink,PostSave;

FILE *fp;
