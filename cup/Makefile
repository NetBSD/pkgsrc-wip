# $NetBSD: Makefile,v 1.2 2012/09/10 11:03:29 jihbed Exp $
#

DISTNAME=	java-cup-11a-runtime
PKGNAME=	${DISTNAME:S/-runtime//}
CATEGORIES=	textproc java
MASTER_SITES=	http://www2.cs.tum.edu/projects/cup/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2.cs.tum.edu/projects/cup/
COMMENT=	LALR parser generator for java

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/java-cup-11a-runtime.jar

USE_JAVA=	run
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC} ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
