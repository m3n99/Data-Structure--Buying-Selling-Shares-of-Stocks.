#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct date { ///Struct for Date
    int day;
    char month[20];

};
typedef struct link { ///struct for Stack and Queue
    int pricepershare;
    int numofshares;
    char company[20];
    struct date DATE;
    struct qlink *next;
} qlink;

FILE *in_f; //define for file
qlink *bts; // original linked list
qlink *top = NULL;//for stack
qlink *rar = NULL; //for queue
qlink *fr = NULL;//for queue

void read() { //Function to read from file and fill linked list
    in_f = fopen("shares.txt", "r"); // read only
    int pricepershare, numofshares;
    char company[20];
    int day;
    char month[20];
    qlink *ptr;
    if (in_f == NULL) {
        printf("Error! there is no file\n");
        exit(-1);
    } else {
        while (fscanf(in_f, " %d;%d;%[^;]%*c%d/%s ", &numofshares, &pricepershare, &company, &day, &month) != EOF) {
            qlink *o = malloc(sizeof(qlink));
            o->next = NULL;
            o->numofshares = numofshares;
            o->pricepershare = pricepershare;
            strcpy(o->company, company);
            o->DATE.day = day;
            strcpy((o->DATE.month), month);
            ptr = bts;
            while (ptr->next != NULL) {
                ptr = (qlink *) ptr->next;

            }
            ptr->next = (struct dlink *) o;
        }

    }
    printf(" Read is Successfully\n");

}

void buy_shares() {//Function to buy shares and store in file
    qlink *b;
    b = bts;
    int pricepershare, numofshares;
    char company[20];
    int day;
    char month[20];

    printf("\nEnter the name of the company : ");
    scanf("%s", &company);
    do{
    printf("Enter the number of shares : ");
    scanf("%d", &numofshares);
    printf("Enter the price of shares : ");
    scanf("%d", &pricepershare);
    printf("Enter the Date (day month) : ");
    scanf("%d %s", &day, month);
    if(pricepershare <0 || numofshares <0 || day <0)
        printf("\nEnter some positive value\n ");} while(pricepershare <0 || numofshares <0 || day <0);

    while (b->next) {
        b = (qlink *) b->next;

    }
    qlink *o = malloc(sizeof(qlink));
    o->next = NULL;
    b->next = (struct dlink *) o;
    o->numofshares = numofshares;
    o->pricepershare = pricepershare;
    strcpy(o->company, company);
    o->DATE.day = day;
    strcpy((o->DATE.month), month);


}

void print(int choose) { // function update and print list

    if (choose != 1) {
        in_f = fopen("shares.txt", "w"); // read only
    }
    qlink *a;
    a = bts;
    while (a->next) {
        a = (qlink *) a->next;
        if (choose == 1) {
            printf("%d %d %s %d %s\n", a->numofshares, a->pricepershare, a->company, a->DATE.day, a->DATE.month);
        } else {
            printf("%d %d %s %d %s\n", a->numofshares, a->pricepershare, a->company, a->DATE.day, a->DATE.month);
            fprintf(in_f, "%d;%d;%s;%d/%s\n", a->numofshares, a->pricepershare, a->company, a->DATE.day, a->DATE.month);

        }
    }
}

void push(qlink *s) {  // this function will push to the stack
    qlink *o;
    o = malloc(sizeof(qlink));
    o->next = NULL;
    o->numofshares = s->numofshares;
    o->pricepershare = s->pricepershare;
    strcpy(o->company, s->company);
    o->DATE.day = s->DATE.day;
    strcpy(o->DATE.month, s->DATE.month);
    if (top == NULL) {
        top = o;
    } else {
        o->next = (struct dlink *) top;
        top = o;
    }
}//add to stack
void pop() {  // this function will pop from the stack
    qlink *t;
    if (top == NULL)

        printf("stack is empty\n");
    else {
        t = (qlink *) top->next;
        free(top);
        top = t;
    }
}//remove from the stack
void fillStack() {    // fill the stack
    qlink *r;
    r = bts;
    while (r->next) {
        r = (qlink *) r->next;
        push(r);
    }
    free(bts->next);
    bts->next = NULL;
}

int gainAndLoss(int num, int number, int price) { // Function calculate operation of sell
    num += (number * price);

    return num;
}

int gaining = 0;
int loss = 0;

void totalGain() { // print the gain
    printf("\ntotal gain is :%d$\n", gaining);
}

void totalLoss() { // print the loss
    printf("total loss is :%d$\n", loss);
}


