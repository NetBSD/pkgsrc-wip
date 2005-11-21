# $NetBSD: options.mk,v 1.1.1.1 2005/11/21 20:50:32 bartoszkuzma Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsyslog
PKG_SUPPORTED_OPTIONS=	largefile mysql
PKG_SUGGESTED_OPTIONS=	largefile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlargefile)
CFLAGS+=			-DWITH_LARGEFILE
FEATURE_LARGEFILE=		# empty
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CFLAGS+=			-DWITH_DB
LDFLAGS+=			-lmysqlclient -L/usr/pkg/lib/mysql
FEATURE_DB=			# empty
.include "../../mk/mysql.buildlink3.mk"
.endif
