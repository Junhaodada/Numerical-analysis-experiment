function y=lagrange(X,Y,x)
% 拉格朗日插值函数
% 输入参数：
%   x0-样本点
%   y0-样本值
%   x-查询点
% 输出参数：
%   y-插值
n=length(X);  
m=length(x);
for i=1:m
     z=x(i);
     s=0.0;
    for k=1:n
          p=1.0;
          for j=1:n
               if j~=k
                  p=p*(z-X(j))/(X(k)-X(j));
               end
          end
         s=p*Y(k)+s;
    end
    y(i)=s;
end
end