# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:37 asau Exp $
#

DISTNAME=	commons-dbcp-1.4-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	databases  java
MASTER_SITES=	http://mirror.cloudera.com/apache//commons/dbcp/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://commons.apache.org/dbcp/
COMMENT=	Database Connection Pooling Services
LICENSE=	apache-2.0

DEPENDS+=	apache-commons-collections>=3.2.1:../../wip/apache-commons-collections
DEPENDS+=	apache-commons-pool>=1.5.5:../../wip/apache-commons-pool


WRKSRC=		${WRKDIR}/commons-dbcp-1.4

NO_BUILD=	yes
USE_TOOLS+=	pax

USE_JAVA=		yes
USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-dbcp

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-dbcp-1.4.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-dbcp.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-dbcp



.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
