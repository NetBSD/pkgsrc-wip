# $Id: Makefile,v 1.4 2005/06/14 08:37:22 christian_gall Exp $
# $NetBSD: Makefile,v 1.4 2005/06/14 08:37:22 christian_gall Exp $

DISTNAME=	muttng-20050614
CATEGORIES=	mail
MASTER_SITES=	http://nion.modprobe.de/mutt-ng/snapshots/

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://mutt-ng.berlios.de/
COMMENT=	Fork of the well-known email client mutt

CONFLICTS+=		mutt-[0-9]*
CONFLICTS+=		mutt-devel-[0-9]*
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALL_UNSTRIPPED=	yes
USE_PERL5=		yes
REPLACE_PERL=		smime_keys.pl
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/muttng/ \
			--enable-pop --enable-imap --with-slang \
			--with-gss

PKG_OPTIONS_VAR=	PKG_OPTIONS.muttng
PKG_SUPPORTED_OPTIONS=	ssl gpgme sasl2 idn esmtp hcache
.include "../../mk/bsd.options.mk"

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
CONFIGURE_ARGS+=	--enable-hcache --with-bdb
.include "../../databases/db4/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

