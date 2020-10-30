public class Shift {
    public static void shiftTwoDArr(int[][] arr) {

        int[]temp = arr[arr[2].length-1];

        for(int i = arr.length-2 ; i >= 0; i--) {
            arr[i+1] = arr[i];
        }

        arr[0] = temp;


    }

    public static void showTwoDArr(int[][] arr){
        for(int i = 0 ; i < arr.length; i++){
            for(int j = 0; j < arr[i].length; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        int[][] arr = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

        System.out.println("1차 shift...");
        shiftTwoDArr(arr);
        showTwoDArr(arr);

        System.out.println("2차 shift...");
        shiftTwoDArr(arr);
        showTwoDArr(arr);
        System.out.println("3차 shift...");
        shiftTwoDArr(arr);
        showTwoDArr(arr);
    }


}
