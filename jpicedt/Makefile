# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:43 othyro Exp $
#

VERSION=	1.4.1-03
DISTNAME=	jpicedt-install_1_4_1_03_20071021
PKGNAME=	jpicedt-${VERSION}
CATEGORIES=	print java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jpicedt/}
EXTRACT_SUFX=	.jar

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.jpicedt.org/
COMMENT=	Interactive picture edtor for LaTeX and PSTricks
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	run
USE_JAVA2=	yes

INSTALLATION_DIRS=	bin  share/applications   lib/java/jpicedt

post-extract:
	cd ${WRKDIR} && ${JAVA_BINPREFIX}-jar -xf jpicedt-install_1_4_1_03_20071021.jar

do-build:
	${ECHO} "Create jpicedt.desktop:"
	${ECHO} "[Desktop Entry]" > ${WRKSRC}/jpicedt.desktop
	${ECHO} "GenericName=Interactive picture edtor for LaTeX and PSTricks" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "Exec= jpicedt" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "Terminal=false" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "X-MultipleArgs=false" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "Type=Application" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "Categories=Development;" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "Encoding=UTF-8" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "StartupNotify=true" >> ${WRKSRC}/jpicedt.desktop
	${ECHO} "Create jpicedt script:"
	printf "#!${SH}\\nJAVA_HEAP_SIZE=96\\nexec ${PKG_JAVA_HOME}/bin/java -Xmx${JAVA_HEAP_SIZE}m \"${JPICEDT}\" -classpath \"${CLASSPATH}\":${PREFIX}/lib/java/jpicedt/lib/jpicedt.JPicEdt \"\$$@\"\\n" > ${WRKSRC}/jpicedt.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jpicedt.sh ${DESTDIR}${PREFIX}/bin/jpicedt
	${INSTALL_DATA} ${WRKSRC}/jpicedt.desktop	${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${PREFIX}/lib/java/jpicedt/
	cd ${WRKSRC}/add-ons && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/jpicedt/add-ons
	cd ${WRKSRC}/add-ons && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/jpicedt/api-doc
	cd ${WRKSRC}/add-ons && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/jpicedt/fragments
	cd ${WRKSRC}/add-ons && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/jpicedt/help-files
	cd ${WRKSRC}/add-ons && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/jpicedt/lang
	cd ${WRKSRC}/add-ons && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/jpicedt/macros

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
