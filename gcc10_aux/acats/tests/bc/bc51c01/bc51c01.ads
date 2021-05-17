

     --===================================================================--


with FC51C00;
with BC51C01_1;
package BC51C01 is

-- Check that, for a non-abstract type derived from an abstract formal derived
-- type, all abstract primitive subprograms inherited from the actual type
-- must be overridden in the instance.

--
-- Generics which declare a record extension of the formal derived type:
--

   package Instance01 is new BC51C01_1.RecExt_Overrides_Inherited
     (FC51C00.Abstract_Child);                                -- ERROR: {1:4;1}
                            -- Derived type in instance has abstract primitive
                            -- subprograms (Proc, New_Proc).


   package Instance02 is new BC51C01_1.RecExt_Overrides_All
     (FC51C00.Abstract_Child);                                -- OK.    {1:4;1}



--
-- Generics which declare a record extension of the formal derived type:
--

   package Instance03 is new BC51C01_1.PriExt_Overrides_Inherited
     (FC51C00.Abstract_Child);                                -- ERROR: {1:4;1}
                             -- Derived type in instance has abstract primitive
                             -- subprograms (Proc, New_Proc).


   package Instance04 is new BC51C01_1.PriExt_Overrides_All
     (FC51C00.Abstract_Child);                                -- OK.    {1:4;1}


end BC51C01;
