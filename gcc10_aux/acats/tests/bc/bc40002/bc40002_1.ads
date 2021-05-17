

     --==================================================================--


with BC40002_0;
use  BC40002_0;
package BC40002_1 is

   generic
      FObj: in T;
   package In_T is end;

   generic
      FObj: T'Class;
   package In_TClass is end;

   generic
      FObj: in out T;
   package InOut_T is end;

   generic
      FObj: in out T'Class;
   package InOut_TClass is end;

end BC40002_1;
