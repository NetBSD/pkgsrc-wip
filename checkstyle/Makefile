# $NetBSD: Makefile,v 1.1 2015/03/14 21:58:24 jihbed Exp $

DISTNAME=	checkstyle-8.19-all
PKGNAME=	${DISTNAME:S/-all//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_GITHUB:=checkstyle/}
GITHUB_PROJECT=	checkstyle
GITHUB_RELEASE=	${PKGNAME}
EXTRACT_SUFX=	.jar

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://checkstyle.org/
COMMENT=	Static code analysis tool for Java
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec ${JAVA_BINPREFIX}-java -jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/checkstyle.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/checkstyle.sh ${DESTDIR}${PREFIX}/bin/checkstyle
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
