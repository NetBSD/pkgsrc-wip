with Ada.Characters.Handling;
separate (C392013)
package body P3 is

    function "=" (L, R : T) return Boolean is
    begin
        return P2."=" (P2.T (L), P2.T (R)) and then
                  Ada.Characters.Handling.To_Upper (L.C3) =
                     Ada.Characters.Handling.To_Upper (R.C3);
    end "=";

    function Make (Ancestor : P1.T; X : Float) return T is
    begin
        return (P2.Make (Ancestor, X) with ' ');
    end Make;

end P3;
