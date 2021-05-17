
     --==================================================================--

with B610001_0;
procedure B610001 is

   Int_Obj     : aliased Integer;

   Rec_Obj     : aliased B610001_0.Rec;
             
   Tag_Obj     : aliased B610001_0.Tag;

   TagType_Obj : aliased B610001_0.TagType;

   NTag_Obj    : aliased B610001_0.NewTag;

   NNTag_Obj   : aliased B610001_0.NNewTag;

   --------------------------------------------------------------------------
   function CW_Tag_Func (P : B610001_0.Tag'Class) 
     return B610001_0.Tag'Class is
      Operand : B610001_0.Tag'Class := P;
   begin
      return Operand;
   end CW_Tag_Func;

   --------------------------------------------------------------------------
   function CW_NTag_Func (P : B610001_0.NewTag'Class) 
     return B610001_0.NewTag'Class is
      Operand : B610001_0.NewTag'Class := P;
   begin
      return Operand;
   end CW_NTag_Func;

   --------------------------------------------------------------------------
   function CW_NNTag_Func (P : B610001_0.NNewTag'Class) 
     return B610001_0.NNewTag'Class is
      Operand : B610001_0.NNewTag'Class := P;
   begin
      return Operand;
   end CW_NNTag_Func;

   --------------------------------------------------------------------------
   function CW_TagType_Func (P : B610001_0.TagType'Class) 
     return B610001_0.TagType'Class is
      Operand : B610001_0.TagType'Class := P;
   begin
      return Operand;
   end CW_TagType_Func;

   --------------------------------------------------------------------------
   CW_Tag_Obj     : aliased B610001_0.Tag'Class     
                  := CW_Tag_Func (Tag_Obj);

   CW_NTag_Obj    : aliased B610001_0.NewTag'Class  
                  := CW_NTag_Func (NTag_Obj);

   CW_NNTag_Obj   : aliased B610001_0.NNewTag'Class 
                  := CW_NNTag_Func (NNTag_Obj);

   CW_TagType_Obj : aliased B610001_0.TagType'Class     
                  := CW_TagType_Func (TagType_Obj);
   --------------------------------------------------------------------------
   procedure Proc (P : access B610001_0.Rec) is                             
   begin
      P := new B610001_0.Rec'(C => 18);                              -- ERROR:
                                            -- Mode of access parameter is in.
   end Proc;

begin

   B610001_0.Acc_Rec_Proc (Rec_Obj'Access);                          -- OK.

   B610001_0.Acc_Rec_Proc (Rec_Obj'Unchecked_Access);                -- OK.

   B610001_0.Acc_Float_Proc (Int_Obj'Access);                        -- ERROR:
                                  -- Access parameter is not of expected type.

   B610001_0.Acc_Float_Proc (Int_Obj'Unchecked_Access);              -- ERROR:
                                  -- Access parameter is not of expected type.

   B610001_0.Acc_NTag_Proc (CW_Tag_Obj'Access);                      -- ERROR:
                                  -- Access parameter is not of expected type,
                    -- Tag'Class is not covered by nor descended from New_Tag.

   B610001_0.Acc_NTag_Proc (CW_Tag_Obj'Unchecked_Access);            -- ERROR:
                                  -- Access parameter is not of expected type,
                    -- Tag'Class is not covered by nor descended from New_Tag.

   --------------------------------------------------------------------------
   B610001_0.Acc_CW_NTag_Proc (NTag_Obj'Access);                     -- OK.

   B610001_0.Acc_CW_NTag_Proc (NTag_Obj'Unchecked_Access);           -- OK.

   B610001_0.Acc_CW_NTag_Proc (NNTag_Obj'Access);                    -- OK.

   B610001_0.Acc_CW_NTag_Proc (NNTag_Obj'Unchecked_Access);          -- OK.

   B610001_0.Acc_CW_NTag_Proc (Tag_Obj'Access);                      -- ERROR:
                                  -- Access parameter is not of expected type,
                                  -- Tag is not covered by New_Tag'Class.

   B610001_0.Acc_CW_NTag_Proc (Tag_Obj'Unchecked_Access);            -- ERROR:
                                  -- Access parameter is not of expected type,
                                  -- Tag is not covered by New_Tag'Class.

   --------------------------------------------------------------------------
   B610001_0.Acc_CW_NTag_Proc (CW_NTag_Obj'Access);                  -- OK.

   B610001_0.Acc_CW_NTag_Proc (CW_NTag_Obj'Unchecked_Access);        -- OK.

   B610001_0.Acc_CW_NTag_Proc (CW_NNTag_Obj'Access);                 -- OK.

   B610001_0.Acc_CW_NTag_Proc (CW_NNTag_Obj'Unchecked_Access);       -- OK.

   B610001_0.Acc_CW_NTag_Proc (CW_Tag_Obj'Access);                   -- ERROR:

   B610001_0.Acc_CW_NTag_Proc (CW_Tag_Obj'Unchecked_Access);         -- ERROR:
                                         -- Tag'Class covers New_Tag'Class.

   --------------------------------------------------------------------------
   B610001_0.Acc_CW_Tag_Proc (TagType_Obj'Access);                   -- ERROR:
                                 -- Access parameter is not of expected type,
                                 -- TagType is not covered by Tag'Class.

   B610001_0.Acc_CW_Tag_Proc (TagType_Obj'Unchecked_Access);         -- ERROR:
                                 -- Access parameter is not of expected type,
                                 -- TagType is not covered by Tag'Class.

   B610001_0.Acc_CW_Tag_Proc (CW_TagType_Obj'Access);                -- ERROR:
                                 -- Access parameter is not of expected type,
                                 -- TagType'Class is not covered by Tag'Class.

   B610001_0.Acc_CW_Tag_Proc (CW_TagType_Obj'Unchecked_Access);      -- ERROR:
                                 -- Access parameter is not of expected type,
                                 -- TagType'Class is not covered by Tag'Class.

end B610001;
