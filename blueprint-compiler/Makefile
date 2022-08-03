# $NetBSD$

DISTNAME=	blueprint-compiler-v0.2.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.gnome.org/jwestman/blueprint-compiler/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jwestman.pages.gitlab.gnome.org/blueprint-compiler/index.html
COMMENT=	Markup language and compiler for GTK 4 user interfaces
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	blueprint-compiler.py

PKGCONFIG_OVERRIDE+=	blueprint-compiler.pc.in

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
