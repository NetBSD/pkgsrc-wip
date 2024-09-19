# $NetBSD: options.mk,v 1.3 2006/09/07 12:03:21 hfath Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sxemacs
PKG_SUPPORTED_OPTIONS=	ldap xface canna pgsql ffi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mxface)
CONFIGURE_ARGS+=	--with-xface
.  include "../../mail/faces/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xface
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna
PLIST_SUBST+=	FOR_MULE=''
.else
CONFIGURE_ARGS+=	--without-canna
PLIST_SUBST+=	FOR_MULE='@comment '
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

.if !empty(PKG_OPTIONS:Mffi)
CONFIGURE_ARGS+=	--with-ffi
# XXX What external dependencies does FFI have?
.else
CONFIGURE_ARGS+=	--without-ffi
.endif

CONFIGURE_ARGS+=	--with-sound=noarts
