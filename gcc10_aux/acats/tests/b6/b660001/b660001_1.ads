
     --==================================================================--

with B660001_0;
use  B660001_0;

package B660001_1 is

   -- Check explicit overloading of "/=".

   function "/=" (I1, I2 : Private_Type) return Record_Type;         -- OK.

   function "/=" (I1, I2 : Private_Type) return Boolean;             -- ERROR:
                                                    -- Result type is Boolean.

   function "/=" (I1, I2 : Limited_Private) return Enum_Type;        -- OK.

   function "/=" (I1, I2 : Limited_Private) return Boolean;          -- ERROR:
                                                    -- Result type is Boolean.

   function "/=" (I1, I2 : Private_Type)    
     return Float renames Not_Equal_Float;                           -- OK.

   function "/=" (I1, I2 : Limited_Private)    
     return Enum_Type renames Not_Equal_Enum;                        -- OK.

   function "/=" (I1, I2 : Private_Type)    
     return Boolean renames Not_Equal_Boolean_PT;                    -- ERROR:
                                                    -- Result type is Boolean.

   function "/=" (I1, I2 : Limited_Private) 
     return Boolean renames Not_Equal_Boolean_LP;                    -- ERROR:
                                                    -- Result type is Boolean.

   --------------------------------------------------------------------------
   function "=" (I1, I2 : Private_Type) return Boolean;              -- OK.

   -- Check that "=" may have a non Boolean result.

   function "=" (I1, I2 : Private_Type) return Record_Type;          -- OK.

   function "=" (I1, I2 : Limited_Private) return Access_To_Proc;    -- OK.

   function "=" (I1 : Limited_Private; I2 : Private_Type)          
     return Enum_Type;                                               -- OK.

   -- Check that "=" may rename a function other than an equality operator.

   function "=" (I1, I2 : Limited_Private) 
     return Integer renames Equal_Integer;                           -- OK.

   function "=" (I1, I2 : Private_Type)    
     return Boolean renames Equal_Boolean;                           -- OK.

   --------------------------------------------------------------------------
   generic

      -- "/=" may have a result other than Boolean.

      with function "/=" (I1, I2 : Limited_Private) 
        return Integer;                                              -- OK.

      -- "/=" may not have a Boolean result.

      with function "/=" (I1, I2 : Limited_Private) 
        return Boolean;                                              -- ERROR:
                                                    -- Result type is Boolean.

      with function "/=" (I1, I2 : Private_Type)    
        return Boolean;                                              -- ERROR:
                                                    -- Result type is Boolean.

   package Gen_Pck is end;

   package New_Pak_1 is new Gen_Pak(Boolean);                        -- ERROR:
                                      -- overloaded "/=" cannot return Boolean

   function Equal(L,R: Enum_Type) return Enum_Type;

   package New_Pak_2 is new Gen_Pak(Enum_Type,Equal);                -- OK.

end B660001_1;
