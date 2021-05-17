
     --==================================================================--

with B660002_0;
use  B660002_0;

procedure B660002 is

   -- "/=" may be overloaded for non-limited types.

   function "/=" (I1, I2 : NonLimited) return Float is          -- OK.    {4}
   begin
      return ( Float (I1) - Float (I2) );
   end "/=";

   -------------------------------------------------------------
   function "/=" (I1, I2 : Arr_Of_Booleans)
     return Arr_Of_Booleans is                                  -- OK.    {1:4}
   begin
      return ( I1(1) /= I2(1),
               I2(2) /= I2(2) );
   end "/=";

   -------------------------------------------------------------
   function "/=" (I1, I2 : NonLimited) return Access_To_Proc is -- OK.    {4}
   begin
      return Do_Something_Access;
   end "/=";

   -------------------------------------------------------------
   -- "/=" may not have a Boolean result.

   function "/=" (I1, I2 : Arr_Of_Booleans)
     return Boolean is                                          -- ERROR: {1:4}
                                                    -- Result type is Boolean.
   begin
      if ( I1(1) /= I2(1) and I2(2) /= I2(2) ) then
         return True;
      else
         return False;
      end if;
   end "/=";

   -------------------------------------------------------------
   function "/=" (I1 : NonLimited; I2 : Arr_Of_Booleans)
     return Access_To_Proc renames Not_Equal_AccToProc;         -- OK.    {1:4}

   -------------------------------------------------------------
   function "/=" (I1, I2 : NonLimited)
     return Boolean renames Not_Equal_Boolean;                  -- ERROR: {1:4}
                                                    -- Result type is Boolean.

   -------------------------------------------------------------
   -- "=" may have a result other than Boolean.

   function "=" (I1, I2 : NonLimited) return Enumeration_Type is -- OK.   {4}
   begin
      if ( Integer (I1) = Integer (I2) ) then
         return NL_True;
      else
         return NL_False;
      end if;
   end "=";

   -------------------------------------------------------------
   function "=" (I1, I2 : NonLimited)
     return Arr_Of_Booleans is                                  -- OK.    {1:4}
      Arr : Arr_Of_Booleans;
   begin
      if ( Integer (I1) = Integer (I2) ) then
         Arr := (True, False);
      else
         Arr := (False, True);
      end if;
      return Arr;
   end "=";

   --------------------------------------------------------------------------
   function "=" (I1, I2 : Record_Type)
     return Record_Type is                                      -- OK.    {1:4}
   begin
      if (I1.C = I2.C ) then
         return I1;
      else
         return I2;
      end if;
   end "=";

   --------------------------------------------------------------------------
   -- "/=" may have a result other than Boolean.

   function "/=" (I1, I2 : Integer) return Integer is           -- OK.    {4}
   begin
      if (I1 = I2 ) then
         return I1;
      else
         return I2;
      end if;
   end "/=";

   --------------------------------------------------------------------------
   function "/=" (I1, I2 : NonLimited)
     return Integer renames Equal_Integer;                      -- OK.    {1:4}

   --------------------------------------------------------------------------
   generic

      -- "/=" may have a result other than Boolean.

      with function "/=" (I1, I2 : NonLimited)
        return Integer;                                         -- OK.    {1:4}

      -- "/=" may not have a Boolean result.

      with function "/=" (I1, I2 : NonLimited)
        return Boolean;                                         -- ERROR: {1:4}
                                                    -- Result type is Boolean.

      with function "/=" (I1, I2 : Arr_Of_Booleans)
        return Boolean;                                         -- ERROR: {1:4}
                                                    -- Result type is Boolean.

   package Gen_Pck is end;

   --------------------------------------------------------------------------
   NL1, NL2   : NonLimited;
   I1,  I2    : Integer;
   R1,  R2    : Record_Type;
   Enu_Result : Enumeration_Type;
   Int_Result : Integer;
   Rec_Result : Record_Type;
   Arr_Result : Arr_Of_Booleans;

begin

   Enu_Result := NL1 /= NL2;                                    -- ERROR: {4}
                                  -- "/=" return Enumeration_Type not defined.

   Int_Result := I1  /= I2;                                     -- OK.    {4}
                                            -- "/=" return Integer is defined.

   Rec_Result := R1 /= R2;                                      -- ERROR: {4}
                                          -- "/=" return Rec_Type not defined.

   Arr_Result := NL1 /= NL2;                                    -- ERROR: {4}
                                   -- "/=" return Arr_Or_Booleans not defined.

end B660002;
