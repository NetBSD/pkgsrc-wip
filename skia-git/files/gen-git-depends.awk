#! /usr/bin/env awk -f
function header() {
	printf("# $NetBSD$\n");
	printf("#\n");
	printf("# Generated automatically; run make git-depends.mk to regenerate this file.\n");
	printf("#\n");
}
function indent(str, col) {
	need = int((col - length(str) + 7) / 8)
	for (; need > 0; need--)
		str = str "\t"
	return str
}
BEGIN {
	split(ENVIRON["REQUIRED_REPOS"], tmp, " +");
	for (x in tmp) {
		required_repos[tmp[x]] = 1;
	}
	header();
}
/^deps = / { deps = 1; }
/^  .bin./ { deps = 0; }
/^  "/ {
	if (deps) {
		dir = $0;
		gsub("^  \"", "", dir);
		gsub("\".*$", "", dir);
		basename = dir;
		gsub("^.*/", "", basename);
		if (!required_repos[basename])
			next;
		full_url = $0;
		gsub("^.*: \"", "", full_url);
		gsub("\".*$", "", full_url);
		url = full_url
		gsub("@.*$", "", url)
		rev = full_url
		gsub("^.*@", "", rev)
		printf("\n");
		printf("%s%s\n", indent("GIT_REPOSITORIES+=", 24), basename);
		printf("%s\n", indent("GIT_REPO." basename "+=", 24) url);
		printf("%s%s\n", indent("GIT_BRANCH." basename "=", 24), "main");
		printf("%s%s\n", indent("GIT_REVISION." basename "=", 24), rev);
		printf("%sskia/%s\n", indent("GIT_EXTRACTDIR." basename "=", 24), dir);
	}
}
