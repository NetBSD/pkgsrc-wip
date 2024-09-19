# $NetBSD: options.mk,v 1.1 2009/06/09 17:19:16 marko_schuetz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.tardy
PKG_SUPPORTED_OPTIONS=		testing
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

###
### testing support
###
.if !empty(PKG_OPTIONS:Mtesting)
DEPENDS+=	gcpio-[0-9]*:../../archivers/gcpio
.endif
