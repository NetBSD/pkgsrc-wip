# $NetBSD: Makefile,v 1.3 2012/10/03 18:15:32 asau Exp $
#

DISTNAME=	netlogo-4.1.3
CATEGORIES=	devel java
MASTER_SITES=	http://ccl.northwestern.edu/netlogo/4.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ccl.sesp.northwestern.edu/netlogo/index.shtml
COMMENT=	NetLogo is a multi-agent programmable modeling environment
LICENSE=	apache-2.0

USE_JAVA=	run
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-*

INSTALLATION_DIRS= \
	bin 					\
	lib/java/netlogo/lib 			\
	lib/java/netlogo 			\
	share/doc/netlogo 			\
	lib/java/netlogo/extensions 		\
	share/netlogo/icons 			\
	share/applications

post-extract:
	${CP} ${FILESDIR}/netlogo.desktop ${WRKSRC}
	${CP} ${FILESDIR}/icon.png ${WRKSRC}

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -server -Djava.library.path=${PREFIX}/lib/netlogo/lib -Djava.ext.dirs= -XX:MaxPermSize=128m -Xmx1024m -Duser.language=en -Duser.country=US -jar ${PREFIX}/lib/java/netlogo/NetLogo.jar  \"\$$@\"\\n" >  ${WRKSRC}/netlogo.sh
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -server -Xms16m -Xmx1024m -classpath ${PREFIX}/lib/java/NetLogo.jar org.nlogo.hubnet.client.App \"\$$@\"\\n" > ${WRKSRC}/hubnet.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netlogo.sh ${DESTDIR}${PREFIX}/bin/netlogo
	${INSTALL_SCRIPT} ${WRKSRC}/hubnet.sh ${DESTDIR}${PREFIX}/bin/hubnet
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DESTDIR}${PREFIX}/lib/java/netlogo
	${INSTALL_DATA} ${WRKSRC}/*.xml ${DESTDIR}${PREFIX}/lib/java/netlogo
	${INSTALL_DATA} ${WRKSRC}/icon.png ${DESTDIR}${PREFIX}/share/netlogo/icons
	${INSTALL_DATA} ${WRKSRC}/netlogo.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/netlogo
	cd ${WRKSRC}/lib  && pax -rw -pmp * ${DESTDIR}${PREFIX}/lib/java/netlogo/lib/
	cd ${WRKSRC}/extensions && pax -rw -pmp *  ${DESTDIR}${PREFIX}/lib/java/netlogo/extensions
	cd ${WRKSRC}/docs && pax -wr -pm * ${DESTDIR}${PREFIX}/share/doc/netlogo

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
