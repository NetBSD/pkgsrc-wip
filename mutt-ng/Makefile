# $Id: Makefile,v 1.19 2012/10/08 14:00:39 asau Exp $
# $NetBSD: Makefile,v 1.19 2012/10/08 14:00:39 asau Exp $

DISTNAME=	muttng-20061125
CATEGORIES=	mail
MASTER_SITES=	http://nion.modprobe.de/mutt-ng/snapshots/

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://mutt-ng.berlios.de/
COMMENT=	Fork of the well-known email client mutt

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALL_UNSTRIPPED=	yes
REPLACE_PERL+=		smime_keys.pl
REPLACE_PERL+=		contrib/update-config.pl
CONFIGURE_ARGS+=	--with-docdir=${PREFIX:Q}/share/doc/muttng/ \
			--enable-pop --enable-imap
AUTOCONF_REQD+=		2.50
USE_TOOLS+=		gmake autoconf automake perl

.include "options.mk"

pre-configure:
	cd ${WRKSRC}; ./autogen.sh

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
