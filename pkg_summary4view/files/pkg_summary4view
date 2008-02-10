#!/usr/bin/awk -f

# Copyright (c) 2007-2008 Aleksey Cheusov <vle@gmx.net>
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

function spaces (n){
	while (n-- > 0){
		printf " "
	}
}

BEGIN {
	special ["DESCRIPTION"] = 0
	special ["PLIST"]       = 0
	special ["PROVIDES"]    = 0
	special ["REQUIRES"]    = 0

	offset = 16
}

NF == 0 {
	print
	last_field = ""
	next
}

/^PKGNAME=/ {
	print "-----------------------------------------------------------"
}

{
	#
	field = $0
	sub(/=.*$/, "", field)

	#
	sub(/^[^=]*=/, "")

	#
	if (field == "DEPENDS" || field == "BUILD_DEPENDS"){
		printf "%s:", field
		if ($0 !~ /^( |\t)*$/)
			spaces(offset - length(field) - 1)

		print $1

		for (i=2; i <= NF; ++i){
			spaces(offset)
			print $i
		}

		next
	}else if (field in special) {
		if (field != prev_field) {
			print field ":"
		}

		printf "    "
	}else{
		printf "%s:", field
		if ($0 !~ /^( |\t)*$/)
			spaces(offset - length(field) - 1)
	}

	#
	prev_field = field
}

{
	print $0
}
