 
----------------------------------------------------------------------
 
package F393A00_1 is
   type Object is abstract tagged private;
   procedure Initialize( An_Object: in out Object );
   function  Initialized( An_Object: Object'Class ) return Boolean;
   procedure Swap( A,B: in out Object ) is abstract;
   function  Create return Object is abstract;
private
   type Object is abstract tagged record
     Initialized : Boolean := False;
   end record;
end F393A00_1;
