
with C854002_1.Pure;
with C854002_1.Caller; pragma Elaborate(C854002_1.Caller);
    -- This pragma ensures that this package body (Renamings)
    -- will be elaborated after Caller, so that when Caller calls
    -- the renamings during its elaboration, the renamings will
    -- not have been elaborated (although what the rename have been).
package body C854002_1.Renamings is

    function Renamed_F return String renames C854002_1.Pure.F;

    package Dummy is end; -- So we can insert statements here.
    package body Dummy is
    begin
        G_Pointer := C854002_1.Pure.G'Access;
    end Dummy;

    function Renamed_G return String renames G_Pointer.all;

end C854002_1.Renamings;
