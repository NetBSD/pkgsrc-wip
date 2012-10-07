# $NetBSD: Makefile,v 1.4 2012/10/07 15:52:36 asau Exp $
#

DISTNAME=		snark-0.5
CATEGORIES=		net
MASTER_SITES=		http://www.klomp.org/snark/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.klomp.org/snark/
COMMENT=		BitTorrent application suite in Java

BUILD_TARGET=	snark.jar

# yet defined in java-sh
#JAR_PREFIX=${PREFIX}/share/classpath/

JAVA_APP_TARGETS=snark
JAVA_APP_MAIN.snark=org.klomp.snark.Snark
JAVA_APP_CLASSPATH.snark=${JAR_PREFIX}/snark.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/snark.jar ${DESTDIR}${JAR_PREFIX}/

.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
