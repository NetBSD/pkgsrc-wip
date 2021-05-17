
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C760011_0 is

  procedure Initialize( It: in out Controlled_Type ) is
  begin
    It.TC_Component := (others => It.Tag);
    if It.Tag in Tracking_Array'Range then 
      Initialized(It.Tag) := True;
    end if;
    if Under_Debug then
      Report.Comment("Initializing Tag: " & It.Tag );
    end if;
  end Initialize;
  
  procedure Finalize( It: in out Controlled_Type ) is
  begin
    if Under_Debug then
      Report.Comment("Finalizing for Tag: " & It.Tag );
    end if;
    if It.Tag in Finalized'Range then 
      Finalized(It.Tag) := True;
    end if;
  end Finalize;

  function Create(With_Tag: Character) return Controlled_Type is
  begin
    return Controlled_Type'(Ada.Finalization.Controlled
                            with Tag          => With_Tag,
                                 TC_Component => "*CON" );
  end Create;

  procedure Initialize( It: in out Non_Controlled ) is
  begin
    Report.Failed("Called Initialize for Non_Controlled");
  end Initialize;
  
  procedure Finalize( It: in out Non_Controlled ) is
  begin
    Report.Failed("Called Finalize for Non_Controlled");
  end Finalize;

  function Create(With_Tag: Character) return Non_Controlled is
  begin
    return Non_Controlled'(Tag => With_Tag, Controlled_Component => (
                                  Ada.Finalization.Controlled
                                    with Tag          => With_Tag,
                                         TC_Component => "#NON" ) );
  end Create;

end C760011_0;
