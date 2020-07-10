# $NetBSD$

GITHUB_PROJECT=	calculator
GITHUB_TAG=	1.5.5
DISTNAME=	1.5.5
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=elementary/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elementary/calculator/
COMMENT=	Elementary Calculator
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/calculator-1.5.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS=		pkg-config
USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../wip/granite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
