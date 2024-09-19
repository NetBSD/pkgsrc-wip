# $NetBSD: Makefile,v 1.2 2015/04/30 06:46:46 gschwarz Exp $

DISTNAME=	smap-20081016
PKGNAME=	smap-0.6.0
CATEGORIES=	security
MASTER_SITES=	http://dev.gateworks.com/sources/
MASTER_SITES+=	https://github.com/jslink/openwrt-trunk-dl/raw/master/
MASTER_SITES+=	http://pandorabox.tuuz.cc:8000/sources/
MASTER_SITES+=	http://mirror2.openwrt.org/sources/

MAINTAINER=	schwarz@NetBSD.org
COMMENT=	SIP network scanner
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/smap
NO_CONFIGURE=	YES
USE_TOOLS+=	gmake

CFLAGS+=	-DHAVE_STRNSTR
CFLAGS+=	-DHAVE_IFADDRS
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	-lm
LDFLAGS+=	${PTHREAD_LDFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

SUBST_CLASSES+=		cflags
SUBST_FILES.cflags=	Makefile
SUBST_SED.cflags=	-e 's/^CFLAGS=/CFLAGS?=/g'
SUBST_SED.cflags+=	-e 's/^LDFLAGS=/LDFLAGS?=/g'
SUBST_STAGE.cflags=	post-patch

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smap ${DESTDIR}${PREFIX}/bin

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
