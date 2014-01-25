# $NetBSD: Makefile,v 1.9 2014/01/25 10:38:25 thomasklausner Exp $

DISTNAME=	reinteract-0.5.10
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://download.reinteract.org/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.reinteract.org/
COMMENT=	Reinteract is a system for interactive experimentation with Python
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

REPLACE_PYTHON+=	bin/reinteract.in
PY_PATCHPLIST=	yes
PYTHON_VERSIONED_DEPENDENCIES=	cairo

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
