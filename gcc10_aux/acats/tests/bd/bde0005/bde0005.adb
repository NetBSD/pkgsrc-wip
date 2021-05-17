
     --==================================================================--


package body BDE0005 is

   procedure Op1 (P : Tag_Type) is
   begin
      null;
   end Op1;    
   ---------------------------------------------

   procedure Op2 (P : Tag_Type) is                                    -- OK.
   begin
      null;
   end Op2;    

   ---------------------------------------------
   type NTag_T1 is new Tag_Type with null record;       
   -- implicit procedure Op1 (P : NTag_T1) declared here
   -- implicit procedure Op2 (P : NTag_T1) declared here

   procedure Op1 (P : NTag_T1);                     -- Overrides.
   procedure Op2 (P : NTag_T1);                     -- Overrides.

   ---------------------------------------------
   procedure Op1 (P : NTag_T1) is
   begin
      null;
   end Op1;    

   ---------------------------------------------
   procedure Op2 (P : NTag_T1) is  
   begin 
      null;
   end Op2;    

   ---------------------------------------------
   type NTag_T2 is new Tag_Type with null record;       
   -- implicit procedure Op1 (P : NTag_T2) declared here
   -- implicit procedure Op2 (P : NTag_T2) declared here

   procedure Op1 (P : NTag_T2) is                   -- Freezes NTag_T2.
   -- overrides inherited Op1 (P1 : NTag_T2)
   begin
      null;
   end Op1;    

   ---------------------------------------------
   procedure Op2 (P : NTag_T2) is                                     -- ERROR:
                              -- Primitive declaration of a frozen tagged type.
   begin 
      null;
   end Op2;    

end BDE0005;
