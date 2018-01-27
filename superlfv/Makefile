# $NetBSD: Makefile,v 1.1 2014/07/27 00:10:12 jihbed Exp $

DISTNAME=	superlfv-1.0-0
PKGNAME=	${DISTNAME:S/-0//}
CATEGORIES=	math java
MASTER_SITES=	http://www.hepforge.org/archive/superlfv/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://superlfv.hepforge.org/Super_LFV.html
COMMENT=	Calculate lepton flavor violating observables
LICENSE=	mit

WRKSRC=		${WRKDIR}/superlfv-1.0

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -classpath ${PREFIX}/lib/java/superlfv.jar superlfv \"\$$@\"\\n" > ${WRKSRC}/superlfv.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/superlfv.sh ${DESTDIR}${PREFIX}/bin/superlfv
	${INSTALL_DATA} ${WRKSRC}/superlfv.jar ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
