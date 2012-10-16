# $NetBSD: Makefile,v 1.7 2012/10/16 18:02:41 jihbed Exp $
#

DISTNAME=	reinteract-0.5.10
PKGREVISION=	1
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

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
