# $NetBSD: Makefile,v 1.2 2006/10/20 05:15:08 kcf Exp $
#

.include "Makefile.common"

DISTNAME=		xspsrc_${XSPDISTID}_tar
PKGNAME=		xspd-${XSPDVERSION}
MASTER_SITES=		http://home.arcor.de/joachimschulze/xsp/download/
EXTRACT_SUFX=		.tgz
COMMENT=		http server using C/C++/JAVA/Shell xsp based pages
WRKSRC=			${WRKDIR}
NO_BUILD=		yes

do-install:
	@${DO_NADA}

pre-configure:
	@${MV} ${WRKSRC}/*.tar ${DISTDIR}/.


.include "../../mk/bsd.pkg.mk"
