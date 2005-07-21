# $Id: Makefile,v 1.7 2005/07/21 14:15:43 christian_gall Exp $
# $NetBSD: Makefile,v 1.7 2005/07/21 14:15:43 christian_gall Exp $

DISTNAME=	muttng-20050721
CATEGORIES=	mail
MASTER_SITES=	http://nion.modprobe.de/mutt-ng/snapshots/

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://mutt-ng.berlios.de/
COMMENT=	Fork of the well-known email client mutt

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALL_UNSTRIPPED=	yes
USE_PERL5=		yes
REPLACE_PERL+=		smime_keys.pl
REPLACE_PERL+=		contrib/update-config.pl
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/muttng/ \
			--enable-pop --enable-imap --with-slang
AUTOCONF_REQD=		2.50
USE_TOOLS+=		gmake autoconf automake


PKG_OPTIONS_VAR=	PKG_OPTIONS.muttng
PKG_SUPPORTED_OPTIONS=	ssl gpgme sasl2 idn esmtp hcache gssapi
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gss=${KRB5BASE}
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
.include "../../security/cyrus-sasl2/buildlink3.mk"
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

pre-configure:
	cd ${WRKSRC}; ./autogen.sh

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

