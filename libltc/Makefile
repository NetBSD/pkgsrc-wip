# $NetBSD$

DISTNAME=	libltc-1.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=x42/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://x42.github.io/libltc/
COMMENT=	POSIX-C Library for handling Linear/Logitudinal Time Code (LTC)
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	ltc.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
