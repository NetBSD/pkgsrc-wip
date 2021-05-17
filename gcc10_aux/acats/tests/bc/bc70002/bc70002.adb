

     --==================================================================--


with BC70002_0;  -- Template for formal package.
with BC70002_1;  -- Generic subprogram which declares formal package.
with BC70002_2;  -- Generic package.
with BC70002_3;  -- Generic package identical to template.
with BC70002_4;  -- Non-generic package.

procedure BC70002 is

   type Enum_Type    is (One, Two, Three);
   type Integer_Type is range -10 .. 10;
   type Float_Type   is digits 1;
   type Fixed_Type   is delta 0.125 range 0.0 .. 255.0;
   type Array_Type   is array (Integer_Type range 0 .. 7) of Natural;

   type Record_Type is record
      Component : String (1 .. 6);
   end record;


   procedure Gen_But_Not_Pack  is new BC70002_2 (Enum_Type);
   package   Inst_Of_Identical is new BC70002_3 (Record_Type);

   package Enum_List is new BC70002_0 (Enum_Type);
   package Char_List is new BC70002_0 (Character);
   package Bool_List is new BC70002_0 (Boolean);
   package Int_List  is new BC70002_0 (Integer_Type);
   package Flt_List  is new BC70002_0 (Float_Type);
   package Fix_List  is new BC70002_0 (Fixed_Type);
   package Arr_List  is new BC70002_0 (Array_Type);
   package Rec_List  is new BC70002_0 (Record_Type);


-- Begin legal instantiations: ---------------------------

   procedure Enum_Check is new BC70002_1 (Enum_List);                 -- OK.
   procedure Char_Check is new BC70002_1 (Char_List);                 -- OK.
   procedure Bool_Check is new BC70002_1 (Bool_List);                 -- OK.
   procedure Int_Check  is new BC70002_1 (Int_List);                  -- OK.
   procedure Flt_Check  is new BC70002_1 (Flt_List);                  -- OK.
   procedure Fix_Check  is new BC70002_1 (Fix_List);                  -- OK.
   procedure Arr_Check  is new BC70002_1 (Arr_List);                  -- OK.
   procedure Rec_Check  is new BC70002_1 (Rec_List);                  -- OK.

-- End legal instantiations. -----------------------------

-- Begin illegal instantiations: -------------------------

   procedure Template      is new BC70002_1 (BC70002_0);              -- ERROR:
                                      -- Actual is not an instance of template.

   procedure Wrong_Package is new BC70002_1 (Inst_Of_Identical);      -- ERROR:
                                      -- Actual is not an instance of template.

   procedure Not_Package   is new BC70002_1 (Gen_But_Not_Pack);       -- ERROR:
                                      -- Actual is not an instance of template.

   procedure Not_Generic   is new BC70002_1 (BC70002_4);              -- ERROR:
                                      -- Actual is not an instance of template.

-- End illegal instantiations. ---------------------------

begin
   null;
end BC70002;
