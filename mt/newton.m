function [A,y]=newton(X,Y,x)
% 牛顿插值函数
% 输入参数：
%   X-样本点
%   Y-样本值
%   x-查询点
% 输出参数：
%   A-均差表
%   y-插值
n=length(X);    
m=length(x);
% 计算样本点的均差表A
A=zeros(n,n);A(:,1)=Y';
for j=2:n  % 求j阶均差
        for i=j:n  
            A(i,j)=(A(i,j-1)-A(i-1,j-1))/(X(i)-X(i-j+1));
        end
end
% 计算查询点x的插值
y=zeros(1,m);
for t=1:m  
    s=0.0;  z=x(t);
    for k=1:n  % 计算(x-xj)的累乘
        p=1.0;
        for j=1:k-1
            p=p*(z-X(j)); 
        end
        s=s+A(k,k)*p; % 含k阶均差的乘积项
    end
    y(t)=s;  % y为查询点的插值
end
end