
with Ada.Numerics.Float_Random; use Ada.Numerics;

package body F552A00_Bingo_Balls is

   Generator : Float_Random.Generator;

   -----------------
   -- Has_Element --
   -----------------

   function Has_Element (Position : Cursor) return Boolean is
   begin
      Ada.Strings.Unbounded.Append
        (Source   => TC_Call_History,
         New_Item => "H:" &
                     (if Position.Count > 0 then "T(" else "F(") &
           Natural'Image (Bingo_Index'Last - Position.Count + 1) &
        ')');
      return Position.Count > 0;
   end Has_Element;

   type Iterator is new Bingo_Iterator.Forward_Iterator with null record;

   overriding function First
     (Object : Iterator) return Cursor;

   overriding function Next
     (Object   : Iterator;
      Position : Cursor) return Cursor;

   function First
     (Object : Iterator) return Cursor is
   begin
      Ada.Strings.Unbounded.Append (Source   => TC_Call_History,
                                    New_Item => '1');

      return Position : Cursor do
         Position.Count := Position.Balls'Last;
         for I in Bingo_Call'Range loop
            Position.Balls (Bingo_Call'Pos (I) + 1) := I;
         end loop;

         Position.Current_Ball :=
           Bingo_Index'Base'Max
             (Bingo_Index'Last,
              Bingo_Index'First + Bingo_Index'Base
                (Float'Floor (Float_Random.Random (Gen => Generator) /
                   1.0 / Float (Position.Count))));

      end return;

   end First;

   function Next
     (Object   : Iterator;
      Position : Cursor) return Cursor is
   begin

      return New_Position : Cursor do
         New_Position.Count := Position.Count - 1;

         if Position.Current_Ball > 1 then
            New_Position.Balls (1 .. Position.Current_Ball - 1) :=
              Position.Balls (1 .. Position.Current_Ball - 1);
         end if;

         if Position.Current_Ball < Position.Count then
            New_Position.Balls (Position.Current_Ball .. Position.Count - 1) :=
              Position.Balls (Position.Current_Ball + 1 .. Position.Count);
         end if;

         New_Position.Current_Ball :=
           (if New_Position.Count = 0 then 0 else
            Bingo_Index'Base'Max
             (New_Position.Count,
              Bingo_Index'First + Bingo_Index'Base
                (Float'Floor (Float_Random.Random (Gen => Generator) /
                   1.0 / Float (New_Position.Count)))));

         Ada.Strings.Unbounded.Append
           (Source   => TC_Call_History,
            New_Item => "N(" &
              Integer'Image (Integer (Bingo_Index'Last) -
                Integer (New_Position.Count) + 1) & ')');

      end return;

   end Next;

   -------------
   -- Iterate --
   -------------

   function Iterate
     (Container : Bingo_Game)
      return Bingo_Iterator.Forward_Iterator'Class is
   begin
      Ada.Strings.Unbounded.Append (Source   => TC_Call_History,
                                    New_Item => 'I');

      return New_Iterator : Iterator do
         null;
      end return;

   end Iterate;

   ------------------------
   -- The_Call           --
   ------------------------

   function The_Call
     (Container : Bingo_Game;
      Position  : Cursor) return Bingo_Call is
   begin
      TC_Used_Constant_Indexing := True;
      return Position.Balls (Position.Current_Ball);
   end The_Call;

end F552A00_Bingo_Balls;
