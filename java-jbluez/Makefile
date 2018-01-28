# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		jbluez-1.0
PKGNAME=		java-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jbluez/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jbluez.sourceforge.net/
COMMENT=		Java interface for BlueZ stack

USE_TOOLS=	gmake
USE_JAVA=	YES
MAKE_ENV=	JDK_HOME=${PKG_JAVA_HOME}

WRKSRC=		${WRKDIR}/src

SUBST_CLASSES+=	jh
SUBST_STAGE.jh=	pre-build
SUBST_FILES.jh=	c/Makefile
SUBST_SED.jh=	-e 's,/usr/lib/java,${PKG_JAVA_HOME},g'

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKDIR}/bin/jbluez.jar ${DESTDIR}${PREFIX}/lib/java/
	${INSTALL_LIB} ${WRKDIR}/bin/libjbluez.so ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/jbluez/
	${CP} -rf ${WRKDIR}/javadoc/* ${DESTDIR}${PREFIX}/share/doc/jbluez/

.include "../../mk/java-vm.mk"
.include "../../wip/bluez-libs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
