# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:32:23 jihbed Exp $
#

DISTNAME=	scimark2src
PKGNAME=	scimark2-2.0
CATEGORIES=	benchmarks java
MASTER_SITES=	http://math.nist.gov/scimark2/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://math.nist.gov/scimark2/index.html
COMMENT=	Java benchmark for scientific and numerical computing

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

USE_JAVA=  run
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

SCMDIR=	${PREFIX}/lib/java/scimark2
SCMJDIR=	${PREFIX}/lib/java/scimark2/jnt

INSTALLATION_DIRS=	bin ${SCMJDIR}

do-build:
	cd ${WRKSRC} && ${JAVA_BINPREFIX}-javac commandline.java
	${CP} ${WRKSRC}/commandline.class ${WRKSRC}/jnt/scimark2
	${ECHO} "#!/bin/sh" > ${WRKSRC}/scimark2-java.sh
	${ECHO} "cd ${SCMDIR} && ${PKG_JAVA_HOME}/bin/java jnt.scimark2.commandline" '$$1' > ${WRKSRC}/scimark2-java.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scimark2-java.sh ${DESTDIR}${PREFIX}/bin/scimark2-java
	cd ${WRKSRC}/jnt && pax -rw -pp . ${DESTDIR}${SCMJDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
