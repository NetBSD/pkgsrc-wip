# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		java-getopt-1.0.9
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.urbanophile.com/pub/arenn/software/sources/
EXTRACT_SUFX=		.jar
LICENSE=		gnu-lgpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.urbanophile.com/arenn/hacking/download.html
COMMENT=		GNU getopt port for Java

INSTALLATION_DIRS=	share/classpath

do-extract:

do-build:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${DESTDIR}${PREFIX}/share/classpath/java-getopt.jar

WRKSRC=		${WRKDIR}/

.include "../../mk/bsd.pkg.mk"
