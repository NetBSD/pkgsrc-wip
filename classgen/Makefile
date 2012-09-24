# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:54 asau Exp $
#

DISTNAME=	classgen-1.4-bin
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel
MASTER_SITES=	http://classgen.sourceforge.net/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://classgen.sourceforge.net/
COMMENT=	Java tool to generate class frameworks and visitor patterns
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/classgen-1.4

USE_JAVA=	run
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin lib/java share/doc/classgen

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/classgen.jar \"\$$@\"\\n" > ${WRKSRC}/classgen.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/classgen.sh ${DESTDIR}${PREFIX}/bin/classgen
	${INSTALL_DATA} ${WRKSRC}/lib/classgen.jar ${DESTDIR}${PREFIX}/lib/java/
	cd ${WRKSRC}/docs && pax -wr -pm * ${DESTDIR}${PREFIX}/share/doc/classgen

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
