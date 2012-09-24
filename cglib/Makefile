# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=	cglib-2.2
CATEGORIES=	devel java
MASTER_SITES=	http://garr.dl.sourceforge.net/project/cglib/cglib2/2.2/
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
