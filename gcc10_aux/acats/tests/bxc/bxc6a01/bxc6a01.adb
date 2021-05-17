

     --==================================================================--


with FXC6A00;
with BXC6A01_0;

procedure BXC6A01 is

   type Byzantine is new FXC6A00.Roman;
   pragma Atomic (Byzantine);                                  -- N/A => ERROR.
          -- Implementation must reject this pragma if it does not support
          -- indivisible read/write for Byzantine objects.  

   procedure Byzantine_Formal (X: Byzantine) is
   begin
      null;
   end Byzantine_Formal;


   A01 : FXC6A00.Private_Type;
   pragma Volatile (A01);

   A02 : FXC6A00.Volatile_Record;
   pragma Volatile (A02);

   A03 : FXC6A00.Array_Type;

   A04 : FXC6A00.Array_Type;
   pragma Volatile (A04);

   A05 : array (1 .. 5) of FXC6A00.Lim_Private_Type;
   pragma Volatile_Components (A05);

   A06 : FXC6A00.Composite_Type;
   pragma Volatile (A06);

   A07 : Byzantine;
   pragma Volatile (A07);

   A08 : FXC6A00.Record_Type;
   pragma Volatile (A08);

   A09 : FXC6A00.Protected_Type;
   pragma Volatile (A09);

   A10 : Boolean;
   pragma Atomic (A10);                                        -- N/A => ERROR.
          -- Implementation must reject this pragma if it does not support
          -- indivisible read/write for Boolean objects.  

   A11 : FXC6A00.Roman;
   pragma Atomic (A11);                                        -- N/A => ERROR.
          -- Implementation must reject this pragma if it does not support
          -- indivisible read/write for Roman objects.  

   A12 : array (1 .. 7) of FXC6A00.Roman;
   pragma Atomic_Components (A12);                             -- N/A => ERROR.
          -- Implementation must reject this pragma if it does not support
          -- indivisible read/write for Roman objects.  

   A13 : BXC6A01_0.Scalar;
begin

   BXC6A01_0.Private_Formal (A01);                                    -- ERROR:
                    -- Formal parameter is of a non-volatile by-reference type.
   
   BXC6A01_0.Vol_Record_Formal (A02);                                 -- OK.
                     -- Formal parameter is of a volatile by-reference type.

   BXC6A01_0.Tagged_Formal (A03(1));                                  -- ERROR:
                    -- Formal parameter is of a non-volatile by-reference type.

   BXC6A01_0.Array_Formal (A04);                                      -- ERROR:
                    -- Formal parameter is of a non-volatile by-reference type.

   BXC6A01_0.Lim_Private_Formal (A05(4));                             -- OK.
                      -- Formal parameter is of a non-volatile by-copy type.

   BXC6A01_0.Tagged_Formal (A06.C);                                   -- ERROR:
                    -- Formal parameter is of a non-volatile by-reference type.

   Byzantine_Formal (A07);                                            -- OK.
                      -- Formal parameter is of a non-volatile by-copy type.
             -- NOTE: if pragma Atomic is rejected for Byzantine, this case
             --       need NOT be flagged as legal.

   BXC6A01_0.Record_Formal (A08);                                     -- OK.
     -- Formal parameter is of a non-volatile type that allows pass-by-copy.

   BXC6A01_0.Protected_Formal (A09);                                  -- ERROR:
                    -- Formal parameter is of a non-volatile by-reference type.

   BXC6A01_0.Boolean_Formal (A10);                                    -- OK.
                      -- Formal parameter is of a non-volatile by-copy type.
                   -- NOTE: if pragma Atomic is rejected for A10, this case
                   --       need NOT be flagged as legal.

   BXC6A01_0.Roman_Formal (A11);                                      -- OK.
                      -- Formal parameter is of a non-volatile by-copy type.
                   -- NOTE: if pragma Atomic is rejected for A11, this case
                   --       need NOT be flagged as legal.

   BXC6A01_0.Roman_Formal (A12(6));                                   -- OK.
                      -- Formal parameter is of a non-volatile by-copy type.
        -- NOTE: if pragma Atomic_Components is rejected for A12, this case
        --       need NOT be flagged as legal.

   BXC6A01_0.New_Scalar_Formal (BXC6A01_0.New_Scalar(A13));           -- OK.

end BXC6A01;
