# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:19 thomasklausner Exp $
#

DISTNAME=		jbluez-1.0
PKGNAME=		java-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jbluez/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jbluez.sourceforge.net/
COMMENT=		Java interface for BlueZ stack

USE_TOOLS=gmake
USE_JAVA= YES
MAKE_ENV=JDK_HOME=${PKG_JAVA_HOME}

WRKSRC=		${WRKDIR}/src

SUBST_CLASSES=jh
SUBST_STAGE.jh=pre-build
SUBST_FILES.jh= c/Makefile
SUBST_SED.jh= -e 's,/usr/lib/java,${PKG_JAVA_HOME},g'

do-install:
	${INSTALL_DATA} ${WRKDIR}/bin/jbluez.jar ${PREFIX}/lib/java/
	${INSTALL_LIB} ${WRKDIR}/bin/libjbluez.so ${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jbluez/
	${CP} -rf ${WRKDIR}/javadoc/* ${PREFIX}/share/doc/jbluez/

.include "../../mk/java-vm.mk"
.include "../../wip/bluez-libs/Makefile.common"
.include "../../mk/bsd.pkg.mk"
