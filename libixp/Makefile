# $NetBSD: Makefile,v 1.2 2006/11/05 19:37:47 kh-p Exp $

DISTNAME=		libixp
PKGNAME=		libixp-20061105
CATEGORIES=		devel
MASTER_SITES=		http://perso.orange.fr/kh.p/pkgsrc/

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://libs.suckless.org/
COMMENT=		Standalone client/server 9P library

NO_CONFIGURE=		yes
USE_LIBTOOL=		yes

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/ixpc ${PREFIX}/bin
	 ${INSTALL_DATA} ${WRKSRC}/ixp.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/libixp.a ${PREFIX}/lib
	 ${INSTALL_DATA} ${WRKSRC}/ixpc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
