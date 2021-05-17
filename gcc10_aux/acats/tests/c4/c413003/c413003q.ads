
with C413003P;
package C413003Q is
   type TQ is new C413003P.TP with record
      Value : Float := 0.0;
   end record;

   procedure Prim_Proc (X : access TQ);
   procedure Prim_Proc (X : access TQ; Value : Integer);
   function  Prim_Func (X : access constant TQ) return Integer;
   function  Prim_Func (X : access constant TQ; Value : Integer) return Integer;

   procedure Class_Wide_Proc (X : access TQ'Class; Value : Float);
   function  Class_Wide_Func (X : access constant TQ'Class; Value : Float) return Float;
   --  Note: Formals of these class-wide subprograms are different from the
   --        class-wide subprograms defined in the ancestor.

   function Prim_New_Func (X : access constant TQ) return Integer;
   --  This is a new primitive operation.

   package Local is
      type TPP is new TQ with null record;
      procedure Prim_Proc (X : access TPP);
      procedure Prim_Proc (X : access TPP; Value : Integer);
      function  Prim_Func (X : access constant TPP) return Integer;
      function  Prim_Func (X : access constant TPP; Value : Integer) return Integer;
   end Local;
end C413003Q;
