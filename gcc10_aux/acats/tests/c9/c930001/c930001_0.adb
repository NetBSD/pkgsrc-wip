

with Report;
package body C930001_0 is

    protected body Note is
        procedure Done (Id : Ids) is
        begin
            Finalization_Cnt := Finalization_Cnt + 1;
            Finalization_Order (Finalization_Cnt) := Id;
        end Done;
    end Note;

    procedure Finalize (Object : in out Has_Finalization) is
    begin
        Note.Done (Object.Id);
        if Verbose then
            Report.Comment ("in Finalize for" & Ids'Image (Object.Id));
        end if;
    end Finalize;
end C930001_0;
