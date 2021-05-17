

     --===================================================================--


with BC54003_1;
with BC54003_2;
package BC54003_4 is

--
-- Support declarations:
--

   type Rec     is record null; end record;
   type Rec_Ptr is access Rec;

   type    Count is new Natural range 0 .. 100;

   type    Table     is array (Count) of Rec_Ptr;
   subtype Sub_Table is Table;
   type    New_Table is new Table;

   type Array_Op_Ptr is access function            -- Access-to-subprogram type
     (P: Table; Q: Count) return Rec_Ptr;          -- to be passed as actual.



   type Dollars is new Integer range 0 .. 5000;
   subtype Thousand is Dollars range 0 .. 1000;

   package Rec_Tables   is new BC54003_1 (Rec_Ptr, Count, Table);
   package Sub_Tables   is new BC54003_1 (Rec_Ptr, Count, Sub_Table);
   package New_Tables   is new BC54003_1 (Rec_Ptr, Count, New_Table);

   package Dollar_Support_1 is new BC54003_2 (Rec_Tables, Dollars);
   package Dollar_Support_2 is new BC54003_2 (Sub_Tables, Dollars);
   package Dollar_Support_3 is new BC54003_2 (New_Tables, Dollars);

   package Thousand_Support is new BC54003_2 (Rec_Tables, Thousand);
   package Integer_Support  is new BC54003_2 (Rec_Tables, Integer);

   type Dollar_Op_Ptr is access function           -- Access-to-subprogram type
     (Left, Right: Dollars) return Dollars;        -- to be passed as actual.


end BC54003_4;
