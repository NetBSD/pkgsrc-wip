# $NetBSD: $

VIM_VERSION=		8.2
# XXX This version of vim-classic is Drew Devault's fork.  I need to email him about
# how patchlevel versions are going to be handled going forward.  Leaving as-is for now.
VIM_PATCHLEVEL=		5172
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
