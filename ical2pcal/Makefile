# $NetBSD$

GITHUB_PROJECT=	ical2pcal
DISTNAME=	862912973dc5404e3f98e7f8b546eca43d56e14b
# version number is inside the script
PKGNAME=	${GITHUB_PROJECT}-0.0.7
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=pmarin/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	862912973dc5404e3f98e7f8b546eca43d56e14b

MAINTAINER=	cherry@zyx.in
HOMEPAGE=	https://github.com/pmarin/ical2pcal/
COMMENT=	Convert iCalendar (.ics) data files to pcal data files
LICENSE=	mit

NO_BUILD=	yes
USE_TOOLS+=	bash:run
AUTO_MKDIRS=	yes
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-862912973dc5404e3f98e7f8b546eca43d56e14b

REPLACE_BASH=	${WRKSRC}/ical2pcal.sh
USE_TOOLS=	bash

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ical2pcal/
	${INSTALL_SCRIPT} ${WRKSRC}/ical2pcal.sh ${DESTDIR}${PREFIX}/bin/ical2pcal

.include "../../mk/bsd.pkg.mk"