void sellStockAsStack() { // Function to make sell from stack
    fillStack();
    bool flag = false, flag2 = false;
    int x = 0;
    char company[50];
    qlink *u, *pos, *temp = malloc(sizeof(qlink));
    temp->next = NULL;
    int pricepershare, numofshares;
    printf("please enter the company name :");
    scanf("%s", &company);
    printf("please enter the number of shares :");
    scanf("%d", &numofshares);
    printf("please enter the price of share :");
    scanf("%d", &pricepershare);
    int num1 = 0;
    int te = 0;
    int xl = 0;
    while (top) {
        if (strcmpi(company, top->company) == 0) {
            flag = true;
            x++;
            if (te==0)
            te = numofshares - top->numofshares;
            else if (te > 0 && te != top->numofshares)
                numofshares = te;
            else
                numofshares=top->numofshares;

            if (numofshares <= top->numofshares) {
                top->numofshares -= numofshares;
                int price = pricepershare - top->pricepershare;
                xl = gainAndLoss(num1, numofshares, price);

                if (top->numofshares == 0)
                    pop();
                break;
            } else {
                numofshares = te;
                pop();
            }
        } else {
            flag = false;
            u = malloc(sizeof(qlink));
            u->numofshares = top->numofshares;
            u->pricepershare = top->pricepershare;
            strcpy(u->company, top->company);
            strcpy(u->DATE.month, top->DATE.month);
            u->DATE.day = top->DATE.day;
            u->next = temp->next;
            temp->next = (struct qlink *) u;
            pop();
        }
    }
    if (xl > 0)
        flag2 = true;
    if (flag2)
        gaining += xl;
    else
        loss += xl;
    if (flag == false && x == 0) {
        printf("The company doesn't exist\n");
    }
    if (te != 0) {
        printf("\n unsold amount from this company %s is %d shares\n", company, te);
    } else {
        printf("\nsold Successfully\n");
    }
    while (temp->next) {
        temp = (qlink *) temp->next;
        push(temp);
    }
    while (top) {
        pos = malloc(sizeof(qlink));
        pos->numofshares = top->numofshares;
        pos->pricepershare = top->pricepershare;
        strcpy(pos->company, top->company);
        strcpy(pos->DATE.month, top->DATE.month);
        pos->DATE.day = top->DATE.day;
        pos->next = bts->next;
        bts->next= (struct qlink *) pos;
        pop();
    }
}//sell as stack principle
void printStack() {
    qlink *temp = top;
    while (temp) {
        printf("%s  %d \n", temp->company, temp->numofshares);
        temp = (qlink *) temp->next;
    }
}

void enqueue(qlink *s) { //this is a copy  of enqueue i used for some other functions
    qlink *o;
    o = malloc(sizeof(qlink));
    o->next = NULL;
    o->numofshares = s->numofshares;
    o->pricepershare = s->pricepershare;
    strcpy(o->company, s->company);
    o->DATE.day = s->DATE.day;
    strcpy(o->DATE.month, s->DATE.month);
    if (fr == NULL) {
        fr = o;
        rar = o;
    } else {

        rar->next = (struct qlink *) o;
        rar = o;
    }
}//add to queue
void dequeue() {
    qlink *p;
    if (fr == NULL && rar == NULL)
        printf("\t\t\t~ the queue is empty ~\n");
    else {
        if (fr == rar) {
            free(fr);
            fr = NULL;
            rar = NULL;
        } else {
            p = fr;
            fr = (qlink *) fr->next;
        }
    }
}//remove from the queue
void fillQueue() {
    qlink *r;
    r = bts;
    while (r->next) {
        r = (qlink *) r->next;
        enqueue(r);
    }
    free(bts->next);
    bts->next = NULL;
}//fill the queue
void printQueue() {
    qlink *temp = fr;
    while (temp) {
        printf("%s %d\n", temp->company, temp->numofshares);
        temp = (qlink *) temp->next;
    }
}
void sellStockAsQueue() { //Function to see from queue
    fillQueue();
    bool flag = false;  bool flag2 = false;
    int x = 0;
    char company[50];
    qlink *u, *temp = malloc(sizeof(qlink));
    temp->next = NULL;
    int pricepershare, numofshares;
    printf("please enter the company name :");
    scanf("%s", &company);
    printf("please enter the number of shares :");
    scanf("%d", &numofshares);
    printf("please enter the price of share :");
    scanf("%d", &pricepershare);
    int num1 = 0;
    int te = 0;
    int xl = 0;
    while (fr){
        if (strcmpi(company, fr->company) == 0){
             flag = true;
            x++;
             if (te==0)
            te = numofshares - fr->numofshares;
            else if (te > 0 && te != fr->numofshares)
                numofshares = fr;
            else
                numofshares=fr->numofshares;


            if (numofshares <= fr->numofshares) {
                fr->numofshares -= numofshares;
                int price = pricepershare - fr->pricepershare;
                xl = gainAndLoss(num1, numofshares, price);
              if (fr->numofshares == 0)
                    dequeue();
                break;
            } else {
                numofshares = te;
                dequeue();
            }
           if (te<0)
            break;
            else {
                numofshares = te;
                 dequeue();
            }
       }  else {
            flag = false;
            u = malloc(sizeof(qlink));
            u->numofshares = fr->numofshares;
            u->pricepershare = fr->pricepershare;
            strcpy(u->company, fr->company);
            strcpy(u->DATE.month, fr->DATE.month);
            u->DATE.day = fr->DATE.day;
            u->next = NULL;
            qlink *teme = temp;
            while (teme->next) {
                teme = (qlink *) teme->next;
            }
            teme->next = (struct qlink *) u;
            dequeue();
        }
        }

    while (fr) {
        u = malloc(sizeof(qlink));
        u->numofshares = fr->numofshares;
        u->pricepershare = fr->pricepershare;
        strcpy(u->company, fr->company);
        strcpy(u->DATE.month, fr->DATE.month);
        u->DATE.day = fr->DATE.day;
        u->next = NULL;
        qlink *teme = temp;
        while (teme->next) {
            teme = (qlink *) teme->next;
        }
        teme->next = (struct qlink *) u;
        dequeue();

    }

     if (xl > 0)
        flag2 = true;
    if (flag2)
        gaining += xl;
    else
        loss += xl;
    if (flag == false && x == 0) {
        printf("The company doesn't exist\n");
    }
    if (te != 0) {
        printf("\nUnsold Amount from this Company (%s) is: %d Shares\n", company, te);
    } else {
        printf("\nSold Successfully\n");
    }
    while (temp->next) {
        temp = (qlink *) temp->next;
        u = malloc(sizeof(qlink));
        u->numofshares = temp->numofshares;
        u->pricepershare = temp->pricepershare;
        strcpy(u->company, temp->company);
        strcpy(u->DATE.month, temp->DATE.month);
        u->DATE.day = temp->DATE.day;
        u->next = NULL;
        qlink *teme = bts;
        while (teme->next) {
            teme = (qlink *) teme->next;
        }
        teme->next = (struct qlink *) u;
    }
}//sell as queue principle

