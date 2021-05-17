
     --=================================================================--

package CA11002_0.CA11002_1 is            -- Child package OS.Operations.

   -- Dot qualification of types, objects, etc. from parent is not required
   -- in a child unit.

   procedure Create_File (Mode : in     File_Mode:= Active_Mode;
                          File :    out File_Type);    

end CA11002_0.CA11002_1;                  -- Child package OS.Operations. 
