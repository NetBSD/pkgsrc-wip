

     --===================================================================--


with BC54003_0;
with BC54003_3;
with BC54003_4;
package BC54003 is

--
-- Instantiations:
--


   -- Parameter in profile is a formal derived type:

   package Instance01 is new BC54003_3.Formal_Derived_Parameter
     (BC54003_0.Child, BC54003_0.Child_Op_Ptr);                       -- OK.


   package Instance02 is new BC54003_3.Formal_Derived_Parameter
     (BC54003_0.Parent, BC54003_0.Child_Op_Ptr);                      -- ERROR:
                    -- Parameters in designated profiles do not have same type.

   package Instance03 is new BC54003_3.Formal_Derived_Parameter
     (BC54003_0.Parent, BC54003_0.Class_Op_Ptr);                      -- ERROR:
                    -- Parameters in designated profiles do not have same type.

   package Instance04 is new BC54003_3.Formal_Derived_Parameter
     (BC54003_0.Child'Class, BC54003_0.Child_Op_Ptr);                 -- ERROR:
                    -- Parameters in designated profiles do not have same type.

   package Instance05 is new BC54003_3.Formal_Derived_Parameter
     (BC54003_0.Parent'Class, BC54003_0.Class_Op_Ptr);                -- OK.



   -- Parameter in profile is a formal private type:

   package Instance06 is new BC54003_3.Formal_Private_Parameter
     (String, BC54003_0.String_Op_Ptr);                               -- OK.


   package Instance07 is new BC54003_3.Formal_Private_Parameter
     (String, BC54003_0.Message_Op_Ptr);                              -- ERROR:
                  -- Profile is mode conformant, but not subtype conformant.
                  -- Changed by AI05-0288-1, OK in Ada 95.

   package Instance08 is new BC54003_3.Formal_Private_Parameter
     (BC54003_0.Message, BC54003_0.String_Op_Ptr);                    -- ERROR:
                  -- Profile is mode conformant, but not subtype conformant.
                  -- Changed by AI05-0288-1, OK in Ada 95.


   package Instance09 is new BC54003_3.Formal_Private_Parameter
     (BC54003_0.Message, BC54003_0.Message_Op_Ptr);                   -- OK.


   package Instance10 is new BC54003_3.Formal_Private_Parameter
     (BC54003_0.New_String, BC54003_0.String_Op_Ptr);                 -- ERROR:
                    -- Parameters in designated profiles do not have same type.

   package Instance11 is new BC54003_3.Formal_Private_Parameter
     (BC54003_0.New_String, BC54003_0.Message_Op_Ptr);                -- ERROR:
                    -- Parameters in designated profiles do not have same type.

   package Instance12 is new BC54003_3.Formal_Private_Parameter
     (BC54003_0.Short_Msg, BC54003_0.Message_Op_Ptr);                 -- ERROR:
                  -- Profile is mode conformant, but not subtype conformant.
                  -- Changed by AI05-0288-1, OK in Ada 95.



   -- Parameter in profile is a formal discrete type
   -- (one level of indirection through formal package):

   package Instance13 is new BC54003_3.Formal_Discrete_Parameter
     (BC54003_4.Dollar_Support_1, BC54003_4.Dollar_Op_Ptr);           -- OK.

   package Instance14 is new BC54003_3.Formal_Discrete_Parameter
     (BC54003_4.Thousand_Support, BC54003_4.Dollar_Op_Ptr);           -- ERROR:
                  -- Profile is mode conformant, but not subtype conformant.
                  -- Changed by AI05-0288-1, OK in Ada 95.

   package Instance15 is new BC54003_3.Formal_Discrete_Parameter
     (BC54003_4.Integer_Support, BC54003_4.Dollar_Op_Ptr);            -- ERROR:
                    -- Parameters in designated profiles do not have same type.



   -- Parameter in profile is a formal array type
   -- (two levels of indirection through formal packages):

   package Instance16 is new BC54003_3.Formal_Array_Parameter
     (BC54003_4.Dollar_Support_1, BC54003_4.Array_Op_Ptr);            -- OK.

   package Instance17 is new BC54003_3.Formal_Array_Parameter
     (BC54003_4.Dollar_Support_2, BC54003_4.Array_Op_Ptr);            -- OK.

   package Instance18 is new BC54003_3.Formal_Array_Parameter
     (BC54003_4.Dollar_Support_3, BC54003_4.Array_Op_Ptr);            -- ERROR:
                    -- Parameters in designated profiles do not have same type.


end BC54003;
