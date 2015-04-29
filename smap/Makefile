# $NetBSD: Makefile,v 1.1 2015/04/29 15:09:13 gschwarz Exp $

PKGNAME=	smap-0.6.0
DISTNAME=	smap-20081016
CATEGORIES=	security
MASTER_SITES=	https://downloads.openwrt.org/sources/
MASTER_SITES+=	http://mirror2.openwrt.org/sources/

MAINTAINER=	schwarz@NetBSD.org
COMMENT=	SIP network scanner
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/smap
NO_CONFIGURE=	YES
USE_TOOLS+=	gmake

SUBST_CLASSES+=	cflags
SUBST_FILES.cflags=	Makefile
SUBST_SED.cflags=	-e 's/^CFLAGS=/CFLAGS?=/g'
SUBST_STAGE.cflags=	post-patch

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smap ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
