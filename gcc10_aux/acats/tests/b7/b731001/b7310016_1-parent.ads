
----------------------------------------------------------------
-- This part comes from AARM-7.3.1(7.d-7.q):

package B7310016_1.Parent is
    type Root is tagged null record;
    procedure Op1(X : Root);

    type My_Int is range 1..10;
private
    procedure Op2(X : Root);

    type Another_Int is new My_Int;
    procedure Int_Op(X : My_Int);
end B7310016_1.Parent;
