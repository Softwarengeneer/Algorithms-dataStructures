#include <iostream>

using namespace std;

int main()
{
    int Buf[] = {-1, -1, -1};
    int index1 = 1;
    int index2 = 1;
    int m_index1 = 1;
    int n;
    int M_length=0;
    int last3=0;
    cin >> n;
    for (int i = 1; i <= n; i++) {

        Buf[0] = Buf[1];
        Buf[1] = Buf[2];
        cin >> Buf[2];
//
//        if(Buf[0] == Buf[1]&&
//                Buf[1] == Buf[2]&&index2==1){
//            index2=i;
//            M_length=index2-index1;
//            last3=i;
//        }
//        if (Buf[0] == Buf[1]&&
//            Buf[1] == Buf[2]&&i-last3>M_length){
//            index1=index2;
//            index2=i;
//            M_length=index2-index1;
//            last3=i;
//        }
//        if (Buf[0] == Buf[1]&&
//            Buf[1] == Buf[2]&&i-index2<M_length){
//            last3=i;
//        }
//
//
//        if((n-1==i)&&(index2-index1<n-last3)&&index1!=1){
//            index1=last3;
//            index2=n;
//        }else if(n-1==i&&n-index2>index2-index1){
//            index1=index2;
//            index2=n;
//        }

        if(Buf[0] == Buf[1]&&
           Buf[1] == Buf[2]
           &&i-index1>M_length){
            M_length=i-index1;
            m_index1=index1;
        }
        if(Buf[0] == Buf[1]&&
           Buf[1] == Buf[2]){
            index1=i-1;
        }
        if(i == n){
            if(i-index1+1>M_length){
                M_length=i-index1+1;
                m_index1 = index1;
            }
        }
    }
    cout << m_index1 << " " << m_index1+M_length-1 << endl;
    return 0;
}
