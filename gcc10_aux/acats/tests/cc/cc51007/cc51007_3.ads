

     --===================================================================--


with CC51007_0;
generic
   type Alert_Type is new CC51007_0.Alert with private;
   Initial_State : in Alert_Type;
package CC51007_3 is

   function Clear_Message (A: Alert_Type)                -- Function returning
     return Alert_Type;                                  -- formal type.


   Max_Note : Natural := 10;
   type Note is new String (1 .. Max_Note);

   type Extended_Alert is new Alert_Type with record
      Addendum : Note := (others => '*');
   end record;

   -- In instance, inherits version of Handle from
   -- actual corresponding to formal type.

   function Annotate_Alert (A: in Alert_Type'Class)      -- Function returning
     return Extended_Alert;                              -- derived type.


   Init_Ext_Alert : constant Extended_Alert     :=       -- Object declaration.
     (Initial_State with Addendum => "----------");      -- Aggregate.


   type Alert_Type_Ptr is access constant Alert_Type;
   type Ext_Alert_Ptr  is access          Extended_Alert;

   Init_Alert_Ptr     : Alert_Type_Ptr := 
     new Alert_Type'(Initial_State);                        -- Allocator.

   Init_Ext_Alert_Ptr : Ext_Alert_Ptr  :=
     new Extended_Alert'(Init_Ext_Alert);                -- Allocator.


   type Alert_Pair is record
      A  : Alert_Type;                                   -- Component.
      EA : Extended_Alert;                               -- Component.
   end record;

end CC51007_3;
