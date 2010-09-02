# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:35:35 jihbed Exp $
#

DISTNAME=	Jason-1.3.3
PKGNAME=	${DISTNAME:S/J/j/}
CATEGORIES=	devel net
MASTER_SITES=	http://garr.dl.sourceforge.net/project/jason/jason/version%201.3.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://jason.sourceforge.net/Jason/Jason.html
COMMENT=	Java-based interpreter for an extended version of AgentSpeak
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

INSTALLATION_DIRS=   	bin					 \
					lib/java/jason/bin		\
					lib/java/jason/bin/jedit	\
					lib/java/jason/lib		\
				 	share/applications 		\
					share/doc/jason 		\
					share/examples/jason

post-extract:
	${CP} ${FILESDIR}/jason.desktop ${WRKSRC}

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -classpath "${PREFIX}/lib/java/jason/jason.jar":"${PREFIX}/lib/java/jason/jedit/jedit.jar":"${PREFIX}/lib/java/jason/lib/saci.jar":"${PREFIX}/lib/java/jason/lib/jade.jar":"${PREFIX}/lib/java/jason/lib/http.jar":"${PREFIX}/lib/java/jason/jedit/jars/ErrorList.jar":"${PREFIX}/lib/java/jason/jedit/jars/SideKick.jar" org.gjt.sp.jedit.jEdit \"\$$1\"\\n" >${WRKSRC}/jason

do-install:
	${INSTALL_DATA} ${WRKSRC}/jason ${DESTDIR}${PREFIX}/lib/java/jason/bin
	${INSTALL_DATA} ${WRKSRC}/jason.desktop ${DESTDIR}${PREFIX}/share/applications
	cd ${WRKSRC}/bin/jedit && pax -wr -pm * ${DESTDIR}${PREFIX}/lib/java/jason/bin/jedit
	cd ${WRKSRC}/lib && pax -wr -pm * ${DESTDIR}${PREFIX}/lib/java/jason/lib
	cd ${WRKSRC}/doc && pax -wr -pm * ${DESTDIR}${PREFIX}/share/doc/jason
	cd ${WRKSRC}/examples && pax -wr -pm * \
		${DESTDIR}${PREFIX}/share/examples/jason


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
