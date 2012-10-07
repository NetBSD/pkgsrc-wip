# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:06 asau Exp $
#

DISTNAME=	simpa-1.2.5
CATEGORIES=	devel parallel java
MASTER_SITES=	http://garr.dl.sourceforge.net/project/simpa/simpa/1.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://alice.unibo.it/xwiki/bin/view/SimpA/
COMMENT=	Agent-oriented framework approach to concurrent, multi-core, distributed programming
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pax
NO_BUILD=	yes
USE_LANGUAGES=	# none

PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15

INSTALLATION_DIRS=	lib/java/simpa/lib share/doc/simpa

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${PREFIX}/lib/java/simpa/lib
	cd ${WRKSRC}/doc && pax -wr -pm * ${DESTDIR}${PREFIX}/share/doc/simpa

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
