# $NetBSD: Makefile,v 1.1 2014/10/24 01:29:27 makoto Exp $
#

DISTNAME=	flexdock-1.2.4
CATEGORIES=	devel
MASTER_SITES=	http://forge.scilab.org/index.php/p/flexdock/downloads/get/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flexdock.dev.java.net/
COMMENT=	Swing windowing and docking framework
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_JAVA=	run

INSTALLATION_DIRS=	\
	lib/java/flexdock \
	lib/java/flexdock/lib \
	lib/java/flexdock/lib/jmf \
	lib/java/flexdock/lib/jmf/doc \
	lib/java/flexdock/lib/jmf/lib \
	share/examples/flexdock

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

do-build:
	${MKDIR} ${WRKSRC}
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/flexdock/flexdock-demo-${PKGVERSION_NOREV}.jar \"\$$@\"\\n" > ${WRKDIR}/flexdock.sh

FD_FILES=	\
	lib/jmf/doc/readme.html \
	lib/jmf/lib/customizer.jar \
	lib/jmf/lib/jmf.jar \
	lib/jmf/lib/jmf.properties \
	lib/jmf/lib/mediaplayer.jar \
	lib/jmf/lib/multiplayer.jar \
	lib/LICENSE.txt \
	lib/looks-2.1.1.jar \
	lib/skinlf.jar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/flexdock.sh ${DESTDIR}${PREFIX}/share/examples/flexdock/
.for tmp in ${FD_FILES}
	${INSTALL_DATA} ${WRKSRC}/${tmp}  ${DESTDIR}${PREFIX}/lib/java/flexdock/${tmp}
.endfor

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
