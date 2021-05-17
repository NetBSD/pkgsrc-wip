

     --===================================================================--


with BA21002_0;
use type BA21002_0.My_Int;
package BA21002 is

   pragma Pure (BA21002);

   type Tag_Ext is new BA21002_0.Tag     with null record;
   type Rec_Ext is new BA21002_0.Pri_Ext with null record;

   procedure Proc;

   type Priv is tagged private;

private

   type Priv is tagged record
      A: Integer;
      B: Boolean;
   end record;

end BA21002;
