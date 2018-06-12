# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gitea
PKG_SUPPORTED_OPTIONS=	sqlite pam
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
GO_TAGS+=	sqlite
.endif

.if !empty(PKG_OPTIONS:Mpam)
GO_TAGS+=	pam
.endif
