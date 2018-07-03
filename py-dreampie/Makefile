# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:41 thomasklausner Exp $

DISTNAME=	dreampie-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/dreampie/trunk/1.1/+download/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://dreampie.sourceforge.net/
COMMENT=	Advanced graphical interactive Python shell
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gobject, py-gtksourceview

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gtksourceview/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
