# $NetBSD: Makefile,v 1.1.1.1 2004/05/09 19:25:46 dillo Exp $
#

DISTNAME=		raw-0.1.0
CATEGORIES=		games
MASTER_SITES=		http://membres.lycos.fr/cyxdown/raw/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/cyxdown/raw/
COMMENT=		Engine for playing Another World

USE_BUILDLINK3=		yes
ALL_TARGET=		raw

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raw ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/raw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/raw

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
