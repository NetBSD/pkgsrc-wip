# $NetBSD: Makefile,v 1.3 2008/11/15 21:50:41 gschwarz Exp $

DISTNAME=			iodine-0.4.2
CATEGORIES=			net
MASTER_SITES=			http://code.kryo.se/iodine/

MAINTAINER=			mj@mjturner.net
HOMEPAGE=			http://code.kryo.se/iodine/
COMMENT=			Tool to tunnel IPv4 over DNS

PKG_DESTDIR_SUPPORT=		user-destdir

WRKSRC=				${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=			src
INSTALLATION_DIRS=		share/${PKGBASE} ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodine ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodined ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/iodine.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
