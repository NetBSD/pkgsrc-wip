# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnfs
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

###
### KRB5 support
###
.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-libkrb5
KRB5_ACCEPTED=		mit-krb5
.  include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libkrb5
.endif
