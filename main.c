#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*
//Pangrams:
int main () {
    char *potentialPangramString = malloc(1001*sizeof(char));
    scanf("%1000[^\n]",potentialPangramString);
    
    int *alphabetArray = calloc(26,sizeof(int));
    
    for (int potentialPangramString_i = 0 ; potentialPangramString_i < strlen(potentialPangramString); potentialPangramString_i++){
        int index = tolower(potentialPangramString[potentialPangramString_i]) - 'a';
        alphabetArray[index]++;
    }
    
    int isPangram = 1;
    for (int alphabetArray_i = 0; alphabetArray_i < 26 && isPangram == 1; alphabetArray_i++) {
        if (alphabetArray[alphabetArray_i] == 0) {
            isPangram = -1;
        }
    }
    printf(isPangram == 1 ? "pangram" : "not pangram");
    free(alphabetArray);
    return 0;
} */


/*
//Weighted Uniform Strings:
int main () {
    char *s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    int n;
    scanf("%d",&n);
    
    int *alphabetArray = calloc(26,sizeof(int));
    alphabetArray[s[0]-'a'] = 1;
    int current = s[0];
    int currentCount = 1;
    for (int s_i = 1; s_i <= strlen(s); s_i++) {
        if (s[s_i] == current) {
            currentCount++;
        } else {
            if (alphabetArray[s[s_i-1]-'a'] < currentCount) {
                alphabetArray[s[s_i-1]-'a'] = currentCount;
            }
            current = s[s_i];
            currentCount = 1;
        }
    }
    //Flush last values of current and current Count if needed
    if (alphabetArray[s[strlen(s)-1]-'a'] < currentCount) {
        alphabetArray[s[strlen(s)-1]-'a'] = currentCount;
    }
    
    //Debug:
    for (int x_i = 0; x_i < 26; x_i++) {
        printf("[%c->%d->%d]\n",'a'+x_i,x_i+1,alphabetArray[x_i]);
    }
    
    
    for(int a0 = 0; a0 < n; a0++){
        long long x;
        scanf("%lld",&x);
        int isFound = -1;
        for (long long x_i = 1; x_i <= 26 && isFound == -1; x_i++) {
            long long max = alphabetArray[x_i-1]*(x_i);
            if (x%(x_i)== 0 && x <= alphabetArray[x_i-1]*(x_i)) {
                isFound = 1;
            }
        }
        //printf("%d",a0+1);
        printf(isFound == 1 ? "Yes\n" : "No\n");
    }
    free(alphabetArray);
    return 0;
} */


/*
//Funny String
int funnyString(char* s){
    int isFunny = 1;
    for (int i = 1; i < strlen(s) && isFunny == 1; i++) {
        //Debug: printf("front: (%c,%c)\nback: (%c,%c)\n",s[i],s[i-1],s[strlen(s)-i],s[strlen(s)-i-1]);
        if (abs(s[i]-s[i-1]) != abs(s[strlen(s)-i]-s[strlen(s)-1-i])) {
            isFunny = -1;
        }
    }
    return isFunny;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char *s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result_size;
        int result = funnyString(s);
        printf("%s", result == 1 ? "Funny" : "Not Funny");
        printf("\n");
    }
    return 0;
} */


/*
//Gemstones
int gemstones(int arr_size, char** arr){
    int *alphabetArray = calloc(26,sizeof(int));
    for (int i = 0; i < arr_size; i++) {
        for(int str_i = 0; str_i < strlen(arr[i]); str_i++){
            if (alphabetArray[arr[i][str_i]-'a'] == i){
                alphabetArray[arr[i][str_i] - 'a']++;
            }
        }
    }
    
    int gemstones = 0;
    for (int alphabetArray_i = 0; alphabetArray_i < 26; alphabetArray_i++){
        if(alphabetArray[alphabetArray_i] == arr_size){
            gemstones++;
        }
    }
    return gemstones;
}

int main() {
    int n;
    scanf("%i", &n);
    char* *arr = malloc(sizeof(char*) * n);
    for(int arr_i = 0; arr_i < n; arr_i++){
        arr[arr_i] = (char *)malloc(10240 * sizeof(char));
        scanf("%s",arr[arr_i]);
    }
    int result = gemstones(n,arr);
    printf("%d\n", result);
    return 0;
} */


/*
//Alternating Characters
int alternatingCharacters(char* s){
    int current = s[0];
    int change = 0;
    for (int s_i = 1; s_i < strlen(s); s++){
        if (current == s[s_i]){
            change++;
        } else {
            current = s[s_i];
        }
    }
    return change;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = alternatingCharacters(s);
        printf("%d\n", result);
    }
    return 0;
} */


