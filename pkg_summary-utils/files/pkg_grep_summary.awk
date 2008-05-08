
BEGIN {
	FS     = "="
	skip   = -1 # -1 - unknown, 0 - false, 1 - true
	count  = 0
}

function update_skip (){
	skip = !(grep_summary__condition())

	if (skip == 0){
		for (i=0; i < count; ++i){
			print accu [i]
		}
	}

	delete accu
	count = 0
}

skip == 1 && NF > 0 {
	next
}

$1 == grep_summary__field {
	update_skip()
}

skip == 0 && NF > 0 {
	print $0
	next
}

skip == -1 && NF > 0 {
	accu [count++] = $0
}

NF == 0 {
	if (skip == 0){
		print ""
	}

	delete accu
	count = 0
	skip = -1
}
