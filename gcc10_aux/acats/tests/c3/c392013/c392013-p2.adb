separate (C392013)
package body P2 is

    function "=" (L, R : T) return Boolean is
    begin
        return P1."=" (P1.T (L), P1.T (R)) and then abs (L.C2 - R.C2) <= 0.5;
    end "=";


    function Make (Ancestor : P1.T; X : Float) return T is
    begin
        return (Ancestor with X);
    end Make;

end P2;
