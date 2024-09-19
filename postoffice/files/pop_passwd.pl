#!/usr/pkg/bin/perl
# pop_passwd username password >> password file

 $name = $ARGV[0];

 @salt_chars         = ('a'..'z','A'..'Z','0'..'9');
 $salt               = $salt_chars[rand(62)] . $salt_chars[rand(62)];

 $passwd = crypt ($ARGV[1], $salt);

 print "$name:$passwd\n";
