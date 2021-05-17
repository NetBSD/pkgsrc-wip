
package B393011_Q.Child is
   type TC is new B393011_Q.T with null record;     -- OK.
   -- Op[2] (which is not abstract) inherited here.
   procedure Do_It (X : B393011_Q.T);
end B393011_Q.Child;

