# $NetBSD: options.mk,v 1.2 2006/04/13 21:33:47 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.muttng
PKG_SUPPORTED_OPTIONS=	ssl gpgme sasl2 idn esmtp hcache gssapi debug curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurses)
CONFIGURE_ARGS+=--with-curses
.include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=--with-slang
.include "../../devel/libslang/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gss=${KRB5BASE:Q}
.include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gss
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !empty(PKG_OPTIONS:Mgpgme)
CONFIGURE_ARGS+=	--enable-gpgme
.include "../../security/gpgme/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msasl2)
CONFIGURE_ARGS+=	--with-sasl2
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Midn)
CONFIGURE_ARGS+=	--with-idn
.include "../../devel/libidn/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mesmtp)
CONFIGURE_ARGS+=	--with-libesmtp
.include "../../mail/libesmtp/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mhcache)
CONFIGURE_ARGS+=	--enable-hcache --with-bdb --without-qdbm --without-gdbm
.include "../../databases/db4/buildlink3.mk"
.endif
