# $NetBSD: Makefile,v 1.4 2012/11/14 00:16:04 othyro Exp $
#

DISTNAME=	elk-1.1.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=elk/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://elk.sourceforge.net/
COMMENT=	All-electron full-potential linearised augmented-planewave
LICENSE=	gnu-gpl-v3

DEPENDS+=	gnuplot>=4.2.6:../../graphics/gnuplot

WRKSRC=		${WRKDIR}/elk

MAKE_JOBS_SAFE=		NO
ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-*

MAKEFILE_FILE=	make.inc
USE_TOOLS+=	gmake bash:run
USE_LANGUAGES=	fortran

REPLACE_BASH+=	utilities/elk-bands

INSTALLATION_DIRS=	bin share/elk/species share/doc/elk

do-configure:
	cd ${WRKSRC} && ${SH} setup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/elk ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/spacegroup/spacegroup ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utilities/elk-bands ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/species/*.in ${DESTDIR}${PREFIX}/share/elk/species
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DESTDIR}${PREFIX}/share/doc/elk

.include "../../mk/bsd.pkg.mk"
