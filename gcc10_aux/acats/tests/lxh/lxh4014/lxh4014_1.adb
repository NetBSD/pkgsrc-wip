
package body LXH4014_1 is

  function Dispatch( O: Class ) return Natural is
  begin
    return 0;
  end Dispatch;

  function Dispatch( R: Root ) return Natural is
  begin
    return R.Stuff'Length;
  end Dispatch;

  function Choose( T: Class'Class ) return Natural is-- OPTIONAL ERROR: {20;18}
              -- Violation: pragma Restrictions (No_Dispatch) in force.
  begin
    return Dispatch(T);
  end Choose;

end LXH4014_1;
