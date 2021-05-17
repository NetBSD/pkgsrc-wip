
     --==================================================================--

with CA11014_0;            -- Generic list abstraction.
pragma Elaborate (CA11014_0);
generic             

   -- Import the list abstraction defined in CA11014_0.
   with package List_Mgr is new CA11014_0 (<>);

package CA11014_1 is    

   -- Write to current element and advance "current" pointer.
   procedure Write_Element (L : in out List_Mgr.List_Type; 
                            E : in     List_Mgr.Element_Type);

   -- Read from current element and advance "current" pointer.
   procedure Read_Element (L : in out List_Mgr.List_Type; 
                           E :    out List_Mgr.Element_Type);

   -- Add element to end of list.
   procedure Add_Element (L : in out List_Mgr.List_Type; 
                          E : in     List_Mgr.Element_Type);

end CA11014_1;
