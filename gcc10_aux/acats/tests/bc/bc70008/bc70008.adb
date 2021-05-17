

     --==================================================================--


with BC70008_0;         -- Template for formal package.
with BC70008_1;         -- Generic subprogram which declares formal package.
with BC70008_2;         -- Generic package.
with BC70008_3;         -- Generic package identical to template.
with BC70008_Rename_4;  -- Renamed non-generic package.

procedure BC70008 is

   type Enum_Type    is (One, Two, Three);
   type Integer_Type is range -10 .. 10;
   type Float_Type   is digits 1;
   type Fixed_Type   is delta 0.125 range 0.0 .. 255.0;
   type Array_Type   is array (Integer_Type range 0 .. 7) of Natural;

   type Record_Type is record
      Component : String (1 .. 6);
   end record;


   procedure Generic_Subprogram is new BC70008_2 (Enum_Type);
   procedure Gen_But_Not_Pack renames Generic_Subprogram;  -- Renaming decl.

   package Identical_Instance is new BC70008_3 (Record_Type);
   package Inst_Of_Identical renames Identical_Instance;   -- Renaming decl.

   generic package Template_Rename renames BC70008_0;      -- Renaming decl.


   package Enum_L is new Template_Rename (Enum_Type);
   package Char_L is new BC70008_0       (Character);
   package Bool_L is new Template_Rename (Boolean);
   package Int_L  is new BC70008_0       (Integer_Type);
   package Flt_L  is new BC70008_0       (Float_Type);
   package Fix_L  is new Template_Rename (Fixed_Type);
   package Arr_L  is new Template_Rename (Array_Type);
   package Rec_L  is new BC70008_0       (Record_Type);


-- Renaming declarations:

   package Enum_List renames Enum_L;
   package Char_List renames Char_L;
   package Bool_List renames Bool_L;
   package Int_List  renames Int_L;
   package Flt_List  renames Flt_L;
   package Fix_List  renames Fix_L;
   package Arr_List  renames Arr_L;
   package Rec_List  renames Rec_L;

-- Begin legal instantiations: ---------------------------

   -- Check that if the formal package actual part is (<>),
   -- the actual corresponding to a generic formal package
   -- may be any instance of the generic named in the
   -- formal package declaration.

   procedure Enum_Check is new BC70008_1 (Enum_List);                 -- OK.
   procedure Char_Check is new BC70008_1 (Char_List);                 -- OK.
   procedure Bool_Check is new BC70008_1 (Bool_List);                 -- OK.
   procedure Int_Check  is new BC70008_1 (Int_List);                  -- OK.
   procedure Flt_Check  is new BC70008_1 (Flt_List);                  -- OK.
   procedure Fix_Check  is new BC70008_1 (Fix_List);                  -- OK.
   procedure Arr_Check  is new BC70008_1 (Arr_List);                  -- OK.
   procedure Rec_Check  is new BC70008_1 (Rec_List);                  -- OK.

-- End legal instantiations. -----------------------------

-- Begin illegal instantiations: -------------------------

   procedure Template      is new BC70008_1 (Template_Rename);        -- ERROR:
                                      -- Actual is not an instance of template.

   procedure Wrong_Package is new BC70008_1 (Inst_Of_Identical);      -- ERROR:
                                      -- Actual is not an instance of template.

   procedure Not_Package   is new BC70008_1 (Gen_But_Not_Pack);       -- ERROR:
                                      -- Actual is not an instance of template.

   procedure Not_Generic   is new BC70008_1 (BC70008_Rename_4);       -- ERROR:
                                      -- Actual is not an instance of template.

-- End illegal instantiations. ---------------------------

begin
   null;
end BC70008;
