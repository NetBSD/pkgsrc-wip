
-- No bodies provided for BA13B02_0.

     --==================================================================--

-- Public child package.

package BA13B02_0.BA13B02_1 is

   type Child_Record is private;

   type Child_Vis_Tagged is tagged 
      record
         PI : Parent_Integer;
      end record;

   type Child_Vis_Ext is new Child_Vis_Tagged with 
      record
         CR : Child_Record;
      end record;

   function Assign_Color (C : Parent_Color) 
     return Child_Vis_Ext;

   type Child_Pri_Ext is new Child_Vis_Tagged with private;

   type Child_Private is private;

private

   type Child_Record is 
      record
         VC : Parent_Color;
      end record;

   type Child_Pri_Ext is new Child_Vis_Tagged with
      record
         VI : Parent_Integer;
      end record;

   type Child_Private is 
      record
         VI : Parent_Integer;
      end record;

   function Assign_Integer (I : Parent_Integer)
     return Child_Private;

end BA13B02_0.BA13B02_1;
