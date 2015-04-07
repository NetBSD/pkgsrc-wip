# $NetBSD: Makefile,v 1.5 2015/04/07 16:14:35 krytarowski Exp $

.include "../../wip/keybinder/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for the keybinder library
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--enable-python

PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

INSTALL_DIRS=	python-keybinder

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
