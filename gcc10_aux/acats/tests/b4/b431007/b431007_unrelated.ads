
with B431007;
package B431007_Unrelated is

   type Ext2 is new B431007.Root with private;

private

   type Ext2 is new B431007.Root with record
      C2 : Integer;
   end record;

end B431007_Unrelated;
