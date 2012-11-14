# $NetBSD: Makefile,v 1.4 2012/11/14 00:16:12 othyro Exp $
#

DISTNAME=		netx-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jnlp/}
EXTRACT_SUFX=		.jar
VERSION=		0.5

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jnlp.sourceforge.net/
COMMENT=		Free JNLP implementation

NO_BUILD=#defined

JAVA_APP_TARGETS=	jnlp
JAVA_APP_BIN.jnlp=	netx
JAVA_APP_MAIN.jnlp=	netx.jnlp.runtime.Boot13
JAVA_APP_CLASSPATH.jnlp=	${JAR_PREFIX}/netx-${VERSION}.jar

do-extract:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${JAR_PREFIX}/netx-${VERSION}.jar

.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
