# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gambas3-ide
PKG_SUPPORTED_OPTIONS=	bzip2 gzip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgzip)
DEPENDS+=	gzip-1.*:../../archivers/gzip
.endif
