# $NetBSD: Makefile,v 1.4 2012/11/12 15:59:46 othyro Exp $
#

DISTNAME=	cglib-2.2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cglib/}
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cglib.sourceforge.net/
COMMENT=	Code generation library for Java
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/cglib-2.2.jar

NO_BUILD=	yes
USE_JAVA=	run
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib/java/

do-install:
	${INSTALL_DATA} ${WRKSRC} ${DESTDIR}${PREFIX}/lib/java/
	${LN} -s ${DESTDIR}${JAVADIR}/cglib-2.2.jar  ${DESTDIR}${PREFIX}/lib/java/cglib.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
