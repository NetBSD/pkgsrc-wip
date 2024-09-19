# $NetBSD: Makefile,v 1.1 2015/08/10 20:11:58 yhardy Exp $

GITHUB_PROJECT=	weatherman
DISTNAME=	1.2.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=subrosa2/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/subrosa2/weatherman/
COMMENT=	Display weather information from WeatherBug on the command line
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/weatherman-1.2.2
USE_LANGUAGES=	# none

USE_TOOLS+=	bash gunzip

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	curl-[0-9]*:../../www/curl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

NO_BUILD=	yes

REPLACE_BASH=	weatherman

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/weatherman ${DESTDIR}${PREFIX}/bin
	${GUNZIP_CMD} ${WRKSRC}/weatherman.1.gz
	${INSTALL_DATA} ${WRKSRC}/weatherman.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
