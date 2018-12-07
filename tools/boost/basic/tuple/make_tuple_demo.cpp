/*
 *Created by lyrichu on 18-12-8.
 */
#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>

void make_simple_tuple3();
boost::tuple<int,int> make_tuple_divide(int,int);

int main() {
    make_simple_tuple3();
    boost::tuple<int,int> s = make_tuple_divide(8,2);
    std::cout<<s<<std::endl;
    // 访问s的第一个元素
    std::cout<<"s(0):"<<s.get<0>()<<std::endl;
    // 访问s的第二个元素
    std::cout<<"s(1):"<<boost::get<1>(s)<<std::endl;
    // 元素赋值
    boost::get<0>(s) = 10;
    // 自增
    ++s.get<1>();
    std::cout<<"After change:"<<"s(0):"<<s.get<0>()<<",s(1):"<<boost::get<1>(s)<<std::endl;
}

void make_simple_tuple3() {
    boost::tuple<int,char,float> t(2,'a',1.9);
    std::cout<<t<<std::endl;
}

boost::tuple<int, int> make_tuple_divide(int a,int b) {
    return boost::make_tuple<int,int>(a/b,a%b);
}



