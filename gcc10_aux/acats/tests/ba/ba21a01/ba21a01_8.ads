                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
generic
package BA21A01_8 is
   pragma Preelaborate (BA21A01_8);
private
   Obj: FA21A00.RecCallDefault;                                       -- OK.
                                         -- Call to nonstatic function (in
                                         -- component's default expression).
end BA21A01_8;
