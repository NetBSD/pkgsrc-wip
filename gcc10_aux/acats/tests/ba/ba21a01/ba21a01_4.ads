                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
generic
package BA21A01_4 is
   pragma Preelaborate (BA21A01_4);
   Obj: FA21A00.My_Controlled;                                        -- OK.
                         -- Default-initialized object of a controlled type.
end BA21A01_4;
