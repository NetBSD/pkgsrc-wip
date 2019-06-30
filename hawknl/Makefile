# $NetBSD: Makefile,v 1.2 2015/01/10 20:17:34 thomasklausner Exp $
#

DISTNAME=	HawkNL17b1src
PKGNAME=	hawknl-1.7beta1
CATEGORIES=	net
MASTER_SITES=	http://hawksoft.com/download/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hawksoft.com/hawknl/
COMMENT=	Free, open source, game oriented network API
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/HawkNL1.70/src
INSTALLATION_DIRS+=	include lib

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	makefile.openbsd
SUBST_SED.prefix=	-e "s|/usr/local|${DESTDIR}${PREFIX}|1"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_FILE=	makefile.openbsd
.else
MAKE_FILE=	makefile.${OPSYS:tl}
.endif


.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
