
with Ada.Iterator_Interfaces;
with Ada.Strings.Unbounded; use Ada;

generic

   type Sparse_Array_Index is range <>;

   type Element_Type is private;

package F552A00_Sparse_Arrays is

   --  This package defines an iterable container that is a sparse array.
   --  A sparse array has elements that can have large gaps beteen each
   --  element. For instance an array from 1 .. 1000000 might only have a
   --  dozen real elements in the array.

   type Count_Type is range 0 .. 2 ** 31 - 1;

   type Sparse_Array (Max_Elements : Count_Type) is tagged private
    with   Constant_Indexing => Constant_Reference,
           Variable_Indexing => Reference,
           Default_Iterator  => Iterate,
           Iterator_Element  => Element_Type;

   procedure Append
     (Container : in out Sparse_Array;
      Index     : Sparse_Array_Index;
      New_Item  : Element_Type)
    with Pre => Container.Length < Container.Max_Elements and then
     not Has_Element (Container, Index);
   --  Duplicate indexes are not allowed.

   function Length (Container : Sparse_Array) return Count_Type;
   --  Returns the number of real elements in the array

   type Cursor is private;

   function Has_Element (Position : Cursor) return Boolean;

   function Has_Element
     (Container : Sparse_Array;
      Index     : Sparse_Array_Index)
      return      Boolean;

   function Index_Of (Position : Cursor) return Sparse_Array_Index;
   --  Returns the array index assosiated with Position.

   package Sparse_Array_Iterator_Interfaces is new Ada.Iterator_Interfaces (
      Cursor,
      Has_Element);

   function Iterate
     (Container : aliased in Sparse_Array)
      return      Sparse_Array_Iterator_Interfaces.Reversible_Iterator'Class;

   type Constant_Reference_Type
     (Element : not null access constant Element_Type) is private
     with Implicit_Dereference => Element;

   type Reference_Type (Element : not null access Element_Type) is private
     with Implicit_Dereference => Element;

   function Constant_Reference
     (Container : aliased Sparse_Array;
      Position  : Cursor) return Constant_Reference_Type;

   function Reference
     (Container : aliased in out Sparse_Array;
      Position  : Cursor) return Reference_Type;

   TC_Call_History : Strings.Unbounded.Unbounded_String;
   --
   --  A string capturing the call sequence to the above subprogams.
   --  The following gets appended to the history for the above calls;
   --      Iterate  => I
   --      First    => 1
   --      Next     => N( nn)        where nn is the physical index of the
   --                                   next element
   --      Last     => L
   --      Previous => P( nn)        where nn is the physical index of the
   --                                   next element
   --      Has_Element => H:{T|F}( nn)  H is the Has_Element function
   --                                     T means Has_Element returned True
   --                                     F means Has_Element returns False
   --                                      nn is the physical index

   TC_Constant_Indexing_Use_Count : Natural := 0;
   TC_Variable_Indexing_Use_Count : Natural := 0;

private

   type Sparse_Array_Element is
   record
      Index : Sparse_Array_Index;
      --  The real index associated with the value

      Value : aliased Element_Type;
   end record;

   type Data_Array is
     array (Count_Type range <>) of Sparse_Array_Element;

   type Sparse_Array (Max_Elements : Count_Type) is tagged
   record
      Data : Data_Array (1 .. Max_Elements) := (others => <>);
      Count : Count_Type := 0;
   end record;

   function Length (Container : Sparse_Array) return Count_Type is
     (Container.Count);

   type Sparse_Array_Access is access constant Sparse_Array;
   for Sparse_Array_Access'Storage_Size use 0;

   type Cursor is
   record
      Index : Count_Type;
      Container : Sparse_Array_Access;
   end record;

   function Index_Of (Position : Cursor) return Sparse_Array_Index is
      (Position.Container.all.Data (Position.Index).Index);

   type Constant_Reference_Type
      (Element : not null access constant Element_Type) is null record;

   type Reference_Type (Element : not null access Element_Type)
     is null record;

end F552A00_Sparse_Arrays;
