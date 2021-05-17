

     --==================================================================--


with B460002_0;
with B460002_1;
with B460002_2;
with B460002_3;
with B460002_4;
with B460002_5;
with B460002_6;

procedure B460002 is                                           -- [ Level = 1 ]


   type External_Operand_Type_L1 is access all B460002_0.Tagged_Type;
   type External_Target_Type_L1  is access all B460002_0.Tagged_Type;

   Operand_L1 : External_Operand_Type_L1 := new B460002_0.Tagged_Type;

   -- Level of derived access type is that of its ultimate ancestor, so
   -- the level of this type is 0, even though it is derived at level 1:
   type Derived_Operand_Type_L0 is new B460002_0.External_Operand_Type_L0;


   -- The following instantiation is illegal because the level of the operand
   -- type (which is that of the instance = 1) is deeper than that of the
   -- target type (0):

   package B460002_2_InstanceL1 is new B460002_2
     (Designated_Type         => B460002_0.Tagged_Type,
      Formal_Target_Type      => B460002_0.External_Target_Type_L0);  -- ERROR:
               -- Accessibility level of operand type in access type conversion
               -- deeper than that of target type.

begin -- B460002.                                              -- [ Level = 1 ]

   declare                                                     -- [ Level = 2 ]

      type External_Operand_Type_L2  is access all B460002_0.Tagged_Type;
      Operand_L2 :  External_Operand_Type_L2;

      AccDisc_L2 :  B460002_0.Disc_Record_Type(B460002_0.Tag_Object'Access);


      -- The following instantiation is illegal because the level of the
      -- operand type (which is that of AccDisc_L2 = 2) is deeper than
      -- that of the target type (0):

      package B460002_3_InstanceL2 is new B460002_3
        (Formal_Disc_Record_Type => B460002_0.Disc_Record_Type,
         Formal_AccDisc          => AccDisc_L2);                      -- ERROR:
               -- Accessibility level of operand type in access type conversion
               -- deeper than that of target type.


      -- The following instantiation is illegal because the level of the
      -- operand type (1) is deeper than that of the target type (0):

      package B460002_4_InstanceL2 is new B460002_4
        (Designated_Type         => B460002_0.Tagged_Type,
         Formal_Operand_Type     => External_Operand_Type_L1);        -- ERROR:
               -- Accessibility level of operand type in access type conversion
               -- deeper than that of target type.

      -- The following instantiation is legal because the level of the 
      -- operand type is no deeper than that of the target type (0):

      package B460002_4_Instance is new B460002_4
        (Designated_Type         => B460002_0.Tagged_Type,
         Formal_Operand_Type     => Derived_Operand_Type_L0);          -- OK.

   begin
      declare                                                  -- [ Level = 3 ]

         -- The following instantiation is legal because in all cases the
         -- level of the operand type is no deeper than that of the target
         -- type (which is that of the instance = 3):

         package B460002_1_InstanceL3 is new B460002_1
           (Designated_Type         => B460002_0.Tagged_Type,
            Formal_Operand_Type     => External_Operand_Type_L1,
            Formal_Operand          => Operand_L1,
            Formal_Disc_Record_Type => B460002_0.Disc_Record_Type,
            Formal_AccDisc          => AccDisc_L2);                   -- OK.


         -- The following instantiation is illegal because the level of the
         -- operand type (2) is deeper than that of the target type (1):

         package B460002_5_InstanceL3 is new B460002_5
           (Designated_Type         => B460002_0.Tagged_Type,
            Formal_Operand_Type     => External_Operand_Type_L2,
            Formal_Operand          => Operand_L2,
            Formal_Target_Type      => External_Target_Type_L1);      -- ERROR:
               -- Accessibility level of operand type in access type conversion
               -- deeper than that of target type.


         -- The following instantiation is illegal because the level of the
         -- operand type (which is that of AccDisc_L2 = 2) is deeper than that
         -- of the target type (1):

         package B460002_6_InstanceL3 is new B460002_6
           (Designated_Type         => B460002_0.Tagged_Type,
            Formal_Target_Type      => External_Target_Type_L1,
            Formal_Disc_Record_Type => B460002_0.Disc_Record_Type,
            Formal_AccDisc          => AccDisc_L2);                   -- ERROR:
               -- Accessibility level of operand type in access type conversion
               -- deeper than that of target type.

      begin
         null;
      end;

   end;

end B460002;
