
----------------------------------------------------------------- CC40001_3

generic
  type Formal_Private(<>) is private;
  TC_Check_Object : in Formal_Private;
  with function Bad_Status( O: Formal_Private ) return Boolean;
package CC40001_0.CC40001_3 is
  procedure TC_Verify_State;
end CC40001_0.CC40001_3;
