# $NetBSD: Makefile,v 1.8 2012/11/23 22:33:39 othyro Exp $
#

VERSION=	2.5.2b1
DISTNAME=	jython_installer-${VERSION}
PKGNAME=	${DISTNAME:S/_installer//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jython/}
EXTRACT_SUFX=	.jar

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.jython.org/
COMMENT=	Python for the Java Platform
LICENSE=	python-software-foundation

WRKSRC=		${WRKDIR}/jython_installer-2.5.2b1.jar

USE_TOOLS+=	pax bash
NO_BUILD=	yes
USE_LANGUAGES=	# none

JYTHON_NAME=	${PKGNAME}

ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-* FreeBSD-*-* OpenBSD-*-*

PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15
MAKE_ENV+=		JAVA_HOME=${PKG_JAVA_HOME}

REPLACE_PYTHON+=	jython

PY_PATCHPLIST=	yes

TMPJYTHON=	${WRKDIR}/temp.jython
TARGET_NAME=	${PREFIX}/${PYSITELIB}/${JYTHON_NAME}/Lib

INSTALLATION_DIRS+=	bin                       \
					share/doc/jython  \
					lib/java/jython      \
					lib/java/jython/Lib

post-extract:
	${JAVA_BINPREFIX}-java  -jar ${WRKDIR}/${DISTNAME}.jar -s -d ${TMPJYTHON}

do-install:
	${INSTALL_DATA} ${TMPJYTHON}/jython ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${TMPJYTHON}/registry ${DESTDIR}${PREFIX}/lib/java/jython
	${INSTALL_DATA} ${TMPJYTHON}/jython.jar ${DESTDIR}${PREFIX}/lib/java/jython
	${INSTALL_DATA} ${TMPJYTHON}/ACKNOWLEDGMENTS \
			${DESTDIR}${PREFIX}/share/doc/jython
	${INSTALL_DATA} ${TMPJYTHON}/*.txt ${DESTDIR}${PREFIX}/share/doc/jython
	cd ${TMPJYTHON}/Lib && pax -rw -pp . ${DESTDIR}${PREFIX}/lib/java/jython/Lib
	cd ${TMPJYTHON}/Doc && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/jython


.include "../../lang/python/extension.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
