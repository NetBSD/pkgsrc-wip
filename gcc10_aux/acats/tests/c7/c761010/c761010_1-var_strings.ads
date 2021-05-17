
with Ada.Finalization;
package C761010_1.Var_Strings is
    type Var_String(<>) is private;

    Some_String: constant Var_String;

    function "=" (X, Y: Var_String) return Boolean;

    procedure Check_Equal(X, Y: Var_String);
        -- Calls to this are used to defeat optimizations
        -- that might otherwise defeat the purpose of the
        -- test.  I'm talking about the optimization of removing
        -- unused controlled objects.

private

    type String_Ptr is access constant String;

    type Var_String(Length: Natural) is new Finalization.Controlled with
        record
            Comp_1: String_Ptr := new String'(2..Square(Length)-1 => 'x');
            Comp_2: String_Ptr(1..Length) := null;
            Comp_3: String(Length..Length) := (others => '.');
            TC_Lab: Character := '1';
        end record;
    procedure Initialize(X: in out Var_String);
    procedure Adjust(X: in out Var_String);
    procedure Finalize(X: in out Var_String);

    Some_String: constant Var_String
      := (Finalization.Controlled with Length => 1,
          Comp_1 => null,
          Comp_2 => null,
          Comp_3 => "x",
          TC_Lab => 'A');

    Another_String: constant Var_String
      := (Finalization.Controlled with Length => 10,
          Comp_1 => Some_String.Comp_2,
          Comp_2 => new String'("1234567890"),
          Comp_3 => "x",
          TC_Lab => 'B');

end C761010_1.Var_Strings;
