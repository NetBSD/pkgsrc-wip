# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:17 ykomatsu Exp $
#

DISTNAME=		gps-0.9.2
CATEGORIES=		security net
MASTER_SITES=		http://gps.sourceforge.net/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gps.sourceforge.net/
COMMENT=		Ghost Port Scan

USE_TOOLS+=		gmake
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
