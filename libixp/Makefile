# $NetBSD: Makefile,v 1.6 2007/03/17 22:27:19 cosmedbr Exp $

DISTNAME=		libixp-0.2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://libs.suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://libs.suckless.org/
COMMENT=		Standalone client/server 9P library

NO_CONFIGURE=		yes
USE_LIBTOOL=		yes

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/ixpc ${PREFIX}/bin
	 ${INSTALL_DATA} ${WRKSRC}/ixp.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/libixp.a ${PREFIX}/lib
	 ${INSTALL_DATA} ${FILESDIR}/ixpc.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
