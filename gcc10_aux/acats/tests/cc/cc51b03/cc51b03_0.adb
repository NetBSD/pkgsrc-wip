

     --==================================================================--


package body CC51B03_0 is

   package body PrivateFormalUnknownDiscriminants is
      function Is_Definite return Boolean is
      begin
         if Formal'Definite then                -- Attribute used in "if"
            -- ...Execute algorithm #1...       -- condition inside subprogram.
            return True;
         else
            -- ...Execute algorithm #2...
            return False;
         end if;
      end Is_Definite;
   end PrivateFormalUnknownDiscriminants;


   package body TaggedAncestorUnknownDiscriminants is
      function Is_Definite return Boolean is
      begin
         return Formal'Definite;                -- Attribute used in return
      end Is_Definite;                          -- statement inside subprogram.
   end TaggedAncestorUnknownDiscriminants;


end CC51B03_0;
