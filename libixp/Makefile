# $NetBSD: Makefile,v 1.5 2007/02/03 21:53:05 neimal Exp $

DISTNAME=		libixp-0.2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://libs.suckless.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
