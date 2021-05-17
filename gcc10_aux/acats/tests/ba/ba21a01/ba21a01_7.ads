                                  -- Pragma does not apply to this instance.


     --===================================================================--


with Ada.Finalization;
with FA21A00;
generic
package BA21A01_7 is
   pragma Preelaborate (BA21A01_7);
   CT: FA21A00.My_Controlled :=
     (Ada.Finalization.Controlled with 5);                            -- OK.
              -- Extension aggregate with ancestor denoting controlled type.
end BA21A01_7;
