# $NetBSD: Makefile,v 1.1.1.1 2010/08/03 18:53:20 jihbed Exp $
#

DISTNAME=	cartago-1.4.0
CATEGORIES=	devel
MASTER_SITES=	http://garr.dl.sourceforge.net/project/cartago/cartago/1.4/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://alice.unibo.it/xwiki/bin/view/CARTAGO/
COMMENT= Framework for programming and executing environments in multi-agent
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax
NO_BUILD=	yes
USE_LANGUAGES=	# none

PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15

INSTALLATION_DIRS=	lib/java/cartago/lib share/doc/cartago

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${PREFIX}/lib/java/cartago/lib
	cd ${WRKSRC}/doc && pax -wr -pm * ${DESTDIR}${PREFIX}/share/doc/cartago

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
