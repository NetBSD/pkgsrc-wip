
----------------------------------------------------------------- C393010_1

with Report;
with TCTouch;
with C393010_0;
with C393010_1;
with C393010_2; -- Charter Tours

procedure C393010 is

  type Agents_Handle is access all C393010_0.Ticket'Class;

  type Itinerary;

  type Next_Leg is access Itinerary;

  type Itinerary is record
    Leg  : Agents_Handle;
    Next : Next_Leg;
  end record;

  function Travel_Agent_1 return Next_Leg is
  begin
    -- ORL -> JFK -> LAX -> SAN -> DFW -> ORL
    return new Itinerary'(
       -- ORL -> JFK 01   12  2A First, Lobster
       new C393010_1.Passenger_Ticket'(
         C393010_1.Issue(C393010_1.First, 12, " 2A", C393010_1.Lobster )),
         new Itinerary'(
       -- JFK -> LAX 02   18  2B First, Steak
       new C393010_1.Passenger_Ticket'(
         C393010_1.Issue(C393010_1.First, 18, " 2B", C393010_1.Steak )),
         new Itinerary'(
       -- LAX -> SAN 03 5225 34H Coach
       new C393010_1.Passenger_Ticket'(
         C393010_1.Issue(C393010_1.Coach, 5225, "34H")),
         new Itinerary'(
       -- SAN -> DFW 04   25 13A Business, Fowl
       new C393010_1.Passenger_Ticket'(
         C393010_1.Issue(C393010_1.Business, 25, "13A")),
         new Itinerary'(
       -- DFW -> ORL 05   15  1D First, Lobster
       new C393010_1.Passenger_Ticket'(
         C393010_1.Issue(C393010_1.First, 15, " 1D", C393010_1.Lobster )),
         null          )))));
  end Travel_Agent_1;

  function Travel_Agent_2 return Next_Leg is
  begin
    -- LAX -> NRT -> SYD -> LAX
    return new Itinerary'(
       new C393010_2.Charter'( C393010_2.Issue ),
         new Itinerary'(
       new C393010_2.Charter'( C393010_2.Issue ),
         new Itinerary'(
       new C393010_2.Charter'( C393010_2.Issue ),
         new Itinerary'(
       new C393010_2.Charter'( C393010_2.Issue ),
         null ))));
  end Travel_Agent_2;

  procedure Traveler( Pax_Tix : in Next_Leg ) is
    Fly_Me : Next_Leg := Pax_Tix;
  begin
    -- a particularly consumptive process...
    while Fly_Me /= null loop
      C393010_0.Print( Fly_Me.Leg.all );  -- herein lies the test.
      Fly_Me := Fly_Me.Next;
    end loop;
  end Traveler;

begin

  Report.Test ("C393010", "Check that an extended type can be derived from "
                        & "an abstract type and that a call on an abstract "
                        & "operation is a dispatching operation.  Check "
                        & "that such a call can dispatch to an overriding "
                        & "operation declared in the private part of a "
                        & "package" );

  Traveler( Travel_Agent_1 );
  TCTouch.Validate("LPFLPFLPCLPBLPF","First Trip");

  Traveler( Travel_Agent_2 );
  TCTouch.Validate("XPCXPCXPCXPC","Second Trip");

  Report.Result;

end C393010;
