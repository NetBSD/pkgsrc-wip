# $NetBSD: options.mk,v 1.1.1.1 2009/08/26 20:36:01 udontknow Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.389-ds-base
PKG_SUPPORTED_OPTIONS=	kerberos

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
PKG_FAIL_REASON+= "Heimdal Kerberos support pending on upstream project. https://bugzilla.redhat.com/show_bug.cgi?id=519464"
.  include "../../security/heimdal/buildlink3.mk"
CPPFLAGS+=              -I${BUILDLINK_DIR}/include/krb5
CFLAGS+=                -I${BUILDLINK_DIR}/include/krb5
.else
CONFIGURE_ARGS+=       --without-kerberos
.endif
