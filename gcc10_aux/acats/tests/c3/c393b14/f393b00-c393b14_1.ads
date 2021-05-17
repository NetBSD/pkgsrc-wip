 -- Alert_Foundation.Private_Child

--=======================================================================--

package F393B00.C393B14_1 is
     -- Alert_Foundation.Public_Child

  type Timing is (Before, After);
  procedure Init;
  procedure Modify;
  function Check_Before return Boolean;
  function Check_After  return Boolean;

end F393B00.C393B14_1;
