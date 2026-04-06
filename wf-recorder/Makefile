# $NetBSD$

DISTNAME=	wf-recorder-0.6.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ammen99/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/ammen99/wf-recorder/
COMMENT=	Screen recorder for wlroots-based compositors
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	meson.build
SUBST_SED.path+=	-e 's/fish\/fish/fish/'

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
