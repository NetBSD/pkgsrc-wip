# $NetBSD$

DISTNAME=	ltc-tools-0.6.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=x42/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/x42/ltc-tools/
COMMENT=	Tools to deal with linear-timecode (LTC)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	mandir=%{PREFIX}/${PKGMANDIR}

.include "../../audio/jack/buildlink3.mk"
.include "../../wip/libltc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
