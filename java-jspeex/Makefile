# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 22:17:08 jihbed Exp $
#

DISTNAME=	jspeex-0.9.7
PKGNAME=	java-${DISTNAME}
CATEGORIES=	audio java
MASTER_SITES=	http://garr.dl.sourceforge.net/project/jspeex/jspeex/0.9.7/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://jspeex.sourceforge.net/
COMMENT=	Java Implementation of Speex

PKG_DESTDIR_SUPPORT=	user-destdir

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
