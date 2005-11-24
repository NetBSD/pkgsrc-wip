# $NetBSD: options.mk,v 1.1.1.1 2005/11/24 13:42:36 udontknow Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.pam-pkcs11
PKG_SUPPORTED_OPTIONS=	pcsc-lite ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../wip/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pcsclite
PLIST_SRC+=		PLIST.pcsc-lite
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
PLIST_SRC+=		PLIST.ldap
.endif
