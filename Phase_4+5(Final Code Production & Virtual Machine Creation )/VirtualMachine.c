#include "Phase5.h"

int arraysOrInstr=0;
instruction* instructions = NULL;
unsigned totalinstr = 0;
unsigned int currInstr = 0;
unsigned int currProsQuad = 0;

void initializeStringsArray(int counter){
    int i;
    stringConsts = (char**)malloc(counter*sizeof(char*));
    for(i = 0; i < counter; i++){
        stringConsts[i] = NULL;
    }
}

void initializeNumbersArray(int counter){
    int i;
    numConsts = (double*)malloc(counter*sizeof(double));
    for(i = 0; i < counter; i++){
        numConsts[i] = 0;
    }
}

void initializeUserFuncsArray(int counter){
    userFuncs = (userfunc*)malloc(counter*sizeof(userfunc));
}

void initializeLibFuncsArray(int counter){
    int i;
    namedLibfuncs = (char**)malloc(counter*sizeof(char*));
    for(i = 0; i < counter; i++){
        namedLibfuncs[i] = NULL;
    }
}

void insertString(char *s,int index){
    stringConsts[index]=strdup(s);
}

void insertNumber(double s,int index){
    numConsts[index]=s;
}

void insertUserFunc(int address,int localsize,char *name,int index){

    userFuncs[index].address    = address;
    userFuncs[index].localsize  = localsize;
    userFuncs[index].id         = strdup(name);
}

void insertLibFuncs(char *s,int index){
    namedLibfuncs[index]=strdup(s);
}

void expand_Instruction(void){
    assert(totalinstr == currInstr);
    instruction* t = (instruction*) malloc(NEW_INST_SIZE);

    if(code){
        memcpy(t ,  code , CURR_INST_SIZE);
        free(code);
    }

    code = t;
    totalinstr += EXPAND_SIZE;
}

void emit_instruction(instruction* i){
    if(currInstr == totalinstr) expand_Instruction();

    instruction* t = code + currInstr++;
    t->opcode = i->opcode;
    t->result = i->result;
    t->arg1 = i->arg1;
    t->arg2 = i->arg2;
    t->lineno = i->lineno;
    t->label = i->label - 1;
}

