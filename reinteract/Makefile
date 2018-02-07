# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	reinteract-0.5.10
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://download.reinteract.org/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.reinteract.org/
COMMENT=	Reinteract is a system for interactive experimentation with Python
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

GNU_CONFIGURE=	yes

REPLACE_PYTHON+=		bin/reinteract.in
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
