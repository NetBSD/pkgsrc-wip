# $NetBSD: Makefile,v 1.1.1.1 2004/03/21 00:19:19 poppnk Exp $
#

DISTNAME=		java-getopt-1.0.9
CATEGORIES=		wip
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
USE_BUILDLINK3=		yes

.include "../../mk/bsd.pkg.mk"
