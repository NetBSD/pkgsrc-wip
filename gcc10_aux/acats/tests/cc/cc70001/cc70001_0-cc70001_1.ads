

     --==================================================================--


-- Child must be generic since parent is generic. A formal parameter for
-- "element type" can not be provided here, because then the type of list
-- element assumed by these new operations would be different from that
-- defined by the list type declared in the parent.

generic             
package CC70001_0.CC70001_1 is    -- Additional list operations.

   -- Read from current element and advance "current" pointer.
   procedure Read_Element (L : in out List_Type; E : out Element_Type);

   -- Write to current element and advance "current" pointer.
   procedure Write_Element (L : in out List_Type; E : in Element_Type);

   -- Add element to end of list.
   procedure Add_Element (L : in out List_Type; E : in Element_Type);

end CC70001_0.CC70001_1;
