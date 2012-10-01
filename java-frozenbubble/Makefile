# $NetBSD: Makefile,v 1.4 2012/10/01 20:27:55 asau Exp $
#

DISTNAME=		frozenBubble
PKGNAME=		java-frozenbubble-0.9.5
CATEGORIES=		games
MASTER_SITES=		http://glenn.sanson.free.fr/fb/
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://glenn.sanson.free.fr/fb/index.html
COMMENT=		Java port of Frozen Bubble

WRKSRC=${WRKDIR}
NO_BUILD=		yes

JAVA_APP_TARGETS=	fb
JAVA_APP_BIN.fb=	java-frozenbubble
JAVA_APP_MAIN.fb=	FrozenBubble
JAVA_APP_CLASSPATH.fb=	${JAR_PREFIX}/frozenbubble.jar

do-extract:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${JAR_PREFIX}/frozenbubble.jar

.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
