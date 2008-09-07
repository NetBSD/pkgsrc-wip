
BEGIN {
	FS                 = "="
	grep_summary__skip = -1 # -1 - unknown, 0 - false, 1 - true
	count              = 0
}

function update_skip (){
	grep_summary__skip = grep_summary__condition()
	if (grep_summary__skip == 0 || grep_summary__skip == 1){
		grep_summary__skip = !grep_summary__skip
	}

	if (grep_summary__skip == 0){
		for (i=0; i < count; ++i){
			print accu [i]
		}

		delete accu
		count = 0
	}
}

grep_summary__skip == 1 && NF > 0 {
	next
}

{
	fname = $1
	fvalue = $0
	sub(/^[^=]*=/, "", fvalue)
}

($1 == grep_summary__field) || ("" == grep_summary__field) {
	if (grep_summary__skip == -1){
		update_skip()
	}
}

grep_summary__skip == 0 && NF > 0 {
	print $0
	next
}

{
	grep_summary__fields [$1] = fvalue
}

grep_summary__skip == -1 && NF > 0 {
	accu [count++] = $0
}

NF == 0 {
	if (grep_summary__skip == 0){
		print ""
	}

	delete accu
	delete grep_summary__fields
	count = 0
	grep_summary__skip = -1
}
