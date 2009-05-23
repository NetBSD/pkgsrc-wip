# $NetBSD: options.mk,v 1.2 2009/05/23 19:08:29 imilh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pkgin
PKG_SUPPORTED_OPTIONS=	gzip-summary
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# by default, pkg_summary extention is set to bz2
.if !empty(PKG_OPTIONS:Mgzip-summary)
CPPFLAGS+=	-DSUMEXT=\"gz\"
.endif