void menu(){ // Function make main menu
    do{ system ("cls");
    printf("\t\t\t~~~  Maen Khdour     1171944      sec:2  ~~~~~   \n");
    printf("\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t ~  Buying/Selling Shares of Stocks.            ~\n");
    printf("\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n\t\t\t~ please select the number of instruction:~\n");
    printf("\n\n\t\t\t ~ 1 : Read stocks                          ~\n");
    printf("\n\n\t\t\t ~ 2 : Buy Shares                           ~\n");
    printf("\n\n\t\t\t ~ 3 : Sell Shares                          ~\n");
    printf("\n\n\t\t\t ~ 4 : Total capital gain/loss              ~\n");
    printf("\n\n\t\t\t ~ 5 : Update currently held shares         ~\n");
    printf("\n\n\t\t\t ~ 6 : exit                                 ~\n");
    char y;
    printf("\n\t\t\t~ the instruction number is : %c ", y);
    scanf(" %c", &y);
    system ("cls");

    if(y == '1')
    {
        read();
        sleep(1);
    }
    else if(y == '2')
    {
        buy_shares();
        sleep(1);
    }
    else if(y == '3')
    {
        system("cls");
        sellmenu();
    }
    else if(y == '4')
      {
        totalGain();
        totalLoss();
        int x= gaining + loss;
        if(x>0){
            printf("\nThe Total Profit is:%d$\n",x );
            printf("\nGood You'r Gaining\n");
        }
        else if(x<0){
            printf("\nThe Total Profit is:%d$\n",x );
            printf("\nSorry You'r losing\n");
        }
        else{
             printf("\nSorry You'r not Gain anything, you back your Money\n");
        }

        sleep (3);
    }
    else if(y== '5'){
       print(2);

    }
    else if(y== '6')
    {
         exit(0);

    }
    else {
        menu();
    }
    }while (1);
}

void sellmenu() //Function make menu for sell only
{ do {
    printf("\t\t\t ~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t ~   sell menu    ~\n");
    printf("\t\t\t ~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t~ please select the instruction letter ~\n");
    printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\t  ~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t  ~ 1 Sell old shares ~\n");
    printf("\t\t\t  ~ 2 Sell new shares ~\n");
    printf("\t\t\t  ~ 3 return back     ~\n");
    printf("\t\t\t  ~~~~~~~~~~~~~~~~~~~~~\n");
    char t;
    printf("\n~ instruction letter  is : %c  ", t);
    scanf(" %c", &t);

    if(t == '1')
    {
         sellStockAsQueue();

    }
    else if(t == '2')
    {
        sellStockAsStack();
         }
    else if(t == '3')
    {

        menu();
    }
    else
    {
        sellmenu();
    }
}while (1);
}


