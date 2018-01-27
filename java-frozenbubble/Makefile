# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		frozenBubble
PKGNAME=		java-frozenbubble-0.9.5
CATEGORIES=		games
MASTER_SITES=		http://glenn.sanson.free.fr/fb/
EXTRACT_SUFX=		.jar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://glenn.sanson.free.fr/fb/index.html
COMMENT=		Java port of Frozen Bubble

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

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
