
with B3A2017_G;
generic
  with package Pack is new B3A2017_G(<>);
package B3A2017_FP is
  procedure Dummy; -- just to make body non-optional

  type Gen_Ref is access procedure;
  Z : Gen_Ref;

end;

