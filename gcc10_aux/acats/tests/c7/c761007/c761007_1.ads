
---------------------------------------------------------------- C761007_1

with C761007_0;
with Ada.Finalization;
package C761007_1 is

  type Container is new Ada.Finalization.Controlled
    with record
      Effect   : Character;
      Content  : C761007_0.Internal;
    end record;

  procedure Finalize( C: in out Container );

  Side_Effect : String(1..80);  -- way bigger than needed
  Side_Effect_Finger : Natural := 0;

  This_Exception_Is_Supposed_To_Be_Ignored : exception;

end C761007_1;
