# $NetBSD: Makefile,v 1.3 2005/04/11 21:13:18 tvierling Exp $
#

DISTNAME=		java-getopt-1.0.9
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.urbanophile.com/pub/arenn/software/sources/
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/download.html
COMMENT=		GNU getopt port for Java

do-extract:

do-build:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${PREFIX}/share/classpath/java-getopt.jar

WRKSRC=		${WRKDIR}/

.include "../../mk/bsd.pkg.mk"
