# $NetBSD: Makefile,v 1.1.1.1 2006/06/11 12:58:19 poppnk Exp $
#

DISTNAME=		netx-${VERSION}
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jnlp/}
EXTRACT_SUFX=		.jar
VERSION=		0.5

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jnlp.sourceforge.net/
COMMENT=		A free JNLP implementation

NO_BUILD=#defined

JAVA_APP_TARGETS=	jnlp
JAVA_APP_BIN.jnlp=	netx
JAVA_APP_MAIN.jnlp=	netx.jnlp.runtime.Boot13
JAVA_APP_CLASSPATH.jnlp=	${JAR_PREFIX}/netx-${VERSION}.jar

do-extract:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${JAR_PREFIX}/netx-${VERSION}.jar

.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
