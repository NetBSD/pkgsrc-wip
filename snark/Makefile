# $NetBSD: Makefile,v 1.1.1.1 2005/01/14 19:17:54 poppnk Exp $
#

DISTNAME=		snark-0.5
CATEGORIES=		wip net
MASTER_SITES=		http://www.klomp.org/snark/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.klomp.org/snark/
COMMENT=		BitTorrent application suite in Java

USE_BUILDLINK3=		yes
BUILD_TARGET=	snark.jar

# yet defined in java-sh
#JAR_PREFIX=${PREFIX}/share/classpath/

JAVA_APP_TARGETS=snark
JAVA_APP_MAIN.snark=org.klomp.snark.Snark
JAVA_APP_CLASSPATH.snark=${JAR_PREFIX}/snark.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/snark.jar ${JAR_PREFIX}/

.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
