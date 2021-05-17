
generic
package B3A2017_G.C is
  procedure Dummy; -- just to make body non-optional

  type Inner_Ref is access procedure;
  Y : Inner_Ref;

end;
