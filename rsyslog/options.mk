# $NetBSD: options.mk,v 1.2 2006/08/01 09:42:40 bartoszkuzma Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsyslog
PKG_SUPPORTED_OPTIONS=	largefile mysql
PKG_SUGGESTED_OPTIONS=	largefile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlargefile)
CFLAGS+=			-DWITH_LARGEFILE
FEATURE_LARGEFILE=		# empty
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CFLAGS+=			-DWITH_DB
LDFLAGS+=			-lmysqlclient
FEATURE_DB=			# empty
.endif
