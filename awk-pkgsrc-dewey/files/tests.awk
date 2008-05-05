#!/usr/bin/env runawk

#use "./pkgsrc-dewey.awk"
#use "alt_assert.awk"

{
	assert($3 == dewey_cmp($1, $2))
	if ($3 == "<"){
		assert(">" == dewey_cmp($2, $1))
	}
}
