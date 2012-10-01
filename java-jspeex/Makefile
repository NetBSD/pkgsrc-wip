# $NetBSD: Makefile,v 1.3 2012/10/01 21:43:22 asau Exp $
#

DISTNAME=	jspeex-0.9.7
PKGNAME=	java-${DISTNAME}
CATEGORIES=	audio java
MASTER_SITES=	http://garr.dl.sourceforge.net/project/jspeex/jspeex/0.9.7/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jspeex.sourceforge.net/
COMMENT=	Java Implementation of Speex

WRKSRC=		${WRKDIR}/jspeex

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	run

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jspeex.jar \
		${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
