# $NetBSD: options.mk,v 1.3 2009/05/29 13:31:38 imilh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pkgin
PKG_SUPPORTED_OPTIONS=	gzip-summary

.include "../../mk/bsd.options.mk"

# by default, pkg_summary extention is set to bz2
.if !empty(PKG_OPTIONS:Mgzip-summary)
CPPFLAGS+=	-DSUMEXT=\"gz\"
.endif
