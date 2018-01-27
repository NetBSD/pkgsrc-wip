# $NetBSD: Makefile,v 1.3 2015/03/19 22:44:57 jihbed Exp $
#

DISTNAME=	oslc3.0
PKGNAME=	oslc-3.0
CATEGORIES=	devel java
MASTER_SITES=	http://download.forge.objectweb.org/oslcv3/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wiki.objectweb.org/oslcv3/
COMMENT=	Open Source License Checker
LICENSE=	gnu-gpl-v2

#DEPENDS+=	itext>=5.3.4:../../wip/itext

WRKSRC=		${WRKDIR}

USE_JAVA=	run
USE_TOOLS+=	bash pax perl
USE_LANGUAGES=	# none

REPLACE_BASH+=	licenses/test.sh licenses/create_template.sh  \
		licenses/buildall.sh     licenses/create_meta.sh

REPLACE_PERL+=		licenses/add_compatible.pl

INSTALLATION_DIRS= \
	bin				\
	share/applications		\
	lib/java/oslc			\
	lib/java/oslc/doc  		\
	lib/java/oslc/licenses 		\
	lib/java/oslc/resources

do-build:
	${ECHO} "Create oslc.desktop:"
	${ECHO} "[Desktop Entry]" > ${WRKSRC}/oslc.desktop
	${ECHO} "GenericName=Open Source License Checker" >> ${WRKSRC}/oslc.desktop
	${ECHO} "Exec= ${PREFIX}/lib/java/oslc/oslcgui" >> ${WRKSRC}/oslc.desktop
	${ECHO} "Terminal=false" >> ${WRKSRC}/oslc.desktop
	${ECHO} "X-MultipleArgs=false" >> ${WRKSRC}/oslc.desktop
	${ECHO} "Type=Application" >> ${WRKSRC}/oslc.desktop
	${ECHO} "Categories=Development;" >> ${WRKSRC}/oslc.desktop
	${ECHO} "Encoding=UTF-8" >> ${WRKSRC}/oslc.desktop
	${ECHO} "StartupNotify=true" >> ${WRKSRC}/oslc.desktop
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -Xms512M -Xmx512M -jar ${PREFIX}/lib/java/oslc/oslc.jar \n" > ${WRKSRC}/oslcgui
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -Xms512M -Xmx512M -jar ${PREFIX}/lib/java/oslc/oslc.jar --$@\n" > ${WRKSRC}/oslccli

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oslcgui ${DESTDIR}${PREFIX}/lib/java/oslc
	${INSTALL_SCRIPT} ${WRKSRC}/oslccli ${DESTDIR}${PREFIX}/lib/java/oslc
	${LN} -sf ${DESTDIR}${PREFIX}/lib/java/oslc/oslcgui ${DESTDIR}${PREFIX}/bin/oslcgui
	${LN} -sf ${DESTDIR}${PREFIX}/lib/java/oslc/oslccli ${DESTDIR}${PREFIX}/bin/oslccli
	${INSTALL_DATA} ${WRKSRC}/oslc.desktop  ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DESTDIR}${PREFIX}/lib/java/oslc
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/lib/java/oslc
	cd ${WRKSRC}/documentation && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/oslc/doc
	cd ${WRKSRC}/licenses && pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/oslc/licenses
	cd ${WRKSRC}/resources&& pax -rw -pp * ${DESTDIR}${PREFIX}/lib/java/oslc/resources

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
