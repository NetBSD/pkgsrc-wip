# $NetBSD: $

VIM_VERSION=		8.3
VIM_PATCHLEVEL=		0
VIM_SUBDIR=		vim83

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
