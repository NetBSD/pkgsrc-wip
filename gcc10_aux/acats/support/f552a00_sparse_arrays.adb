
package body F552A00_Sparse_Arrays is

   Disable_History : Boolean := False;

   procedure Append
     (Container : in out Sparse_Array;
      Index     : Sparse_Array_Index;
      New_Item  : Element_Type)
   is
   begin
      Container.Count                  := Container.Count + 1;
      Container.Data (Container.Count) := (Index => Index, Value => New_Item);
   end Append;

   function Has_Element (Position : Cursor) return Boolean is
      Found : constant Boolean :=
        (Position.Container /= null
        and then Position.Index > 0
        and then Position.Index <= Position.Container.all.Count);
   begin
      if not Disable_History then
         Ada.Strings.Unbounded.Append
           (Source   => TC_Call_History,
            New_Item => "H:" &
                        (if Found then "T(" else "F(") &
                        Count_Type'Image (Position.Index) &
                        ')');
      end if;

      return Found;
   end Has_Element;

   function Has_Element
     (Container : Sparse_Array;
      Index     : Sparse_Array_Index)
      return      Boolean
   is
   begin
      return (for some Item in Container.Data'Range =>
                   Container.Data (Item).Index = Index);
   end Has_Element;

   type Iterator is new
     Sparse_Array_Iterator_Interfaces.Reversible_Iterator with
      record
         Index     : Count_Type;
         Container : Sparse_Array_Access;
      end record;

   overriding function First
     (Object : Iterator) return Cursor;

   overriding function Next
     (Object   : Iterator;
      Position : Cursor) return Cursor;

   overriding function Last
     (Object : Iterator) return Cursor;

   overriding function Previous
     (Object   : Iterator;
      Position : Cursor) return Cursor;

   function First
     (Object : Iterator) return Cursor is
   begin
      Ada.Strings.Unbounded.Append (Source   => TC_Call_History,
                                    New_Item => '1');

      return (Index => 1,
              Container => Object.Container);
   end First;

   function Next
     (Object   : Iterator;
      Position : Cursor) return Cursor is
   begin

      Ada.Strings.Unbounded.Append
        (Source   => TC_Call_History,
         New_Item => "N(" & Count_Type'Image (Position.Index + 1) & ')');

      return (Index => Position.Index + 1,
              Container => Object.Container);
   end Next;

   function Last
     (Object : Iterator) return Cursor is
   begin
      Ada.Strings.Unbounded.Append (Source   => TC_Call_History,
                                    New_Item => 'L');

      return (Index => Object.Container.all.Count,
              Container => Object.Container);
   end Last;

   function Previous
     (Object   : Iterator;
      Position : Cursor) return Cursor is
   begin
      Ada.Strings.Unbounded.Append
        (Source   => TC_Call_History,
         New_Item => "P(" & Count_Type'Image (Position.Index - 1) & ')');

      return (Index => Position.Index - 1,
              Container => Object.Container);
   end Previous;

   function Iterate
     (Container : aliased in Sparse_Array)
      return
       Sparse_Array_Iterator_Interfaces.Reversible_Iterator'Class is
   begin
      Ada.Strings.Unbounded.Append (Source   => TC_Call_History,
                                    New_Item => 'I');
      return Iterator'(Index => 0,
                       Container => Container'Unchecked_Access);
   end Iterate;

   function Constant_Reference
     (Container : aliased Sparse_Array;
      Position  : Cursor) return Constant_Reference_Type is
   begin
      Disable_History := True;
      TC_Constant_Indexing_Use_Count := TC_Constant_Indexing_Use_Count + 1;

      if Position.Container = null then
         raise Constraint_Error with "Position is invalid";
      elsif not Position.Container.all'Overlaps_Storage (Container) then
         raise Program_Error with
         "Position denotes a different container";
      elsif Position.Index = 0 or else
        Position.Index > Container.Count then
         raise Constraint_Error with "Position is out of range";
      elsif not Has_Element (Position) then
         raise Constraint_Error with "Position does not exist";
      end if;

      Disable_History := False;

      return (Element => Container.Data (Position.Index).Value'Access);

   end Constant_Reference;

   function Reference
     (Container : aliased in out Sparse_Array;
      Position  : Cursor) return Reference_Type is
   begin
      Disable_History := True;
      TC_Variable_Indexing_Use_Count := TC_Variable_Indexing_Use_Count + 1;

      if Position.Container = null then
         raise Constraint_Error with "Position is invalid";
      elsif not Position.Container.all'Overlaps_Storage (Container) then
         raise Program_Error with
           "Position denotes a different container";
      elsif not Has_Element (Position) then
         raise Constraint_Error with "Position does not exist";
      end if;

      Disable_History := False;

      return (Element => Container.Data (Position.Index).Value'Access);

   end Reference;

end F552A00_Sparse_Arrays;