/*
//Beautiful Binary String
int minSteps(int n, char* B) {
    char dirty[4] = "010";
    char buffer[4];
    int numberOfDirtyFound = 0;
    for (int B_i = 0; B_i < n;) {
        memcpy(buffer,&B[B_i],3);
        //Debug: printf("%s\n",buffer);
        if (strcmp(buffer,dirty) == 0) {
            B_i+=3;
            numberOfDirtyFound++;
        } else {
            B_i++;
        }
    }
    return numberOfDirtyFound;
}

int main() {
    int n;
    scanf("%d",&n);
    char* B = (char *)malloc(512000 * sizeof(char));
    scanf("%s",B);
    int result = minSteps(n, B);
    printf("%d\n", result);
    return 0;
} */


/*
//The Love-Letter Mystery
int theLoveLetterMystery(char* s) {
    int reductions = 0;
    for (int s_i = 0; s_i < strlen(s)/2; s_i++) {
        reductions += abs(s[s_i] - s[strlen(s)-1-s_i]);
    }
    return reductions;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = theLoveLetterMystery(s);
        printf("%d\n", result);
    }
    return 0;
} */


/*
//Palindrome Index
int palindromeIndex(char* s){
    int index = -1;
    for (int s_i = 0; s_i < strlen(s)/2 && index == -1;s_i++){
        if (s[s_i] != s[strlen(s)-s_i-1]) {
            if (s[s_i] == s[strlen(s)-s_i-2] && s[s_i+1] == s[strlen(s)-s_i-3]) {
                index = strlen(s)-s_i-1;
            } else {
                index = s_i;
            }
        }
    }
    return index;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = palindromeIndex(s);
        printf("%d\n", result);
    }
    return 0;
} */


/*
//Anagram
int anagram(char* s){
    if (strlen(s)%2 == 1){
        return -1;
    }
    
    int change = 0;
    int *alphabetTable = calloc(26,sizeof(int));
    for (int s_i = 0; s_i < strlen(s)/2; s_i++){
        alphabetTable[s[s_i]-'a']++;
        alphabetTable[s[strlen(s)-1-s_i]-'a']--;
    }
    
    for (int i = 0; i < 26; i++){
        if (alphabetTable[i] > 0){
            change+=alphabetTable[i];
        }
    }
    
    free(alphabetTable);
    return change;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = anagram(s);
        printf("%d\n", result);
    }
    return 0;
 } */


/*
//Making Anagrams
int makingAnagrams(char* s1, char* s2){
    int deletions = 0;
    int *alphabetTable = calloc(26,sizeof(int));
    
    for (int i = 0; i < strlen(s1); i++) {
        alphabetTable[s1[i]-'a']++;
    }
    
    
    for (int i = 0; i < 26; i++) {
        printf("(%c:%d)\n",i+'a',alphabetTable[i]);
    }
    
    for (int i = 0; i < strlen(s2); i++){
        alphabetTable[s2[i]-'a']--;
    }
    
    //Debug printf("--------------------------\n");
    for (int i = 0; i < 26; i++) {
        printf("(%c:%d)\n",i+'a',alphabetTable[i]);
    }
    
    for (int i = 0; i < 26; i++) {
        deletions+=abs(alphabetTable[i]);
    }
    free(alphabetTable);
    return deletions;
}

int main() {
    char* s1 = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s1);
    char* s2 = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s2);
    int result = makingAnagrams(s1, s2);
    printf("%d\n", result);
    return 0;
} */

/*
//Two Strings
int twoStrings(char* s1, char* s2){
    int isFound = -1;
    int *alphabetTable = calloc(26,sizeof(int));
    int lettersFilled = 0;
    
    for (int i = 0; i < strlen(s1) && lettersFilled < 26; i++) {
        if (alphabetTable[s1[i]-'a'] == 0) {
            lettersFilled++;
        }
        alphabetTable[s1[i]-'a']++;
    }
    
    for (int i = 0; i < strlen(s2) && isFound == -1; i++) {
        if (alphabetTable[s2[i]-'a'] > 0) {
            isFound = 1;
        }
    }
    free(alphabetTable);
    return isFound;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s1 = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s1);
        char* s2 = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s2);
        int result_size;
        int result = twoStrings(s1, s2);
        printf("%s\n", result == -1 ? "NO" : "YES");
    }
    return 0;
} */


/*
//Game of Thrones - I
int gameOfThrones(char* s){
    int isPalindrome = -1;
    int isOddAmountOfLetterAlreadyFound = 0;
    int *alphabetTable = calloc(26,sizeof(int));
    
    for (int i = 0; i < strlen(s); i++) {
        alphabetTable[s[i]-'a']++;
    }
    
    for (int i = 0; i < 26 && isPalindrome == -1; i++) {
        if (isOddAmountOfLetterAlreadyFound == 2) {
            isPalindrome = 1;
        }
        
        if (alphabetTable[i]%2==1) {
            isOddAmountOfLetterAlreadyFound++;
        }
    }
    free(alphabetTable);
    return isPalindrome;
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size;
    int result = gameOfThrones(s);
    printf("%s\n", result == 1 ? "NO" : "YES");
    return 0;
} */


