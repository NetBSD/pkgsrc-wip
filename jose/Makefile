# $NetBSD$

DISTNAME=	v11
PKGNAME=	jose-${DISTNAME:S/v//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=latchset/}
GITHUB_TAG=	${PKGVERSION_NOREV}
DIST_SUBDIR=	jose

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/latchset/jose/
COMMENT=	C implementation of JOSE
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config cmake

BUILD_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

post-install:
	rm -rf ${DESTDIR}/usr/pkg/share/licenses/jose

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
