# ARGUMENTS: aslocation
# NOTE: stdout and stderr will be swapped by a caller

BEGIN {
	cmdno=0
	rmcmd="rm -f"
}

# Workaround for 562102 "-dryrun doesn't list object files among ld arguments"
# https://premier.intel.com/premier/IssueDetail.aspx?IssueID=562102
# Get ld arguments from -mIPOPT_cmdline_link mcpcom option:
/^ *"-mIPOPT_cmdline_link="/ {
	ldargs = transform_dryrun($0)
	sub(/^ *"-mIPOPT_cmdline_link=/, "", ldargs)
	sub(/" *\\$/, "", ldargs)
	gsub(/\\"/, "\"", ldargs) # unquote
}

# Workaround for 562959 "-dryrun doesn't show the "as" command"
# https://premier.intel.com/premier/IssueDetail.aspx?IssueID=562959
/^ *-mGLOB_as_output_backup_file_name=/ {
	asfile=$0
	sub(/^ *-mGLOB_as_output_backup_file_name=/, "", asfile)
	sub(/ *\\?$/, "", asfile)
}

/^ *-mIPOPT_obj_output_file_name=/ {
	objfile=$0
	sub(/^ *-mIPOPT_obj_output_file_name=/, "", objfile)
	sub(/ *\\?$/, "", objfile)
}

# First line of a command
/^[^ ]/ {
	cmdno++
	if(ldargs!="" && $0 ~ /(^|\/)ld *\\?$/) {
		cmd[cmdno++] = gensub(/ *\\?$/, " ", 1) ldargs
	} else if($0 ~ /^icp?c:/) {
		cmd[cmdno++] = "cat <<! 2>&1\n" $0 "\n!\n"
	} else if($0 ~ /^rm /) {
		native = gensub(/^rm */, "", 1)
		emul = " @OPSYS_EMULDIR@" native
		args = emul " " native
		rmcmd = rmcmd " " args
		fixemulcmd = fixemulcmd " && if test -f " emul "; then mv " args "; fi"
	} else {
		cmd[cmdno] = gensub(/ *\\$/, "", 1)
	}
}

# Other lines of a command
/^ / && cmd[cmdno]!="" {
	arg = transform_dryrun($0)
	sub(/^ */, " ", arg)
	sub(/\\$/, "", arg)
	sub(/ *$/, " ", arg)
	cmd[cmdno] = cmd[cmdno] arg
}

# Last line of mcpcom command with -mGLOB_as_output_backup_file_name
# and -mIPOPT_obj_output_file_name options
/[^\\]$/ && asfile!="" && objfile!="" {
	ascmd[cmdno] = "if test -s " asfile "; then " aslocation "/as " asfile " -o " objfile "; fi"
	objfile=asfile=""
}

END {
	print "trap \"" rmcmd "\" EXIT INT" > "/dev/stderr"
	for(i=1; i<=cmdno; i++) {
		print cmd[i] " " fixemulcmd > "/dev/stderr"
		if(ascmd[i]!="")
			print ascmd[i] > "/dev/stderr"
	}
}
