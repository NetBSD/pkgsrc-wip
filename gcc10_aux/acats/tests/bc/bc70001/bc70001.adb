

     --==================================================================--


with BC70001_0;  -- Template for formal package.
with BC70001_1;  -- Generic package which declares formal package.
with BC70001_2;  -- Generic subprogram.
with BC70001_3;  -- Generic package identical to template.
with BC70001_4;  -- Non-generic package.

procedure BC70001 is

   type Enum_Type    is (One, Two, Three);
   type Integer_Type is range -10 .. 10;
   type Float_Type   is digits 1;
   type Fixed_Type   is delta 0.125 range 0.0 .. 255.0;
   type Array_Type   is array (Integer_Type range 0 .. 7) of Natural;

   type Record_Type is record
      Component : String (1 .. 6);
   end record;


   procedure Gen_But_Not_Pack  is new BC70001_2 (Enum_Type);
   package   Inst_Of_Identical is new BC70001_3 (Record_Type);

   package Enum_List is new BC70001_0 (Enum_Type);
   package Char_List is new BC70001_0 (Character);
   package Bool_List is new BC70001_0 (Boolean);
   package Int_List  is new BC70001_0 (Integer_Type);
   package Flt_List  is new BC70001_0 (Float_Type);
   package Fix_List  is new BC70001_0 (Fixed_Type);
   package Arr_List  is new BC70001_0 (Array_Type);
   package Rec_List  is new BC70001_0 (Record_Type);


-- Begin legal instantiations: ---------------------------

   package Enum_Check is new BC70001_1 (Enum_List);                   -- OK.
   package Char_Check is new BC70001_1 (Char_List);                   -- OK.
   package Bool_Check is new BC70001_1 (Bool_List);                   -- OK.
   package Int_Check  is new BC70001_1 (Int_List);                    -- OK.
   package Flt_Check  is new BC70001_1 (Flt_List);                    -- OK.
   package Fix_Check  is new BC70001_1 (Fix_List);                    -- OK.
   package Arr_Check  is new BC70001_1 (Arr_List);                    -- OK.
   package Rec_Check  is new BC70001_1 (Rec_List);                    -- OK.

-- End legal instantiations. -----------------------------

-- Begin illegal instantiations: -------------------------

   package Template      is new BC70001_1 (BC70001_0);                -- ERROR:
                                         -- Actual is not instance of template.

   package Wrong_Package is new BC70001_1 (Inst_Of_Identical);        -- ERROR:
                                         -- Actual is not instance of template.

   package Not_Package   is new BC70001_1 (Gen_But_Not_Pack);         -- ERROR:
                                         -- Actual is not instance of template.

   package Not_Generic   is new BC70001_1 (BC70001_4);                -- ERROR:
                                         -- Actual is not instance of template.

-- End illegal instantiations. ---------------------------

begin
   null;
end BC70001;
