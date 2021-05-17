

     --===================================================================--


with B391002_0;
generic                                                     -- Template for
   type Form_Pri is tagged private;                         -- formal package.
   type Form_Der is new B391002_0.Root with private;
package B391002_1 is
   type Parent  is tagged null record;
   type Pri_Ext is new Form_Pri with private;
   type Rec_Ext is new Form_Der with null record;
private
   type Pri_Ext is new Form_Pri with null record;
end B391002_1;
