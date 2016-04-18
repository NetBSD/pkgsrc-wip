# $NetBSD: options.mk $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nss-pam-ldapd
PKG_SUPPORTED_OPTIONS=	kerberos sasl
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-kerberos
.endif

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif
