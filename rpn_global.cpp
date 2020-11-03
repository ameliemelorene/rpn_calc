# include <iostream>

bool is_operande(char* token) {
    return ((token[0] >= '0') and (token[0] <= '9'));
}

void push (int tab[],int token2,int* adrtop) {
    tab[*adrtop +1] = token2;
    *adrtop = *adrtop + 1;
}

int pop (int tab[],int* adrtop) {
    *adrtop = *adrtop -1;
    return tab[*adrtop +1];
}
int* init_stack(int n){
    int* tab= new int[n];
    return tab;
}

void delete_stack(int* tab){
    delete [] tab;
}
void print_stack(int* adrtop,int* tab){

    for (int i=0; i < *adrtop +1; i++) {
            std::cout << tab[i] << ' ' ;
        }
    std::cout <<'\n';
    }

int rpn_eval (int n,char* tabE[]) { 
    int* tab=init_stack(n);
    int top = -1;
    int* adrtop = &top;
    for (int i=1; i<n; i++) {
        if (is_operande(tabE[i]) == 1) {
            push (tab, atoi(tabE[i]), adrtop);
        }
        else if ((is_operande(tabE[i]) == 0) and (tabE[i][0] == '!')) {
            int nouveau = - pop (tab, adrtop);
            push (tab, nouveau, adrtop);
        }
        else if ((is_operande(tabE[i]) == 0) and (tabE[i][0] != '!')) {
            int nouveau = pop (tab,adrtop);
            int nouveau2 = pop (tab,adrtop);

            if (tabE[i][0] == '+') {
                int valeur = nouveau + nouveau2; 
                push (tab, valeur, adrtop);
            }
            else if (tabE[i][0] == '-') {
                int valeur = nouveau2 - nouveau; 
                push (tab, valeur , adrtop);
            }
            else if (tabE[i][0] == 'x') {
                int valeur = nouveau * nouveau2; 
                push (tab, valeur, adrtop);
            }
            else if (tabE[i][0] == '/') {
                int valeur = nouveau2 / nouveau; 
                push (tab, valeur , adrtop);
                }
            }
        print_stack(adrtop,tab);
        }
    
    int valeur=tab[0];
    delete_stack(tab);
    return valeur;
    }

int main (int argc, char* argv[]) {
    std::cout << rpn_eval(argc, argv) << '\n';
 
    return 0;
}
