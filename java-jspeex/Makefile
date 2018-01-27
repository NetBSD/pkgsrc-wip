# $NetBSD: Makefile,v 1.4 2012/11/12 16:26:42 othyro Exp $
#

DISTNAME=	jspeex-0.9.7
PKGNAME=	java-${DISTNAME}
CATEGORIES=	audio java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jspeex/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jspeex.sourceforge.net/
COMMENT=	Java Implementation of Speex

WRKSRC=		${WRKDIR}/jspeex

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	run

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jspeex.jar \
		${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
