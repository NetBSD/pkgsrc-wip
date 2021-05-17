                                  -- Pragma does not apply to this instance.


     --===================================================================--


with FA21A00;
generic
   type Index is (<>);
   type Array_Type is array (Index) of FA21A00.Pri_Ext;
package BA21A01_6 is
   pragma Preelaborate (BA21A01_6);
   Arr: Array_Type;                                                   -- OK.
                    -- Default-initialized component of a private extension.
end BA21A01_6;
