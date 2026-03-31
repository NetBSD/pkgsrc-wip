# $NetBSD: $

VIM_VERSION=		8.2
# XXX This version of vim-classic is Drew Devault's fork.  He's about to cut an
# 8.3.0 release in April.  When that happens, I'll update the packaging again,
# as the code changes I saw today (30mar2026) look like they solve most of this
# and will simplify the distfile situation.
VIM_PATCHLEVEL=		5172
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
