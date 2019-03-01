# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gitea
PKG_SUPPORTED_OPTIONS=	sqlite
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
GO_TAGS+=	sqlite
.endif
