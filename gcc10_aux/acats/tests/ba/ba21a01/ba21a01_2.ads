                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
use type FA21A00.My_Int;
generic
   FObj: in FA21A00.My_Int;
package BA21A01_2 is
   pragma Preelaborate (BA21A01_2);
   Bool: Boolean := (FObj = 10);                                      -- OK.
                                      -- Primary that is a name of an object
                                      -- which is not a static expression.
end BA21A01_2;
