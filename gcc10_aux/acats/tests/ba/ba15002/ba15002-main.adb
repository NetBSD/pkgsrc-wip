
----------------

with BA15002.OK_Inline;
with BA15002.Procedure_Inline;
with BA15002.Bad_Inline; -- OPTIONAL ERROR:

with BA15002.OK_Elaborate_Body;
with BA15002.OK_Bare_Elaborate_Body;
with BA15002.Bad_Elaborate_Body; -- OPTIONAL ERROR:
with BA15002.Bad_Bare_Elaborate_Body; -- OPTIONAL ERROR:
with BA15002.Private_Elaborate_Body; -- OPTIONAL ERROR:
with BA15002.Private_Generic_Elaborate_Body; -- OPTIONAL ERROR:
with BA15002.Very_Bad_Elaborate_Body; -- OPTIONAL ERROR:
with BA15002.Also_Bad_Elaborate_Body; -- OPTIONAL ERROR:

with BA15002.OK_Preelaborate;
with BA15002.OK_Bare_Preelaborate;
with BA15002.Bad_Preelaborate; -- OPTIONAL ERROR:
with BA15002.Bad_Bare_Preelaborate; -- OPTIONAL ERROR:
with BA15002.Private_Preelaborate; -- OPTIONAL ERROR:
with BA15002.Private_Generic_Preelaborate; -- OPTIONAL ERROR:
with BA15002.Very_Bad_Preelaborate; -- OPTIONAL ERROR:
with BA15002.Also_Bad_Preelaborate; -- OPTIONAL ERROR:
with BA15002.Generic_Preelaborate; -- OPTIONAL ERROR:
with BA15002.Generic_Preelaborate_2; -- OPTIONAL ERROR:

with BA15002.OK_Pure;
with BA15002.OK_Bare_Pure;
with BA15002.Bad_Pure; -- OPTIONAL ERROR:
with BA15002.Bad_Bare_Pure; -- OPTIONAL ERROR:
with BA15002.Private_Pure; -- OPTIONAL ERROR:
with BA15002.Private_Generic_Pure; -- OPTIONAL ERROR:
with BA15002.Very_Bad_Pure; -- OPTIONAL ERROR:
with BA15002.Also_Bad_Pure; -- OPTIONAL ERROR:
with BA15002.Generic_Pure; -- OPTIONAL ERROR:
with BA15002.Generic_Pure_2; -- OPTIONAL ERROR:

with BA15002.Body_Pragmas;

procedure BA15002.Main is
begin
    null;
end BA15002.Main;

