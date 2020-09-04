# $NetBSD: Makefile,v 1.2 2015/02/19 18:01:20 jihbed Exp $

DISTNAME=	cinnamon-screensaver-4.6.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cinnamon-screensaver
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.com
HOMEPAGE=	https://github.com/linuxmint/cinnamon-screensaver
COMMENT=	Cinnamon screensaver
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config automake autoreconf intltool msgfmt

WRKSRC=	${WRKDIR}/cinnamon-screensaver-4.6.0

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../wip/xapps/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
