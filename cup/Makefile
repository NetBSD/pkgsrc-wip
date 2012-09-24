# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:56 asau Exp $
#

DISTNAME=	java-cup-11a-runtime
PKGNAME=	${DISTNAME:S/-runtime//}
CATEGORIES=	textproc java
MASTER_SITES=	http://www2.cs.tum.edu/projects/cup/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2.cs.tum.edu/projects/cup/
COMMENT=	LALR parser generator for java

WRKSRC=		${WRKDIR}/java-cup-11a-runtime.jar

USE_JAVA=	run
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC} ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
