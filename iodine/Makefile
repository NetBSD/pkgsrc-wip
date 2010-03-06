# $NetBSD: Makefile,v 1.5 2010/03/06 20:06:28 gschwarz Exp $

PKGNAME=			iodine-0.6.0
DISTNAME=			iodine-0.6.0-rc1
CATEGORIES=			net
MASTER_SITES=			http://code.kryo.se/iodine/

MAINTAINER=			mj@mjturner.net
HOMEPAGE=			http://code.kryo.se/iodine/
COMMENT=			Tool to tunnel IPv4 over DNS

PKG_DESTDIR_SUPPORT=		user-destdir

INSTALLATION_DIRS=		bin sbin share/${PKGBASE} ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodine ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iodined ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/iodine.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
