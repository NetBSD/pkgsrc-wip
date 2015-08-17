# $NetBSD: Makefile,v 1.1 2015/08/17 21:22:15 yhardy Exp $
#

DISTNAME=	nuvie-0.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nuvie/Nuvie/0.3/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nuvie.sourceforge.net/
COMMENT=	Game engine for Ultima 6
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	share/examples/nuvie

post-install:
	${INSTALL_DATA} ${WRKSRC}/nuvie.cfg.sample ${DESTDIR}${PREFIX}/share/examples/nuvie/nuvie.cfg
	cd ${WRKSRC}/data && ${TOOLS_PATH.find} . | while read name; do \
		if [ -d "$$name" ]; then \
			${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/nuvie/$$name"; \
		else \
			${INSTALL_DATA} "$$name" "${DESTDIR}${PREFIX}/share/nuvie/$$name"; \
		fi; \
	done

.include "../../devel/SDL/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
