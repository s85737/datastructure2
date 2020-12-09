/**
 * Phone 클래스 객체에 맴버 이름과 휴대폰 번호 저장 및 출력
 * @Author 5468107 최제현
 * @Date 2020/10/10
 */

package phonebook;

import java.util.Objects;

public class Phone {

    private String memberName;
    private String phoneNumber;


    public Phone(){
        this.memberName = "홍길동";
        this.phoneNumber = "010-1234-5678";
    }

    public Phone(Phone member){
        this.memberName = member.getMemberName();
        this.phoneNumber = member.getPhoneNumber();
    }

    /**
     * 맴버이름 저장
     * @param memberName 입력한 맴버이름
     */
    public void setMemberName(String memberName){
        this.memberName = memberName;
    }

    /**
     * 휴대폰 번호 저장
     * @param phoneNumber 입력한 맴버 전화번호
     */
    public void setPhoneNumber(String phoneNumber){
        this.phoneNumber = phoneNumber;
    }

    /**
     * @return 맴버 이름 return
     */
    public String getMemberName(){
        return memberName;
    }

    /**
     * @return 휴대폰 번호 return
     */
    public String getPhoneNumber(){
        return phoneNumber;
    }

    @Override
    public boolean equals(Object o) {
        Phone phone = (Phone) o;
        if(this.memberName.equals(phone.memberName)){
            System.out.println("이미 존재하는 데이터입니다.");
            return true;
        }
        else return false;
    }

    @Override
    public int hashCode() {
        return memberName.hashCode();
    }
}
