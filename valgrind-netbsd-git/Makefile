# $NetBSD$

DISTNAME=	valgrind-netbsd-0.0.20260201
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=paulfloyd/}
# head of branch of 'fosdem26' as of date above
GITHUB_TAG=	5b8a5e38549de9c93e35c2eb26cc5947da398a5e

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
