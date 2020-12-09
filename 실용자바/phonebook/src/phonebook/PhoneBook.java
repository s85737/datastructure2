/**
 *  phone객체를 memberlist에 저장하는 클래스
 *
    @Author 5468107 최제현
    @Date 2020/10/10
 */

package phonebook;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class PhoneBook {

    private String memberName;
    private String phoneNumber;
    private String myRequest;
    private HashSet<Phone> memberList = new HashSet<Phone>();
    private Scanner scanner = new Scanner(System.in);

    /**
     * parameter로 memberNumber 를 받고, 그 수만큼 맴버 이름과 번호를 저장
     * @param memberNumber 저장하고싶은 맴버의 수
     */
    public void setMemberList(int memberNumber){



        for(int i = 0; i < memberNumber; i++) {
            System.out.print("이름과 전화번호(이름과 번호는 빈칸없이 입력)>>");
            Phone member = new Phone();

            member.setMemberName(scanner.next());
            member.setPhoneNumber(scanner.next());
            this.memberList.add(member);
        }

        System.out.println("저장되었습니다....");
    }

    /**
     * memberList에서 맴버이름 검색 후 있으면 전화번호 출력 없으면 메시지 출력후 다시 입력
     * 그만이라고 입력시 프로그램 종료
     */
    public void searchMember(){

        System.out.print("검색할 이름: ");
        myRequest = scanner.next();

        if(!myRequest.equals("그만")){
            Iterator<Phone> itr = memberList.iterator();
            while(itr.hasNext()){
                Phone thisMember = itr.next();
                if(thisMember.getMemberName().equals(myRequest)){
                    System.out.println(thisMember.getMemberName()+"의 번호는 "+thisMember.getPhoneNumber()+"입니다.");
                    searchMember();
                    thisMember = null;
                }
            }

            System.out.println(myRequest + " 이 없습니다.");
            searchMember();

        }else{
            System.exit(1);
        }

    }

    public void printMember(){
            Iterator<Phone> itr = memberList.iterator();
            while(itr.hasNext()){
                Phone thisMember = itr.next();
                    System.out.println(thisMember.getMemberName()+"의 번호는 "+thisMember.getPhoneNumber()+"입니다.");
                }
    }

    /**
     * main 클래스 인원수 입력
     */

    public static void main(String[] args) {

        int memberNumber;
        PhoneBook phoneBook = new PhoneBook();

        Scanner scanner = new Scanner(System.in);
        System.out.print("인원수>> ");
        memberNumber = scanner.nextInt();


        phoneBook.setMemberList(memberNumber);
        phoneBook.searchMember();
        phoneBook.printMember();

    }

}