/*
//String Construction
int stringConstruction(char* s) {
    int *alphabetTable = calloc(26,sizeof(int));
    int cost = 0;
    for (int i = 0; i < strlen(s); i++){
        if (alphabetTable[s[i]-'a'] == 0) {
            cost++;
        }
        alphabetTable[s[i]-'a']++;
    }
    free(alphabetTable);
    return cost;
}

int main() {
    int q;
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = stringConstruction(s);
        printf("%d\n", result);
    }
    return 0;
} */


/*
//Sherlock and the Valid Strings
int isValid(char* s){
    int isValid = 1;
    int *alphabetTable = calloc(26,sizeof(int));
    for (int i = 0; i < strlen(s); i++){
        alphabetTable[s[i]-'a']++;
    }
    int replicas = -1;
    int isExtraFound = -1;
    int matched = -1;
    for (int i = 0; i < 26 && isValid == 1 && isExtraFound <= 0; i++) {
        if (replicas == -1 && alphabetTable[i] > 0) {
            replicas = alphabetTable[i];
        } else {
            if (replicas == alphabetTable[i] && matched == -1){
                matched = 1;
            }
            if (replicas - 1 == alphabetTable[i] || replicas == alphabetTable[i] - 1) {
                isExtraFound++;
                if (replicas - 1 == alphabetTable[i] && matched == -1) {
                    replicas = alphabetTable[i];
                }
            }
            
            if (replicas < alphabetTable[i] - 1 || isExtraFound > 0) {
                isValid = -1;
            }
            
        }
    }
    free(alphabetTable);
    return isValid;
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size;
    int result = isValid(s);
    printf("%s\n", result == 1 ? "YES" : "NO");
    return 0;
} */


/* 
//Richie Rich
void richieRich(char** s, int n, int* k) {
    int *sMarked = calloc(strlen(*s)/2+1,sizeof(int));
    for (int i = 0; i < strlen(*s)/2 && *k >= 0; i++) {
        if ((*s)[i] != (*s)[strlen(*s)-1-i]){
            (*k)--;
            if (*k >= 0){
                int first = (*s)[i] - '0';
                int second = (*s)[strlen(*s)-1-i] - '0';
                if (first > second){
                    (*s)[strlen(*s)-1-i] = (*s)[i];
                } else {
                    (*s)[i] = (*s)[strlen(*s)-1-i];
                }
                sMarked[i]++;
            }
        }
    }
    
    int y = 0;
    while (*k > 0 && y <= strlen(*s)/2) {
        if (sMarked[y] > 0) {
            if ((*s)[y] != '9') {
                (*k)--;
                (*s)[y] = '9';
                (*s)[strlen(*s)-1-y] = '9';
            }
        } else {
            if (*k == 1) {
                if (strlen(*s) % 2 == 1) {
                    (*s)[strlen(*s)/2] = '9';
                }
            } else {
                if ((*s)[y] != '9') {
                    if ((*s)[y] != '9') {
                        (*s)[y] = '9';
                        (*k)--;
                    }
                }
                
                if ((*s)[strlen(*s)-1-y] != '9') {
                    if ((*s)[strlen(*s)-1-y] != '9') {
                        (*s)[strlen(*s)-1-y] = '9';
                        (*k)--;
                    }
                    
                }
            }
        }
        y++;
    }
}

int main() {
    int n;
    scanf("%i", &n);
    int k;
    scanf("%i", &k);
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size;
    richieRich(&s, n, &k);
    printf("%s\n", k == -1 ? "-1" : s);
    return 0;
} */


/*
//Counting Sort I
int main() {
    int n;
    scanf("%d",&n);
    
    int input;
    int *countedSortArray = calloc(99,sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d",&input);
        countedSortArray[input]++;
    }
    
    for (int i = 0; i < 99; i++) {
        printf("%d ", countedSortArray[i]);
    }
    
    return 0;
} */


/*
//Counting Sort II
int main() {
    int n;
    scanf("%d",&n);
    
    int input;
    int *countedSortArray = calloc(99,sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d",&input);
        countedSortArray[input]++;
    }
    
    for (int i = 0; i <= 99; i++) {
        for (int j = 0; j < countedSortArray[i]; j++) {
            printf("%d ", i);
        }
    }
    return 0;
} */


//The Full Counting Sort
int main() {
    
    
    return 0;
}
