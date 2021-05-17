                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
generic
package BA21A01_3 is
   pragma Preelaborate (BA21A01_3);
private
   Obj: FA21A00.Prot;                                                 -- OK.
                                               -- Object of a protected type
                                               -- with entry declarations.
end BA21A01_3;
