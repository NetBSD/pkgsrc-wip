# $NetBSD: Makefile,v 1.1 2012/09/16 22:36:24 jihbed Exp $
#

DISTNAME=	sarf
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	textproc java
MASTER_SITES=	http://garr.dl.sourceforge.net/project/sarf/sarf/sarf%201.0/
EXTRACT_SUFX=	.jar

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://sourceforge.net/projects/sarf/
COMMENT=	Arabic Morphology System


PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

VERSION=	1.0
USE_LANGUAGES=	# none

PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15
USE_JAVA2= yes

INSTALLATION_DIRS= bin  lib/java

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/${DISTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.sh ${DESTDIR}${PREFIX}/bin/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
