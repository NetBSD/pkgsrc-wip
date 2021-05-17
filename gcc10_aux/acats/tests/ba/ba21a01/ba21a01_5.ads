                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
generic
package BA21A01_5 is
   pragma Preelaborate (BA21A01_5);
private
   Obj: FA21A00.Priv;                                                 -- OK.
                            -- Default-initialized object of a private type.
end BA21A01_5;
