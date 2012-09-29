# $NetBSD: Makefile,v 1.9 2012/09/29 00:33:28 asau Exp $
#

DISTNAME=		gps-0.9.2
CATEGORIES=		security net
MASTER_SITES=		http://www.mirrors.wiretapped.net/security/network-mapping/gps/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Ghost Port Scan

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

MISCDIR=		${PREFIX}/share/gps
DOCSDIR=		${PREFIX}/share/doc/gps

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MISCDIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/ChangeLog ${DESTDIR}${MISCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${DOCSDIR}

.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
