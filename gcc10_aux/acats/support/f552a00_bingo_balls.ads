
with Ada.Iterator_Interfaces;
with Ada.Strings.Unbounded; use Ada;

package F552A00_Bingo_Balls is
   --  This package defines an iterable container that is only iterable
   --  in the forward direction. In addition, it only supports constant
   --  indexing. It presents the abstraction of a Bingo game, where
   --  a set of Bingo balls is drawn one by one randomly from the set of
   --  available balls. A particular ball can only be drawn once in a game.

   type Bingo_Call is
     (B_1,  I_16, N_31, G_46, O_61,
      B_2,  I_17, N_32, G_47, O_62,
      B_3,  I_18, N_33, G_48, O_63,
      B_4,  I_19, N_34, G_49, O_64,
      B_5,  I_20, N_35, G_50, O_65,
      B_6,  I_21, N_36, G_51, O_66,
      B_7,  I_22, N_37, G_52, O_67,
      B_8,  I_23, N_38, G_53, O_68,
      B_9,  I_24, N_39, G_54, O_69,
      B_10, I_25, N_40, G_55, O_70,
      B_11, I_26, N_41, G_56, O_71,
      B_12, I_27, N_42, G_57, O_72,
      B_13, I_28, N_43, G_58, O_73,
      B_14, I_29, N_44, G_59, O_74,
      B_15, I_30, N_45, G_60, O_75);

   type Bingo_Game is tagged private
    with Constant_Indexing   => The_Call,
           Default_Iterator  => Iterate,
           Iterator_Element  => Bingo_Call;

   type Cursor is private;

   function Has_Element (Position : Cursor) return Boolean;

   package Bingo_Iterator is new Ada.Iterator_Interfaces
     (Cursor,
      Has_Element);

   function Iterate
     (Container : Bingo_Game)
      return      Bingo_Iterator.Forward_Iterator'Class;

   function The_Call
     (Container : Bingo_Game;
      Position  : Cursor) return Bingo_Call;

   TC_Call_History : Strings.Unbounded.Unbounded_String;
   --
   --  A string capturing the call sequence to the above subprogams.
   --  The following gets appended to the history for the above calls;
   --      Iterate  => I
   --      First    => 1
   --      Next     => N( nn)        where nn is the physical index of the
   --                                   next element
   --      Has_Element => H:{T|F}( nn)  H is the Has_Element function
   --                                     T means Has_Element returned True
   --                                     F means Has_Element returns False
   --                                      nn is the physical index

   TC_Used_Constant_Indexing : Boolean := False;

private

   type Bingo_Game is tagged null record;

   subtype Bingo_Index is
     Natural range 0 .. Bingo_Call'Pos (Bingo_Call'Last) + 1;

   type Bingo_Ball_Array is array (1 .. Bingo_Index'Last) of Bingo_Call;

   type Cursor is
      record
         Balls : Bingo_Ball_Array;
         Current_Ball : Bingo_Index;
         Count : Natural;
      end record;

end F552A00_Bingo_Balls;
