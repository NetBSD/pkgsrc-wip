# $NetBSD: Makefile,v 1.2 2010/07/11 18:59:38 jihbed Exp $
#

DISTNAME=	jython_installer-2.5.1
PKGNAME=	jython-${VERSION}
CATEGORIES=	lang python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/jython/jython/2.5.1/
EXTRACT_SUFX=	.jar

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.jython.org/
COMMENT=	Interpreted, interactive, object-oriented programming language
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/jython
VERSION=	2.5.1
USE_LANGUAGES=	# none

USE_JAVA=	run
USE_TOOLS+=	pax bash:run
USE_LANGUAGES=	# none
NO_BUILD=	yes

JAVA=	${PREFIX}/bin/openjdk7-java

REPLACE_BASH+=	jython

ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-* FreeBSD-*-* OpenBSD-*-*

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=  26 25

JYTHON_NAME=	${PKGNAME}
TARGET_NAME=	${PREFIX}/${PYSITELIB}/${JYTHON_NAME}/Lib

INSTALLATION_DIRS+=	bin ${TARGET_NAME} ${DOCDIR}  ${HTMLDIR}

post-extract:
	${MKDIR} ${WRKDIR}/jython
	${JAVA} -jar ${WRKDIR}/jython_installer-2.5.1.jar -s -d \
			${WRKDIR}/jython
	${CP} ${FILESDIR}/jython ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jython ${DESTDIR}${PREFIX}/bin/jython
	cd ${WRKSRC}/Lib && pax -rw -pp . ${DESTDIR}${TARGET_NAME}
	${INSTALL_DATA} ${WRKSRC}/jython.jar \
		${DESTDIR}${PREFIX}/${PYSITELIB}/${JYTHON_NAME}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${WRKSRC}/Doc && pax -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
