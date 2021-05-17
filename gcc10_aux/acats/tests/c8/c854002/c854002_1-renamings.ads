
with C854002_1.Pure;
package C854002_1.Renamings is

    F_Result: constant String := C854002_1.Pure.F; -- Make sure we can call F.
    function Renamed_F return String;

    G_Result: constant String := C854002_1.Pure.G;
    type String_Function is access function return String;
    G_Pointer: String_Function := null;
        -- Will be set to C854002_1.Pure.G'Access in the body.
    function Renamed_G return String;

end C854002_1.Renamings;
