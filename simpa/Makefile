# $NetBSD: Makefile,v 1.4 2012/11/13 22:25:49 othyro Exp $
#

DISTNAME=	simpa-1.2.5
CATEGORIES=	devel parallel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simpa/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://alice.unibo.it/xwiki/bin/view/SimpA/
COMMENT=	Agent-oriented framework for concurrent, multi-core, distributed programming
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pax
NO_BUILD=	yes
USE_LANGUAGES=	# none

PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15

INSTALLATION_DIRS=	lib/java/simpa/lib share/doc/simpa

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${PREFIX}/lib/java/simpa/lib
	cd ${WRKSRC}/doc && pax -wr -pm * ${DESTDIR}${PREFIX}/share/doc/simpa

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
