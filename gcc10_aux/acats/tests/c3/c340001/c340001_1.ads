
package C340001_1 is

   type List_Contents is array (1..10) of Integer;
   type List is tagged limited record
      Length   : Natural range 0..10 := 0;
      Contents : List_Contents := (others => 0);
   end record;

   procedure Add_To (L : in out List; New_Value : in Integer);
   procedure Remove_From (L : in out List);

   function "=" (L, R : in List) return Boolean;

   subtype Revision_Mark is Character range 'A' .. 'Z';
   type Revisable_List is new List with record
      Revision : Revision_Mark := 'A';
   end record;

   procedure Revise (L : in out Revisable_List);

end C340001_1;
