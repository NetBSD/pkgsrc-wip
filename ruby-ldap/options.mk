# $NetBSD: options.mk,v 1.1 2006/08/16 04:43:06 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby-ldap
PKG_OPTIONS_REQUIRED_GROUPS=	ldapsdk
PKG_OPTIONS_GROUP.ldapsdk=	openldap mozilla
PKG_SUGGESTED_OPTIONS=	openldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openldap2
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
.elif !empty(PKG_OPTIONS:Mmozilla)
.include "../../devel/ldapsdk/buildlink3.mk"
CONFIGURE_ARGS+=	--with-netscape
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.ldapsdk}
CONFIGURE_ARGS+=	--with-liblber=lber
.endif
