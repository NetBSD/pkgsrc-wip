# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:34 asau Exp $
#

DISTNAME=	AOKell-2.0-bin
PKGNAME=	aokell-2.0
CATEGORIES=	devel java
MASTER_SITES=	http://download.forge.objectweb.org/fractal/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fractal.ow2.org/aokell/index.html
COMMENT=	AOKell is a Java implementation of the Fractal component model
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/AOKell-2.0

NO_BUILD=	yes
USE_TOOLS+=	pax

PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15
USE_JAVA2=		yes

INSTALLATION_DIRS=	share/doc/aokell lib/java/aokell

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/aokell
	cd ${WRKSRC}/externals  && pax -rw -pp . ${DESTDIR}${PREFIX}/lib/java/aokell/externals
	cd ${WRKSRC}/lib  && pax -rw -pp . ${DESTDIR}${PREFIX}/lib/java/aokell/lib
	cd ${WRKSRC}/doc/javadoc && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/aokell

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
