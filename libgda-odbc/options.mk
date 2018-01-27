# $NetBSD: options.mk,v 1.1.1.1 2012/01/16 14:13:41 noud4 Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.libgda-odbc
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		iodbc unixodbc
PKG_SUGGESTED_OPTIONS=		unixodbc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miodbc)
.include "../../databases/iodbc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.include "../../databases/unixodbc/buildlink3.mk"
.endif
