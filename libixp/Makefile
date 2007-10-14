# $NetBSD: Makefile,v 1.8 2007/10/14 12:17:41 hoka_adam Exp $

DISTNAME=		libixp-20071013
WRKSRC=			${WRKDIR}/libixp
#PKGREVISION=		0
CATEGORIES=		devel

# suckless.org doesn't offer up-to-date official snapshots at the moment
#
MASTER_SITES=		http://irkmaffia.com/~replaced/files/ \
			http://freeshells.ch/~replaced/files/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://www.suckless.org/
COMMENT=		Standalone client/server 9P library

NO_CONFIGURE=		yes
USE_LIBTOOL=		yes

pre-install:
	mv ${WRKSRC}/cmd/ixpc.O ${WRKSRC}/cmd/ixpc

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/cmd/ixpc ${PREFIX}/bin
	 ${INSTALL_DATA} ${WRKSRC}/include/ixp.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/include/ixp_fcall.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/include/ixp_local.h ${PREFIX}/include
	 ${INSTALL_DATA} ${WRKSRC}/lib/libixp.a ${PREFIX}/lib
	 ${INSTALL_DATA} ${WRKSRC}/lib/libixp_pthread.a ${PREFIX}/lib
	 ${INSTALL_DATA} ${FILESDIR}/ixpc.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
