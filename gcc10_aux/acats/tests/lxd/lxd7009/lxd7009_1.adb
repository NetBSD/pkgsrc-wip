

with Report;
package body  LXD7009_1 is

  task Too_Many_Entries is
    entry One_Is_Too_Many;               -- OPTIONAL ERROR: {1:3}
                 -- maximum number of task entries exceeded
  end Too_Many_Entries;

  protected Has_Entries is
    entry Too_Much;                      -- OPTIONAL ERROR: {1:3}
            -- maximum number of protected entries exceeded
  end Has_Entries;

  Global_Var : Integer := 0;
  procedure Do_Something_Important is
  begin
    Global_Var := 1;
  end Do_Something_Important;


  protected body Has_Entries is
    entry Too_Much when True is
    begin
       Do_Something_Important;
    end Too_Much;
  end Has_Entries;

  task body Too_Many_Entries is
  begin
    select
      accept One_Is_Too_Many do             -- OPTIONAL ERROR: {1:5}
                 -- max number of select alternatives exceeded
        Do_Something_Important;
      end One_Is_Too_Many;
    or
      terminate;
    end select;
  end Too_Many_Entries;

  procedure Violations_Abound is
  begin
    Too_Many_Entries.One_Is_Too_Many;
    Has_Entries.Too_Much;
    Report.Failed ("pragma restrictions violations not detected");
  end Violations_Abound;

end LXD7009_1;
