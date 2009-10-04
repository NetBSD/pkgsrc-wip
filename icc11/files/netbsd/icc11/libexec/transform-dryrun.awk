BEGIN {
	argindent="    "
}

function transform_dryrun(arg) {
	sub(/^ *-D_*linux_* /, argindent "-D__NetBSD__", arg)
	sub(/^ *-D_*gnu_linux_* /, argindent "-D__NetBSD__ ", arg)

	# Regexps not tagged by ^ transform an argument of -mIPOPT_cmdline_link.
	sub(/^ *-ldl */, argindent "-licc11bsd ", arg)
	gsub(/"-ldl"/, "\"-licc11bsd\"", arg)
	sub(/^ *\/usr\/lib\/crt1.o */, argindent "/usr/lib/crt0.o ", arg)
	gsub(/"\/usr\/lib\/crt1.o"/, "\"/usr/lib/crt0.o\"", arg)
	sub(/^ *\/lib\/ld-linux.so.2 */, argindent "/usr/libexec/ld.elf_so ", arg)
	gsub(/"\/lib\/ld-linux.so.2"/, "\"/usr/libexec/ld.elf_so\"", arg)

	# Workaround for 562098 "-dryrun doesn't properly quote escaped quotes"
	# https://premier.intel.com/premier/IssueDetail.aspx?IssueID=562098
	gsub(/"/, "\\\"", arg)
	if(arg ~ /^ *\\"/) {
		sub(/^ *\\"/, argindent "\"", arg)
		sub(/\\" *$/, "\" ", arg)
		sub(/\\" *\\$/, "\" \\", arg)
	}

	return arg
}
