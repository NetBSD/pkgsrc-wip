

     --===================================================================--


with FA21A00;
use type FA21A00.My_Int;
generic
   type Form_Priv   is private;
   type Form_PriExt is new FA21A00.Tag with private;

   type Int_Type is range <>;
   with function Init return Int_Type;

   type Index is (<>);
   type Array_Type is array (Index) of FA21A00.Priv;
package BA21A02 is
   pragma Preelaborate (BA21A02);

   type DerPriv is new FA21A00.Priv with record
      S: String (1 .. 7);
   end record;

   procedure Dummy; -- Needed to allow package body.
end BA21A02;
