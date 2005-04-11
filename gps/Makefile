# $NetBSD: Makefile,v 1.3 2005/04/11 21:12:34 tvierling Exp $
#

DISTNAME=		gps-0.9.2
CATEGORIES=		security net
MASTER_SITES=		http://gps.sourceforge.net/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gps.sourceforge.net/
COMMENT=		Ghost Port Scan

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

MISCDIR=		${PREFIX}/share/gps
DOCSDIR=		${PREFIX}/share/doc/gps

post-install:
	${INSTALL_DATA_DIR} ${MISCDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/ChangeLog ${MISCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
