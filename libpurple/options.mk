# $NetBSD: options.mk,v 1.1.1.1 2007/06/17 21:45:46 kheinz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pidgin
PKG_SUPPORTED_OPTIONS+=		gnutls silc perl tcl debug
PKG_SUGGESTED_OPTIONS+=		gnutls silc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--disable-nss
CONFIGURE_ARGS+= --with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+= --with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib

.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnutls
CONFIGURE_ARGS+= --with-nspr-includes=${BUILDLINK_PREFIX.nspr}/include/nspr
CONFIGURE_ARGS+= --with-nspr-libs=${BUILDLINK_PREFIX.nspr}/lib/nspr
CONFIGURE_ARGS+= --with-nss-includes=${BUILDLINK_PREFIX.nss}/include/nss/nss
CONFIGURE_ARGS+= --with-nss-libs=${BUILDLINK_PREFIX.nss}/lib/nss

.  include "../../devel/nss/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msilc)
PLIST_SUBST+=		SILC=
CONFIGURE_ARGS+= --with-silc-includes=${BUILDLINK_PREFIX.silc-toolkit}/include/silc
CONFIGURE_ARGS+= --with-silc-libs=${BUILDLINK_PREFIX.silc-toolkit}/lib/silc
. include "../../devel/silc-toolkit/buildlink3.mk"
.else
PLIST_SUBST+=		SILC="@comment "
CONFIGURE_ARGS+=	--disable-silc
.endif

.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl:run
.  include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(PKG_OPTIONS:Mtcl)
CONFIGURE_ARGS+=	--with-tclconfig=${BUILDLINK_PREFIX.tcl}/lib
.  include "../../lang/tcl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+= --enable-debug
.else
CONFIGURE_ARGS+= --disable-debug
.endif
