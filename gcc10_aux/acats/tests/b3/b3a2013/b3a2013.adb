 

     --==================================================================--


package body B3A2013 is

   task body Task_Type is
      -- Current instance of a limited type is aliased. 
         C : AccTaskType := Task_Type'Access;                         -- ERROR:
                       -- Accessibility level of the current instance Task_Type
                       -- could be deeper than the level of AccTaskType.
                       -- Assume-the-worst checking.
   begin
      null;
   end Task_Type;

                      -------------------------------------


   package Nested is

   --
   -- Types with access discriminants, and associated types:
   --

      type OuterA is tagged limited private;
      type InnerA (Ptr : access OuterA'Class) is tagged limited null record;
      type AccOuterA is access OuterA;

      type OuterB is tagged limited private;
      type InnerB (Ptr : access OuterB) is limited null record;
      type AccInnerB is access InnerB;
 
      type Lim_Priv is limited private;
 
      type AccInt is access all Integer;

      type Rec (Ptr : access Integer) is limited private;
      type AccRec is access all Rec;
      function Func1 (P : access Rec) return Boolean;
      function Func2 (P : AccRec) return Boolean;

   private

      type OuterA is tagged limited record
      -- Current instance of a limited type is aliased. 
         C : InnerA (OuterA'Access);                                  -- OK.
      end record;

      type OuterB is tagged limited record
      -- Current instance of a limited type is aliased. 
         C : AccInnerB := new InnerB (OuterB'Access);                 -- ERROR:
                          -- Accessibility level of the current instance OuterB
                          -- could be deeper than the level of AccInnerB.
                          -- Assume-the-worst checking.
      end record;

      type AccPriv is access all Lim_Priv;
 
      type Lim_Priv is limited record
      -- Current instance of a limited type is aliased. 
         C : AccPriv := Lim_Priv'Access;                              -- ERROR:
                        -- Accessibility level of the current instance Lim_Priv
                        -- could be deeper than the level of AccPriv.
                        -- Assume-the-worst checking.
      end record;

      type Rec (Ptr : access Integer) is limited record
         C1 : Boolean := Func1 (Rec'Access);                          -- OK.
                                                           -- LM 3.10.2(19);6.0
         C2 : AccInt  := AccInt (Ptr);                                -- ERROR:
                           -- Possibility of a deeper level declaration of Rec.
                           -- Assume-the-worst checking.

         C3 : Boolean := Func2 (Rec'Access);                          -- ERROR:
                           -- Possibility of a deeper level declaration of Rec.
                           -- Assume-the-worst checking.      
      end record;

   end Nested;

                      -------------------------------------

   package body Nested is

      function Func1 (P : access Rec) return Boolean is
      begin
         return True;
      end Func1;


      function Func2 (P : AccRec) return Boolean is
      begin
         return False;
      end Func2;

   end Nested;
             

end B3A2013;
