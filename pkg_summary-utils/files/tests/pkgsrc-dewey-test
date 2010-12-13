#!/usr/bin/env runawk

#use "./pkgsrc-dewey.awk"
#use "alt_assert.awk"

function check (condition){
	if (!condition){
		print "dewey($1)=" __dewey2str($1)
		print "dewey($2)=" __dewey2str($2)
		abort()
	}
}

{
	check($3 == dewey_cmp($1, $2))
	if ($3 == "<"){
		check(">" == dewey_cmp($2, $1))
	}
}
