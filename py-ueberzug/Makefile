# $NetBSD$

DISTNAME=	ueberzug-18.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ueber-devel/}
GITHUB_PROJECT=	ueberzug
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ueber-devel/ueberzug/
COMMENT=	Command line utility which allows drawing images on terminals
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

REPLACE_PYTHON+=	ueberzug/__main__.py

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
