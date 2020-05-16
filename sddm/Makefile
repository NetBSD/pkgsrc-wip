# $NetBSD$

DISTNAME=	sddm-0.18.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sddm/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sddm/sddm
COMMENT=	QML based X11 and Wayland display manager
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.if !exists(/etc/login.defs)
CMAKE_ARGS+=	-DUID_MIN=1000
CMAKE_ARGS+=	-DUID_MAX=65000
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths+=	src/common/Configuration.h
SUBST_FILES.paths+=	data/man/sddm.conf.rst.in
SUBST_SED.paths+=	-e 's,/usr/bin/X,${X11BASE}/bin/X,g'
SUBST_SED.paths+=	-e 's,/usr/bin/Xephyr,${X11BASE}/bin/Xephyr,g'
SUBST_SED.paths+=	-e 's,/usr/bin/xauth,${X11BASE}/bin/xauth,g'
SUBST_SED.paths+=	-e 's,/usr/share/xsessions,${PREFIX}/share/xsessions,g'
SUBST_SED.paths+=	-e 's,/usr/share/wayland-sessions,${PREFIX}/share/wayland-sessions,g'
SUBST_SED.paths+=	-e 's,/usr/local/bin,${PREFIX}/bin:/usr/local/bin,g'

LDFLAGS.FreeBSD+=	-lutil
LDFLAGS.NetBSD+=	-lutil

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
