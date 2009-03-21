# $NetBSD: Makefile,v 1.8 2009/03/21 14:58:52 jihbed Exp $
#

DISTNAME=	EditObj-0.5.7
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/songwrite/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.gna.org/oomadness/en/editobj/index.html
COMMENT=	EditObj is a dialog box generator for Python objects

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none


PY_PATCHPLIST=          yes
PYDISTUTILSPKG=         yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
