
package body B7400030 is

   Null_List_Body : constant List_Of_Priv_Comp; -- POSSIBLE ERROR: [Set1] {4;1}
                                           --   Deferred constant in body.
   CRec_Body : constant Rec;               -- POSSIBLE ERROR: [Set2] {4;1}
                                           --   Deferred constant in body.

   Null_List_Body : constant List_Of_Priv_Comp :=
      (1 .. 0 => Anything);                -- POSSIBLE ERROR: [Set1] {1:4;1}
                                           -- Completion of deferred constant
                                           -- in body.

   CRec_Body : constant Rec := (C => 12);  -- POSSIBLE ERROR: [Set2] {4;1}
                                           -- Completion of deferred constant
                                           -- in body.


   procedure Dummy is
      CRec_Sub : constant Rec;             -- POSSIBLE ERROR: [Set3] {7;1}
                                           -- Deferred constant in subprogram.

      CRec_Sub : constant Rec := (C => 18);-- POSSIBLE ERROR: [Set3] {7;1}
                                           -- Completion of deferred constant
                                           -- in subprogram.
      package Goofy is
         CRec_Nest : constant Rec;
      private
         CRec_Nest : constant Rec := (C => 18); -- OK. {10;1}
      end Goofy;
   begin
      declare
         CRec_Sub : constant Rec;          -- POSSIBLE ERROR: [Set4] {10;1}
                                           -- Deferred constant in block.

         CRec_Sub : constant Rec := (C => 92);-- POSSIBLE ERROR: [Set4] {10;1}
                                           -- Completion of deferred
                                           -- constant in block.
      begin
         null;
      end;
   end Dummy;

end B7400030;
