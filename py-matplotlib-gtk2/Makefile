# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:14 thomasklausner Exp $
#

DISTNAME=		matplotlib-0.98.0
PKGNAME=		${PYPKGPREFIX}-matplotlib-gtk-0.98.0
PKGREVISION=		1
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		GTK frontend for matplotlib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../wip/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/py-numpy/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
