# $NetBSD$

DISTNAME=	JDim-0
PKGNAME=	jdim-current-0
CATEGORIES=	chat

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jdimproved.github.io/JDim/
COMMENT=	2ch browser for *nix
LICENSE=	gnu-gpl-v2

GIT_REPO=	https://github.com/JDimproved/JDim.git

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

.include "options.mk"

MESON_ARGS+=	-Dpackager=pkgsrc

.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
