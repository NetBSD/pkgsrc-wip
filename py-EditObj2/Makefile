# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:14 thomasklausner Exp $
#

DISTNAME=	EditObj2-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://download.gna.org/songwrite/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://home.gna.org/oomadness/en/editobj/index.html
COMMENT=	EditObj2 is a dialog box generator for Python objects
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT= 	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=         yes

PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
