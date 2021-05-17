
with B371001_1.Child_1;
package B371001_0 is

    type A is array (1 .. 10) of aliased B371001_1.T;
    type B is array (1 .. 10) of aliased B371001_1.Child_1.T;

    X : A;
    Y : B;

end B371001_0;

