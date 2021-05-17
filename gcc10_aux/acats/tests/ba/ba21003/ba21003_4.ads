

     --===================================================================--


package BA21003_4 is -- Declare-pure unit.

   pragma Pure (BA21003_4);


   type T2 is abstract tagged record
      C: Integer;
   end record;

   procedure Init (P: in out T2);
   procedure Op1  (P: in out T2) is abstract;

end BA21003_4;
