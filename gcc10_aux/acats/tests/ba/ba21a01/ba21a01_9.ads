                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
generic
   type Formal is private;
package BA21A01_9 is
   pragma Preelaborate (BA21A01_9);
   Obj: Formal;                                                       -- OK.
                   -- Default-initialized object of a (formal) private type.
end BA21A01_9;
