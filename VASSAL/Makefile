# $NetBSD: Makefile,v 1.1 2014/08/13 19:26:45 thomasklausner Exp $

DISTNAME=	VASSAL-3.2.13-other
PKGNAME=	${DISTNAME:S/-other//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vassalengine/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vassalengine.sourceforge.net/
COMMENT=	Game engine for building and playing board and card games
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin share/${PKGBASE}

do-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/VASSAL.sh
	${ECHO} "cd ${PREFIX}/share/${PKGBASE} && exec ${JAVA_BINPREFIX}-java -classpath lib/Vengine.jar VASSAL.launch.ModuleManager "'"$$@"' >> ${WRKDIR}/VASSAL.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/VASSAL.sh ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${PREFIX}/share/${PKGBASE}
	cd ${DESTDIR}${PREFIX}/share/${PKGBASE} && ${CHMOD} a-wx */*.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
