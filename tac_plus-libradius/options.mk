# $NetBSD: options.mk,v 1.2 2006/12/05 20:43:15 gschwarz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tac_plus-libradius
PKG_SUPPORTED_OPTIONS=	pam ldap mysql db maxsess
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.include "../../mk/pam.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql-prefix=${BUILDLINK_PREFIX.mysql}
.endif

.if !empty(PKG_OPTIONS:Mdb)
CONFIGURE_ARGS+=	--with-db
.include "../../mk/bdb.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmaxsess)
CONFIGURE_ARGS+=	--with-maxsess
.endif
