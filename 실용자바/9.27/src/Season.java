import java.util.Scanner;

/**
 * @author 5468107 최제현
 * @data 9/27
 * 입력된 정수에 따라 계절 출력
 */
public class Season {

    public static void main(String[]args){

        Scanner scanner = new Scanner(System.in);

        System.out.print("월을 입력해 주세요 : ");

        int inputMonth = scanner.nextInt();


        /*
            12~2월 겨울
            3월~5월 봄
            6월~8월 여름
            9월~11월 가을
         */

        if ((inputMonth < 3 && inputMonth > 0) || (inputMonth == 12)) {
            System.out.println(inputMonth + " 월은 겨울입니다.");
        } else if(inputMonth < 6 && inputMonth > 2){
            System.out.println(inputMonth + " 월은 봄입니다.");
        } else if(inputMonth < 9 && inputMonth > 5){
            System.out.println(inputMonth + " 월은 여름입니다.");
        } else if(inputMonth < 12 && inputMonth > 9){
            System.out.println(inputMonth + " 월은 가을입니다.");
        } else{
                // 예외처리
            System.out.println("1~12월 사이로 입력해 주세요.");
            System.exit(0);
        }

        //스캐너 종료
        scanner.close();

    }
}
