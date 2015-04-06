# $NetBSD: Makefile,v 1.3 2015/04/06 10:07:16 krytarowski Exp $

.include "../../wip/keybinder/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for the keybinder library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	--disable-static
CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--enable-python
# Don't rebuild the documentation
CONFIGURE_ARGS+=	--disable-gtk-doc

PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

INSTALL_DIRS=	python-keybinder

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
