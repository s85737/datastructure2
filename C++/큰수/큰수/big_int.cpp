
 /*
  programmed by Matthew, CHANG
  www.izect.kr
  matthew.chang@me.com
  */
#include “big_int.h”
 big_int::big_int(){
}
 big_int::big_int(int tNum){
    char *temp_char;
    int len = 0;
    int tNum2 = tNum;
    // 음수 처리
    if(tNum2 < 0) { // Negative
        tNum2 *= -1;
        tNum *= -1;
        bSign = false;
        for(int i = 0 ; ; i++) {
            len++;
            tNum2 /= 10;
            if(tNum2 <= 0) break;
        }
        temp_char = new char[len+1];
        for(int i = 0 ; i < len ; i++) {
            int temp = tNum%10;
            temp_char[i] = temp + ‘0’;
            tNum /= 10;
        }
        temp_char[len] = ‘\0’;
    }else{ // Positive
        bSign = true;
        for(int i = 0 ; ; i++) {
            len++;
            tNum2 /= 10;
            if(tNum2 <= 0) break;
        }
        temp_char = new char[len+1];
        for(int i = 0 ; i < len ; i++) {
            int temp = tNum%10;
            temp_char[i] = temp + ‘0’;
            tNum /= 10;
        }
        temp_char[len] = ‘\0’;
    }
    //
    iLength = (int)strlen(temp_char);
    cDigits = new char[len+1];
    for(int i = 0 ; i < iLength ; i++) {
        cDigits[i] = temp_char[iLength-i-1];
    }
    cDigits[len] = ‘\0’;
}
 big_int::big_int(const char* tChar){
    bool zflag = false;
    int cnt = 0;
    if((int)strlen(tChar) == 1 && tChar[0] == ‘0’) {
        cDigits = new char[1];
        cDigits[0] = ‘0’;
        cDigits[1] = ‘\0’;
    }else if(tChar[0] == ‘-‘){
        bSign = false;
        cnt = 1;
        for(int i = 1 ; ; i++) {
            if(tChar[i] != ‘0’) break;
            cnt++;
        }
        
        cDigits = new char[(int)strlen(tChar) – cnt];
        for(int i = 0 ; i < (int)strlen(tChar) – cnt ; i++) {
            cDigits[i] = tChar[i+cnt];
        }
        cDigits[(int)strlen(tChar) – cnt] = ‘\0’;
        iLength = (int)strlen(cDigits);
    }else{
        bSign = true;
        for(int i = 0 ; ; i++) {
            if(tChar[i] != ‘0’) break;
            cnt++;
        }
        cDigits = new char[(int)strlen(tChar) – cnt];
        for(int i = 0 ; i < (int)strlen(tChar) – cnt ; i++) {
            cDigits[i] = tChar[i+cnt];
        }
        cDigits[(int)strlen(tChar) – cnt] = ‘\0’;
        iLength = (int)strlen(cDigits);
    }
}
 big_int::big_int(const big_int& temp){
    cDigits = new char[temp.iLength];
    bSign = temp.bSign;
    strcpy(cDigits,temp.cDigits);
    iLength = temp.iLength;
}
 big_int::~big_int(){
    strcpy(cDigits,”\0″);
    bSign = true;
    iLength = 0;
}
 big_int& big_int::operator=(const big_int& temp){
    bSign = temp.bSign;
    strcpy(cDigits,temp.cDigits);
    iLength = temp.iLength;
    return *this;
}
 bool operator==(const big_int& orig, const big_int& ext) {
    bool flag = true;
    if(orig.bSign != ext.bSign){
        flag = false;
    }else if(strcmp(orig.cDigits,ext.cDigits)){
        flag = false;
    }else if(orig.iLength != ext.iLength){
        flag = false;
    }
    return flag;
}
 bool operator!=(const big_int& orig, const big_int& ext) {
    bool flag = true;
    if(orig.bSign == ext.bSign){
        flag = false;
    }else if(!strcmp(orig.cDigits,ext.cDigits)){
        flag = false;
    }else if(orig.iLength == ext.iLength){
        flag = false;
    }
    return flag;
}
 bool operator>(const big_int& orig, const big_int& ext) {
    bool flag = true;
    if(orig.bSign == false && ext.bSign == true){ // -orig , +ext
        flag = false;
    }else if(orig.bSign == true && ext.bSign == false){ // +orig , -ext
        flag = true;
    }else if(orig.bSign == true && ext.bSign == true){
        if(orig.iLength > ext.iLength) { // same sign, length is orig > ext
            flag = true;
        }else if(orig.iLength < ext.iLength) { // same sign, length is orig < ext
            flag = false;
        }else{
            if(!strcmp(orig.cDigits,ext.cDigits)){
                flag = false;
            }else{
                for(int i = orig.iLength-1 ; i>=0 ; i–){ // same sign, same length
                    int A = (int)(orig.cDigits[i] – ‘0’);
                    int B = (int)(ext.cDigits[i] – ‘0’);
                    if(A < B) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }else if(orig.bSign == false && ext.bSign == false){
        if(orig.iLength > ext.iLength) { // same sign, length is orig > ext
            flag = false;
        }else if(orig.iLength < ext.iLength) { // same sign, length is orig < ext
            flag = true;
        }else{
            if(!strcmp(orig.cDigits,ext.cDigits)){
                flag = false;
            }else{
                for(int i = orig.iLength-1 ; i>=0 ; i–){ // same sign, same length
                    int A = (int)(orig.cDigits[i] – ‘0’);
                    int B = (int)(ext.cDigits[i] – ‘0’);
                    if(A > B) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    return flag;
}
 bool operator<(const big_int& orig, const big_int& ext) {
    bool flag = true;
    if(orig.bSign == false && ext.bSign == true){ // -orig , +ext
        flag = true;
    }else if(orig.bSign == true && ext.bSign == false){ // +orig , -ext
        flag = false;
    }else if(orig.bSign == true && ext.bSign == true){
        if(orig.iLength > ext.iLength) { // same sign, length is orig > ext
            flag = false;
        }else if(orig.iLength < ext.iLength) { // same sign, length is orig < ext
            flag = true;
        }else{
            if(!strcmp(orig.cDigits,ext.cDigits)){
                flag = false;
            }else{
                for(int i = orig.iLength-1 ; i>=0 ; i–){ // same sign, same length
                    int A = (int)(orig.cDigits[i] – ‘0’);
                    int B = (int)(ext.cDigits[i] – ‘0’);
                    if(A > B) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }else if(orig.bSign == false && ext.bSign == false){
        if(orig.iLength > ext.iLength) { // same sign, length is orig > ext
            flag = true;
        }else if(orig.iLength < ext.iLength) { // same sign, length is orig < ext
            flag = false;
        }else{
            if(!strcmp(orig.cDigits,ext.cDigits)){
                flag = false;
            }else{
                for(int i = orig.iLength-1 ; i>=0 ; i–){ // same sign, same length
                    int A = (int)(orig.cDigits[i] – ‘0’);
                    int B = (int)(ext.cDigits[i] – ‘0’);
                    if(A < B) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    return flag;
}
 // 덧셈 : orig + ext
 big_int operator+(const big_int& orig, const big_int& ext) {
    int max_i,min_j,k,carry,temp,len,findex;
    char *temp_str,*result_str,*high,*low;
    if(orig.bSign == ext.bSign){ // 부호가 같은 경우
        // 길이가 긴 것을 찾아서 공통 변수 할당
        if(orig.iLength < ext.iLength) {
            high = new char[(int)strlen(ext.cDigits)];
            low = new char[(int)strlen(orig.cDigits)];
            strcpy(high,ext.cDigits);
            strcpy(low,orig.cDigits);
            max_i = ext.iLength – 1;
            min_j = orig.iLength – 1;
        }else{
            high = new char[(int)strlen(orig.cDigits)];
            low = new char[(int)strlen(ext.cDigits)];
            strcpy(high,orig.cDigits);
            strcpy(low,ext.cDigits);
            max_i = orig.iLength – 1;
            min_j = ext.iLength – 1;
        }
        // 임시변수 초기화
        temp_str = new char[(int)strlen(high)];
        carry = 0;
        // 자릿수가 적은 숫자의 길이만큼의 덧셈 수행
        while(true) {
            temp = ((int)(high[max_i] – ‘0’) + (int)(low[min_j] – ‘0’));
            temp += carry;
            if(temp >= 10){
                carry = 1;
                temp %= 10;
            }else{
                carry = 0;
            }
            temp_str[max_i] = temp + ‘0’;
            max_i–;
            min_j–;
            if(min_j<0){
                break;
            }
        }
        
        // 자릿수가 긴 숫자의 길이만큼을 임시변수에 넣어줌
        for( ; max_i >= 0 ; max_i– ){
            temp = (int)(high[max_i] – ‘0’) + carry;
            if(temp >= 10){
                carry = 1;
                temp %= 10;
            }else{
                carry = 0;
            }
            temp_str[max_i] = temp + ‘0’;
        }
        temp_str[(int)strlen(high)] = ‘\0’;
        
        // 만약 끝까지 CARRY가 발생한 경우를 대비해서 다시 임시배열에 넣어줌.
        if(carry != 0) { // carry가 있는경우
            if(orig.bSign && ext.bSign){ // 둘다 양수라면
                len = (int)strlen(temp_str) + 1;
                findex = 1;
                result_str = new char[len];
                result_str[0] = carry + ‘0’;
                for(k = findex ; k < len ; k++) {
                    result_str[k] = temp_str[k-1];
                }
            }else if(!orig.bSign && !ext.bSign){ // 둘다 음수라면
                len = (int)strlen(temp_str) + 2;
                findex = 2;
                result_str = new char[len];
                result_str[0] = ‘-‘; // 부호 할당
                result_str[1] = carry + ‘0’;
                for(k = findex ; k < len ; k++) {
                    result_str[k] = temp_str[k-1];
                }
            }
        }else{
            if(orig.bSign && ext.bSign){ // 둘다 양수라면
                len = (int)strlen(temp_str);
                findex = 0;
                result_str = new char[len];
                for(k = findex ; k < len ; k++) {
                    result_str[k] = temp_str[k];
                }
            }else if(!orig.bSign && !ext.bSign){ // 둘다 음수라면
                len = (int)strlen(temp_str) + 2;
                findex = 1;
                result_str = new char[len];
                result_str[0] = ‘-‘; // 부호 할당
                for(k = findex ; k < len ; k++) {
                    result_str[k] = temp_str[k-1];
                }
            }
        }
        
        result_str[len] = ‘\0’;
        big_int result(result_str);
        return result;
    }else{ // 부호가 다른 경우
        bool rsign = true;
        // 결과 부호구하기
        // 다 똑같은데 부호만 다른 경우, 0이 나오니 0 리턴.
        if(!strcmp(ext.cDigits,orig.cDigits)){
            big_int result(0);
            return result;
        }
        if(!ext.bSign) { // ext가 음수
            if(orig.iLength > ext.iLength) { // orig가 크다면 결과는 당연히 양수다.
                rsign = true;
            }else if(orig.iLength < ext.iLength){ // ext가 크면 결과는 음수다.
                rsign = false;
            }else{ // 길이가 같으면 숫자만 보고 큰숫자 결정해야함.
                for(int i = 0 ; i < orig.iLength ; i++) {
                    if((orig.cDigits[i] – ‘0’) > (ext.cDigits[i] – ‘0’)) {
                        rsign = true;
                        break;
                    }else if((orig.cDigits[i] – ‘0’) < (ext.cDigits[i] – ‘0’)) {
                        rsign = false;
                        break;
                    }
                }
            }
            if(rsign) { // 결과가 양수면 orig가 큰숫자.
                high = new char[(int)strlen(orig.cDigits)];
                low = new char[(int)strlen(ext.cDigits)];
                strcpy(high,orig.cDigits);
                strcpy(low,ext.cDigits);
                max_i = orig.iLength – 1;
                min_j = ext.iLength – 1;
            }else{
                high = new char[(int)strlen(ext.cDigits)];
                low = new char[(int)strlen(orig.cDigits)];
                strcpy(high,ext.cDigits);
                strcpy(low,orig.cDigits);
                max_i = ext.iLength – 1;
                min_j = orig.iLength – 1;
            }
        }else{ // orig가 음수
            if(orig.iLength > ext.iLength) { // orig가 크다면 결과는 음수다.
                rsign = false;
            }else if(orig.iLength < ext.iLength){ // ext가 크면 결과는 양수다.
                rsign = true;
            }else{ // 길이가 같으면 숫자만 보고 큰숫자 결정해야함.
                for(int i = 0 ; i < orig.iLength ; i++) {
                    if((orig.cDigits[i] – ‘0’) > (ext.cDigits[i] – ‘0’)) {
                        rsign = false;
                        break;
                    }else if((orig.cDigits[i] – ‘0’) < (ext.cDigits[i] – ‘0’)) {
                        rsign = true;
                        break;
                    }
                }
            }
            if(rsign) { // 결과가 양수면 ext가 큰숫자.
                high = new char[(int)strlen(ext.cDigits)];
                low = new char[(int)strlen(orig.cDigits)];
                strcpy(high,ext.cDigits);
                strcpy(low,orig.cDigits);
                max_i = ext.iLength – 1;
                min_j = orig.iLength – 1;
            }else{
                high = new char[(int)strlen(orig.cDigits)];
                low = new char[(int)strlen(ext.cDigits)];
                strcpy(high,orig.cDigits);
                strcpy(low,ext.cDigits);
                max_i = orig.iLength – 1;
                min_j = ext.iLength – 1;
            }
            
        }
        // 임시변수 초기화
        temp_str = new char[(int)strlen(high)];
        carry = 0;
        // 자릿수가 적은 숫자의 길이만큼의 뺄셈 수행
        while(true) {
            temp = ((int)(high[max_i] – ‘0’) – (int)(low[min_j] – ‘0’));
            temp -= carry;
            
            if(temp < 0){
                carry = 1;
                temp += 10;
            }else{
                carry = 0;
            }
            temp_str[max_i] = temp + ‘0’;
            max_i–;
            min_j–;
            if(min_j<0){
                break;
            }
        }
        
        // 자릿수가 긴 숫자의 길이만큼을 임시변수에 넣어줌
        for( ; max_i >= 0 ; max_i– ){
            temp = (int)(high[max_i] – ‘0’) – carry;
            if(temp < 0){
                carry = 1;
                temp += 10;
            }else{
                carry = 0;
            }
            temp_str[max_i] = temp + ‘0’;
        }
        
        temp_str[(int)strlen(high)] = ‘\0’;
        
        // 만약 끝까지 CARRY가 발생한 경우를 대비해서 다시 임시배열에 넣어줌.
        if(temp_str[0] == ‘0’) {
            if(!rsign){
                len = (int)strlen(temp_str);
                result_str = new char[len];
                result_str[0] = ‘-‘;
                for(k = 1 ; k < len ; k++) {
                    result_str[k] = temp_str[k];
                }
            }else{
                len = (int)strlen(temp_str);
                result_str = new char[len];
                for(k = 0 ; k < len-1 ; k++) {
                    result_str[k] = temp_str[k+1];
                }
            }
        }else{
            if(!rsign){
                len = (int)strlen(temp_str) + 1;
                result_str = new char[(int)strlen(temp_str) + 1];
                result_str[0] = ‘-‘;
                for(k = 1 ; k < len ; k++) {
                    result_str[k] = temp_str[k-1];
                }
            }else{
                len = (int)strlen(temp_str);
                result_str = new char[(int)strlen(temp_str)];
                for(k = 0 ; k < len ; k++) {
                    result_str[k] = temp_str[k];
                }
            }
        }
        result_str[len] = ‘\0’;
        big_int result(result_str);
        return result;
    }
}
 // 뻴셈. orig – ext
 big_int operator-(const big_int& orig, const big_int& ext) {
    int max_i,min_j,k,carry,temp,len,findex;
    char *temp_str,*result_str,*high,*low;
    bool rsign;
    if(orig.bSign != ext.bSign){ // 부호가 다른 경우, 길이가 긴 쪽의 부호를 바꿔서 덧셈 수행.
        if(!strcmp(ext.cDigits,orig.cDigits)){
            big_int result(0);
            return result;
        }
        if(!ext.bSign) { // ext가 음수면 다 양수로 바꿔서 계산.
            big_int result(ext.cDigits);
            return orig+result;
        }else{ // orig가 음수면 결과는 무조건 음수다.
            temp_str = new char[ext.iLength + 1];
            temp_str[0] = ‘-‘;
            for(int i = 1 ; i < ext.iLength + 1 ; i++) temp_str[i] = ext.cDigits[i-1];
            temp_str[ext.iLength + 1] = ‘\0’;
            big_int result(temp_str);
            return orig+result;
            
        }
    }else{ // 부호가 같은 경우, ext를 음수로 바꾸고 덧셈 수행.
        if(!ext.bSign) { // 둘다 음수일 경우, 뒤의 숫자를 양수로 바꿔주고 덧셈 수행.
            big_int result(ext.cDigits);
            return orig + result;
        }else{ // 둘다 양수일 경우, 뒤에 숫자를 음수로 바꿔주고 덧셈 수행.
            temp_str = new char[ext.iLength + 1];
            temp_str[0] = ‘-‘;
            for(int i = 1 ; i <= ext.iLength ; i++) temp_str[i] = ext.cDigits[i-1];
            temp_str[ext.iLength – 1] = ‘\0’;
            big_int result(temp_str);
            return orig + ext;
        }
    }
}
 big_int operator*(const big_int& orig, const big_int& ext) {
    big_int temp(0),torig(orig),text(ext); // 33 * 44 의 경우, 33 * 4 + 33 * 40 즉 한자리씩 자릿수만큼 반복해서 더한다음에 뒤에 0을 여러개 붙히고 이를 다시 더해준다.
    int i = ext.iLength – 1;
    if(!orig.bSign){
        big_int tt(orig.cDigits);
        torig = tt;
    }
    if(!ext.bSign) {
        big_int tt(ext.cDigits);
        text = tt;
    }
    while(i>=0) {
        big_int temp2(0);
        char *temp_char,*result_char;
        for(int j = 0 ; j < (int)(text.cDigits[i] – ‘0’) ; j++) {
            temp2 = temp2 + torig;
        }
        if(text.cDigits[i] == ‘0’){
            big_int rslt(“0”);
            temp = temp + rslt;
        }else{
            // 최종 문자 만들기
            result_char = new char[temp2.iLength + (text.iLength – i – 1)];
            for(int j = 0 ; j < temp2.iLength ; j++) {
                result_char[j] = temp2.cDigits[j];
            }
            for(int j = temp2.iLength ; j < temp2.iLength + (text.iLength – i – 1) ; j++) {
                result_char[j] = ‘0’;
            }
            result_char[temp2.iLength + (text.iLength – i – 1)] = ‘\0’;
            big_int rslt(result_char);
            temp = temp + rslt;
        }
        i–;
    }
    if((!orig.bSign && ext.bSign) || (orig.bSign && !ext.bSign)) {
        char *rslt = new char[temp.iLength + 1];
        rslt[0] = ‘-‘;
        for(int j = 1 ; j < temp.iLength + 1 ; j++) {
            rslt[j] = temp.cDigits[j-1];
        }
        rslt[temp.iLength + 1] = ‘\0’;
        big_int result(rslt);
        return rslt;
    }else{
        return temp;
    }
}
 ostream& operator<<(ostream& c, const big_int& orig) {
    if(orig.bSign == false) c << ‘-‘;
    c << orig.cDigits;
    return c;
}
