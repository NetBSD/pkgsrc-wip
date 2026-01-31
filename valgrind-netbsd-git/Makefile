# $NetBSD$

DISTNAME=	valgrind-netbsd-0.0.20260131
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=paulfloyd/}
GITHUB_TAG=	a2555d14c3156d039e25037b6e03d3489f2a505c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paulfloyd/valgrind-netbsd
COMMENT=	NetBSD port of Valgrind
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/valgrind-netbsd-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	automake autoconf autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
