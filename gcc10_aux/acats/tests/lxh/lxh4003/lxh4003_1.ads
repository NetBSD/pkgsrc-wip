
----------------------------------------------------------------- LXH4003_1

with LXH4003_0;
package LXH4003_1 is

  type Objects is tagged record
    Name : String(1..20);
    Location : Natural;
  end record;

  type Pointers is access Objects;

end LXH4003_1;
