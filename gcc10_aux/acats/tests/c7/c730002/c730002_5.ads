
     --==================================================================--

with C730002_0;  use C730002_0;
with C730002_4;  use C730002_4;

package C730002_5 is

   type Inspection_Type is (AAA, MIL_STD, NRC);

   type Nuclear_Series is new Engine_Type with private;              -- (A)

   -- Inherits procedure Routine_Maintenance from ancestor; does not override.
   --                      (Engine     : in out Nuclear_Series; 
   --                       Specialist : in     Specialist_ID := Moe);
   -- But body executed will be that of C730002_4.Routine_Maintenance, 
   -- the parent type.

   function TC_Specialist         (E : Nuclear_Series) return Specialist_ID;
   function TC_Personnel_Required (E : Nuclear_Series) return Personnel_Type;
   function TC_Time_Required      (E : Nuclear_Series) return Hours_Type;

   -- Dispatching subprogram.
   procedure Maintain_The_Engine (The_Engine : in out Engine_Type'Class);

private

   type Nuclear_Series is new Electric_Series with record           -- (B)
      Inspector_Rep : Inspection_Type := NRC;
   end record;

   -- The ancestor type is used in the type extension (A), while the parent
   -- of the full type (B) is a descendent of the ancestor type, through a
   -- series of types produced by generic instantiation.

end C730002_5;
