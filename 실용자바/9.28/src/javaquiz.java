import java.util.Scanner;

public class javaquiz {
    public static void main(String[] args) {

        boolean run = true;
        int studentNum = 0;
        int[] scores = null;
        int maxScore = 0;
        int averageScore = 0;
        int sum = 0;

        Scanner scanner = new Scanner(System.in);

        while(run) {
            System.out.println("-------------------------");
            System.out.println("1. 학생수 | 2. 점수입력 | 3. 점수리스트| 4. 분석| 5. 종료");
            System.out.println("-------------------------");
            System.out.print("선택> ");

            int selectNo = scanner.nextInt();

            if (selectNo == 2) {
                System.out.println("몇명의 점수를 입력할까요? ");
                int num = scanner.nextInt();
                scores = new int[num];

                for (int i = 0; i < scores.length; i++) {
                    System.out.print("원하는 숫자를 입력하세요: ");
                    scores[i] = scanner.nextInt();
                    if (maxScore < scores[i]) maxScore = scores[i];
                    sum += scores[i];
                }
                System.out.println("입력이 종료되었습니다.");

                System.out.println("입력된 갯수: " + num + " max값 : " + maxScore + " 평균값 : " + (sum / num));

            }

            if (selectNo == 4) {
                System.out.println("-------------------------");
                for (int i = 0; i < scores.length; i++) {
                    System.out.println("score[" + i + "] = " + scores[i]);
                }
            }

            if(selectNo == 5 ){
                System.out.println("프로그램을 종료하였습니다.");
                run = false;
            }

        }

    }
}
