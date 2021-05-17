                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
generic
   type Formal is new FA21A00.Tag with private;
package BA21A01_10 is
   pragma Preelaborate (BA21A01_10);
private
   Obj: Formal;                                                       -- OK.
              -- Default-initialized object of a (formal) private extension.
end BA21A01_10;
