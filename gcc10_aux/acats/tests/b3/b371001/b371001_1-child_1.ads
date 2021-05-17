
package B371001_1.Child_1 is
    pragma Elaborate_Body;

    type T (D2 : Integer := 0) is null record;
    type Ptr1 is access all T;

private
    type Ptr2 is access constant T;
end B371001_1.Child_1;
