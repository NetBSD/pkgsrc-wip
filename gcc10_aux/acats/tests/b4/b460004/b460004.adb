
     --==================================================================--

with B460004_0;

procedure B460004 is

   Tag_Type_Operand   : B460004_0.Tag_Type;
   DTag_Type_Operand  : B460004_0.DTag_Type;
   DDTag_Type_Operand : B460004_0.DDTag_Type;

   Tag_Type_Target    : B460004_0.Tag_Type;
   DTag_Type_Target   : B460004_0.DTag_Type;
   DDTag_Type_Target  : B460004_0.DDTag_Type;

   Acc_Tag_Operand   : B460004_0.Acc_Tag;
   Acc_DTag_Operand  : B460004_0.Acc_DTag;
   Acc_DDTag_Operand : B460004_0.Acc_DDTag;

   Acc_Tag_Target    : B460004_0.Acc_Tag;   
   Acc_DTag_Target   : B460004_0.Acc_DTag;
   Acc_DDTag_Target  : B460004_0.Acc_DDTag;

   --------------------------------------------------------------------------

   function CW_Tag_Func (P : B460004_0.Tag_Type'Class) 
     return B460004_0.Tag_Type'Class is
      Operand : B460004_0.Tag_Type'Class := P;
   begin
      return Operand;
   end CW_Tag_Func;

   --------------------------------------------------------------------------

   function CW_DTag_Func (P : B460004_0.DTag_Type'Class) 
     return B460004_0.DTag_Type'Class is
      Operand : B460004_0.DTag_Type'Class := P;
   begin
      return Operand;
   end CW_DTag_Func;

   --------------------------------------------------------------------------

   function CW_DDTag_Func (P : B460004_0.DDTag_Type'Class) 
     return B460004_0.DDTag_Type'Class is
      Operand : B460004_0.DDTag_Type'Class := P;
   begin
      return Operand;
   end CW_DDTag_Func;

   --------------------------------------------------------------------------

   CW_Tag_Type_Operand   : B460004_0.Tag_Type'Class
                         := CW_Tag_Func (Tag_Type_Target);
   CW_DTag_Type_Operand  : B460004_0.DTag_Type'Class
                         := CW_DTag_Func (DTag_Type_Target);
   CW_DDTag_Type_Operand : B460004_0.DDTag_Type'Class
                         := CW_DDTag_Func (DDTag_Type_Target);

begin

   Tag_Type_Target   := B460004_0.Tag_Type (DTag_Type_Operand);       -- OK.
                            -- Operand type is a descendant of the target type.

   Tag_Type_Target   := B460004_0.Tag_Type (DDTag_Type_Operand);      -- OK.
                            -- Operand type is a descendant of the target type.

   DTag_Type_Target  := B460004_0.DTag_Type (DDTag_Type_Operand);     -- OK.
                            -- Operand type is a descendant of the target type.

   DTag_Type_Target  := B460004_0.DTag_Type (Tag_Type_Operand);       -- ERROR:
                             -- Operand type is not descended from target type.
 
   DDTag_Type_Target := B460004_0.DDTag_Type (Tag_Type_Operand);      -- ERROR:
                             -- Operand type is not descended from target type.

   DDTag_Type_Target := B460004_0.DDTag_Type (DTag_Type_Operand);     -- ERROR:
                             -- Operand type is not descended from target type.

   --------------------------------------------------------------------------

   Tag_Type_Target   := B460004_0.Tag_Type
                     (B460004_0.DTag_Type'Class(DDTag_Type_Operand)); -- OK.
                        -- Operand type is class-wide covering the target type.

   DTag_Type_Target  := B460004_0.DTag_Type 
                     (B460004_0.Tag_Type'Class(Tag_Type_Operand));    -- OK.
                        -- Operand type is class-wide covering the target type.

   DTag_Type_Target  := B460004_0.DTag_Type 
                     (B460004_0.DTag_Type'Class(DDTag_Type_Operand)); -- OK.
                        -- Operand type is class-wide covering the target type.

   DDTag_Type_Target := B460004_0.DDTag_Type 
                     (B460004_0.Tag_Type'Class(Tag_Type_Operand));    -- OK.
                        -- Operand type is class-wide covering the target type.

   DDTag_Type_Target := B460004_0.DDTag_Type 
                     (B460004_0.Tag_Type'Class(DTag_Type_Operand));   -- OK.
                        -- Operand type is class-wide covering the target type.

   --------------------------------------------------------------------------

   DTag_Type_Target  := B460004_0.DTag_Type (CW_Tag_Type_Operand);    -- OK.
                            -- Operand type is a descendant of the target type.

   DDTag_Type_Target := B460004_0.DDTag_Type (CW_Tag_Type_Operand);   -- OK.

   DDTag_Type_Target := B460004_0.DDTag_Type (CW_DTag_Type_Operand);  -- OK.

   Tag_Type_Target   := B460004_0.Tag_Type (CW_DTag_Type_Operand);    -- OK.
                            -- Operand type is a descendant of the target type.

   Tag_Type_Target   := B460004_0.Tag_Type (CW_DDTag_Type_Operand);   -- OK.
                            -- Operand type is a descendant of the target type.

   DTag_Type_Target  := B460004_0.DTag_Type (CW_DDTag_Type_Operand);  -- OK.
                            -- Operand type is a descendant of the target type.

   --------------------------------------------------------------------------

   Acc_Tag_Target   := B460004_0.Acc_Tag (Acc_DTag_Operand);          -- OK.
                            -- Operand type is a descendant of the target type.

   Acc_Tag_Target   := B460004_0.Acc_Tag (Acc_DDTag_Operand);         -- OK.
                            -- Operand type is a descendant of the target type.

   Acc_DTag_Target  := B460004_0.Acc_DTag (Acc_DDTag_Operand);        -- OK.
                            -- Operand type is a descendant of the target type.

   Acc_DTag_Target  := B460004_0.Acc_DTag (Acc_Tag_Operand);          -- ERROR:
                           -- Operand type is not convertible from target type.
 
   Acc_DDTag_Target := B460004_0.Acc_DDTag (Acc_Tag_Operand);         -- ERROR:
                           -- Operand type is not convertible from target type.

   Acc_DDTag_Target := B460004_0.Acc_DDTag (Acc_DTag_Operand);        -- ERROR:
                           -- Operand type is not convertible from target type.

end B460004;
