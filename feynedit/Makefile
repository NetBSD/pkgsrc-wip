# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:04 othyro Exp $
#

DISTNAME=	FeynEdit-1.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	java graphics
MASTER_SITES=	http://www.feynarts.de/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.feynarts.de/
COMMENT=	Tool for drawing Feynman diagrams
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PKG_JVMS_ACCEPTED=	sun-jdk7

INSTALLATION_DIRS=	bin share/doc/feynedit

do-build:
	${ECHO} "Create jpicedt.desktop:"
	${ECHO} "[Desktop Entry]" > ${WRKSRC}/feynedit.desktop
	${ECHO} "Tool for drawing Feynman diagrams" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "Exec= jpicedt" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "Terminal=false" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "X-MultipleArgs=false" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "Type=Application" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "Categories=Development;" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "Encoding=UTF-8" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "StartupNotify=true" >> ${WRKSRC}/feynedit.desktop
	${ECHO} "Create feynedit script:"
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/FeynEdit.jar \"\$$@\"\\n" > ${WRKSRC}/feynedit.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/feynedit.sh ${DESTDIR}${PREFIX}/bin/feynedit
	${INSTALL_DATA} ${WRKSRC}/FeynEdit.pdf ${DESTDIR}${PREFIX}/share/doc/feynedit

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
