# $NetBSD: Makefile,v 1.1.1.1 2004/04/16 10:26:30 tripledes Exp $
#

DISTNAME=		gps-0.9.2
CATEGORIES=		security net
MASTER_SITES=		http://gps.sourceforge.net/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gps.sourceforge.net/
COMMENT=		Ghost Port Scan

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

MISCDIR=		${PREFIX}/share/gps
DOCSDIR=		${PREFIX}/share/doc/gps

post-install:
	${INSTALL_DATA_DIR} ${MISCDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/COPYING ${WRKSRC}/ChangeLog ${MISCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}

.include "../../devel/libnet/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
