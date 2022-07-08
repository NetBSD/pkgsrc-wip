# $NetBSD$

GITHUB_PROJECT=	budgie-desktop
GITHUB_TAG=	v10.6.1
DISTNAME=	v10.6.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	X11
MASTER_SITES=	${MASTER_SITE_GITHUB:=BuddiesOfBudgie/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BuddiesOfBudgie/budgie-desktop/
COMMENT=	Budgie  desktop env
LICENSE=	gnu-gpl-v2

USE_TOOLS=	pkg-config

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${PREFIX}/bin/meson build && \
	{PREFIX}/bin/ninja -C build

.include "../../devel/meson/build.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

