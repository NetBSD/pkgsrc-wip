

     --===================================================================--


with FC51C00;
with BC51C02_1;
package BC51C02 is

--
-- Generics which declare a record extension of the formal private type:
--

   package Instance01 is new BC51C02_1.RecExt_No_Overrides
     (FC51C00.Abstract_Child);                                -- ERROR: {1:4;1}
                            -- Derived type in instance has primitive
                            -- subprograms that require overriding (Proc,
                            -- New_Proc, Func).


   package Instance02 is new BC51C02_1.RecExt_Overrides_Explicit
     (FC51C00.Abstract_Child);                                -- ERROR: {1:4;1}
                            -- Derived type in instance has a primitive
                            -- subprogram that requires overriding (Func).


   package Instance03 is new BC51C02_1.RecExt_Overrides_All
     (FC51C00.Abstract_Child);                                -- OK.    {1:4;1}



--
-- Generics which declare a record extension of the formal private type:
--

   package Instance04 is new BC51C02_1.PriExt_No_Overrides
     (FC51C00.Abstract_Child);                                -- ERROR: {1:4;1}
                            -- Derived type in instance has primitive
                            -- subprograms that require overriding (Proc,
                            -- New_Proc, Func).


   package Instance05 is new BC51C02_1.PriExt_Overrides_Explicit
     (FC51C00.Abstract_Child);                                -- ERROR: {1:4;1}
                            -- Derived type in instance has a primitive
                            -- subprogram that requires overriding (Func).


   package Instance06 is new BC51C02_1.PriExt_Overrides_All
     (FC51C00.Abstract_Child);                                -- OK.    {1:4;1}


end BC51C02;
