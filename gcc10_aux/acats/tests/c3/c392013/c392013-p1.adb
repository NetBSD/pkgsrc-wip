separate (C392013)
package body P1 is

    function "=" (L, R : T) return Boolean is
    begin
        return abs L.C1 = abs R.C1;
    end "=";

end P1;
