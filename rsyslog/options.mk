# $NetBSD: options.mk,v 1.3 2008/08/10 21:08:29 mstapelberg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rsyslog
PKG_SUPPORTED_OPTIONS=	largefile mysql gnutls
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

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gnutls
.endif