int main(){
    //---------------5h fash!!!!!!!!!!!--------------------------
    avm_initialize();
    FILE *finput;
    finput=fopen("binary.bin","r");
    char line[300];

    if(finput==NULL){
        printf("Den yparxei to binary.bin magka\n");
        return 0;
    }

    int counter,i;
    int globals = 0;
    char colon[50];

    while(fgets(line,sizeof(line),finput)){
        char data[300];
        if(sscanf(line , "%d %s %s\n" , &counter ,colon,data)==EOF){
            //printf("Error in binary.bin\n");
        }
        else{
            if(arraysOrInstr==0){
                //printf("V:%d,%s,%s\n",counter,colon,data);
                if(strcmp(data ,"Globals") == 0) {
                    int val;
                    sscanf(line , "%d %s %d\n" , &globals ,colon, &val);
                }
                else if(strcmp(data ,"Strings") == 0){
                    initializeStringsArray(counter);
                    totalStringConsts = counter;
                    int index,val;
                    for(i = 0; i < counter; i++){
                        if( fgets(line,sizeof(line),finput) ){
                            index=i;
                            int k = 0;
                            while(line[k] != ' ') { k++; }
                            strcpy(data, &line[k + 3]);
                            // sscanf(line,"%d %s %s\n",&index,colon,data);
                            insertString(data,index);
                        }
                    }
                }
                else if((strcmp(data ,"Numbers") == 0)){
                    initializeNumbersArray(counter);
                    totalNumConsts=counter;
                    int index;
                    float val;
                    for(i = 0; i < counter; i++){
                        if( fgets(line,sizeof(line),finput) ){
                            sscanf(line , "%d %s %f\n" , &index ,colon, &val);
                            insertNumber(val,index);
                        }
                    }
                }
                else if((strcmp(data ,"UserFuncs") == 0)){
                    initializeUserFuncsArray(counter);
                    totalUserFuncs=counter;
                    int index,address,totallocals;
                    for(i = 0; i < counter; i++){
                        if(fgets(line, sizeof(line) , finput)){
                            sscanf(line , "%d %s %d,%d,%s\n" , &index , colon, &address , &totallocals ,data);
                            insertUserFunc(address , totallocals , data , index);
                        }
                    }
                }
                else if((strcmp(data ,"LibFuncs") == 0)){
                    initializeLibFuncsArray(counter);
                    totalNamedLibfuncs = counter;
                    int index;
                    for(i = 0; i < counter; i++){
                        if(fgets(line, sizeof(line) , finput)){
                            sscanf(line , "%d %s %s\n" , &index ,colon, data);
                            insertLibFuncs(data , index);
                        }
                    }
                }
                else if(strcmp(data,"InstructionsCode")==0){
                    sscanf(line , "%d %s" , &codeSize,data);
                }
                else if(strcmp(data,"TheEnd")==0){
                     arraysOrInstr=1;
                }
                else{
                    vmarg result,arg1,arg2;
                    int op,label,res_type,arg1_type,arg2_type;

                    instruction* t = (instruction*)malloc(sizeof(instruction));
                    t->result = (vmarg*)malloc(sizeof(vmarg));
                    t->arg1 = (vmarg*)malloc(sizeof(vmarg));
                    t->arg2 = (vmarg*)malloc(sizeof(vmarg));

                    sscanf(line,"%d(%d),%d  (%d)%d  (%d),%d  %d\n"
                    ,&op
                    ,&res_type,&result.val
                    ,&arg1_type,&arg1.val
                    ,&arg2_type,&arg2.val
                    ,&label);

                    t->opcode       = op;
                    t->result->type = res_type;
                    t->result->val  = result.val;
                    t->arg1->type =   arg1_type;
                    t->arg1->val  =   arg1.val;
                    t->arg2->type =   arg2_type;
                    t->arg2->val  =   arg2.val;
                    t->label      =   label;

                    printf("Binary : %d(%d),%d  (%d)%d  (%d),%d  %d\n",t->opcode
                    ,t->result->type,t->result->val
                    ,t->arg1->type,t->arg1->val
                    ,t->arg2->type,t->arg2->val
                    ,t->label);


                    emit_instruction(t);

                }
            }
        }
        
    }

    int k=0;
    printf("-----NUMBER-----\n");
    for(k=0;k<totalNumConsts;k++){
        printf("%d : %f \n",k,numConsts[k]);
    }
    printf("-----STRINGS-----\n");
    for(k=0;k<totalStringConsts;k++){
        printf("%d : %s \n",k,stringConsts[k]);
    }
    printf("-----USERFUNC-----\n");
    for(k=0;k<totalUserFuncs;k++){
        printf("%d : %d %d %s \n",k,userFuncs[k].address,userFuncs[k].localsize,userFuncs[k].id);
    }
    printf("-----LIBFUNC-----\n");
    for(k=0;k<totalNamedLibfuncs;k++){
        printf("%d : %s \n",k,namedLibfuncs[k]);
    }
    printf("--------------- AVM START---------------\n");

    top = AVM_STACKSIZE -1 - globals;
    topsp = top;

    while(executionFinished != 1){
        execute_cycle();
    }
    
    printf("--------------- AVM END ---------------\n");
    // int k2;
    // for(k2=0;k2<AVM_STACKSIZE;k2++){
    //     if(stack!=NULL && (stack[k2].data.strVal)!=NULL);
    //     printf("Stack : %s",stack[k2].data.strVal);
    // }

    //printf("Stack : %d",stack[4093].data.numVal);
    
    return 0;
}
