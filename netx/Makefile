# $NetBSD: Makefile,v 1.6 2012/12/27 12:29:16 othyro Exp $
#

DISTNAME=	netx-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jnlp/}
EXTRACT_SUFX=	.jar
VERSION=	0.5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jnlp.sourceforge.net/netx/
COMMENT=	Free JNLP implementation

NO_BUILD=	yes

JAVA_APP_TARGETS=		jnlp
JAVA_APP_BIN.jnlp=		netx
JAVA_APP_MAIN.jnlp=		netx.jnlp.runtime.Boot13
JAVA_APP_CLASSPATH.jnlp=	${JAR_PREFIX}/netx-${VERSION}.jar
JAVA_APP_PATH=			${DESTDIR}${PREFIX}/bin

INSTALLATION_DIRS+=	bin share/classpath

do-extract:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${JAR_PREFIX}/netx-${VERSION}.jar

.include "../../wip/mk/java-app.mk"
.include "../../mk/bsd.pkg.mk"
