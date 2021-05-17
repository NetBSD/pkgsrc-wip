                                  -- Pragma does not apply to this instance.



     --===================================================================--


generic
   type Int_Type is range <>;
   with function Init return Int_Type;
package BA21A01_1 is
   pragma Preelaborate (BA21A01_1);
private
   Call : Int_Type := Init;                                           -- OK.
                                                 -- Call to formal function.
end BA21A01_1;
