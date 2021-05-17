
with C3A0013_4;
with Report;
procedure C3A0013 is
begin

  Report.Test ("C3A0013", "Check general access types.  Check aliased "
                        & "nature of formal tagged type parameters.  "
                        & "Check aliased nature of the current "
                        & "instance of a limited type.  Check the "
                        & "constraining of actual subtypes for "
                        & "discriminated objects" );

  C3A0013_4.Perform_Tests;

  Report.Result;
end C3A0013;
