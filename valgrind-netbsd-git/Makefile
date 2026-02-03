# $NetBSD$

DISTNAME=	valgrind-netbsd-0.0.20260203
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=paulfloyd/}
# head of branch of 'fosdem26' as of date above
GITHUB_TAG=	542995e04e0f69815d4d2e22918bbc5a0c4dabd4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paulfloyd/valgrind-netbsd
COMMENT=	NetBSD port of Valgrind
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/valgrind-netbsd-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	automake autoconf autoreconf perl

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
