
with Report;
package body C761001_1 is

  task body Library_Task is
  begin
    if Report.Ident_Int( 1 ) /= 1 then
      Report.Failed( "Baseline failure in Library_Task");
    end if;
  end Library_Task;

end C761001_1;
