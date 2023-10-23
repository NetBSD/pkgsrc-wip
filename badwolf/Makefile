# $NetBSD$

DISTNAME=	badwolf-1.3.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://hacktivis.me/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hacktivis.me/projects/badwolf
COMMENT=	Minimalist and privacy-oriented webkit browser
LICENSE=	modified-bsd

DEPENDS+=	ninja-build>=1.7:../../devel/ninja-build

USE_TOOLS+=		pkg-config
#USE_PKGLOCALEDIR=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2
DEPENDS+=	ninja-build>=1.7:../../devel/ninja-build

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ninja -j ${MAKE_JOBS:U1}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		ninja -j ${MAKE_JOBS:U1} install

#.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
