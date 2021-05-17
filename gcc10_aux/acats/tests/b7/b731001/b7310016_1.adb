
package body B7310016_1 is

    function Bool_Op(B: Boolean) return Enum is
    begin
        return Enum'Last;
    end Bool_Op;

    function Bool_Op(B: Boolean) return Another_Enum is
    begin
        return Another_Enum'First;
    end Bool_Op;

end B7310016_1;
