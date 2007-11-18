# $NetBSD: Makefile,v 1.9 2007/11/18 01:15:47 zul_ Exp $

DISTNAME=		libixp-0.4
CATEGORIES=		devel

MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://www.suckless.org/
COMMENT=		Standalone client/server 9P library

NO_CONFIGURE=		yes

pre-install:
	mv ${WRKSRC}/cmd/ixpc.O ${WRKSRC}/cmd/ixpc

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/cmd/ixpc ${PREFIX}/bin
	 ${INSTALL_DATA} ${WRKSRC}/include/ixp.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/include/ixp_fcall.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/include/ixp_local.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/lib/libixp.a ${PREFIX}/lib
	 ${INSTALL_DATA} ${WRKSRC}/lib/libixp_pthread.a ${PREFIX}/lib
	 ${INSTALL_DATA} ${WRKSRC}/man/ixpc.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
