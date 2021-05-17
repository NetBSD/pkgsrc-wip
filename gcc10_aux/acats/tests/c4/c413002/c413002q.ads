
with C413002P;
package C413002Q is
   type TQ is new C413002P.TP with record
      Value : Float := 0.0;
   end record;

   procedure Prim_Proc (X : in out TQ);
   procedure Prim_Proc (X : in out TQ; Value : Integer);
   function  Prim_Func (X : TQ) return Integer;
   function  Prim_Func (X : TQ; Value : Integer) return Integer;

   procedure Class_Wide_Proc (X : in out TQ'Class; Value : Float);
   function  Class_Wide_Func (X : TQ'Class; Value : Float) return Float;
   --  Note: Formals of these class-wide subprograms are different from the
   --        class-wide subprograms defined in the ancestor.

   function Prim_New_Func (X : TQ) return Integer;
   --  This is a new primitive operation.

   package Local is
      type TPP is new TQ with null record;
      procedure Prim_Proc (X : in out TPP);
      procedure Prim_Proc (X : in out TPP; Value : Integer);
      function  Prim_Func (X : TPP) return Integer;
      function  Prim_Func (X : TPP; Value : Integer) return Integer;
   end Local;
end C413002Q;
