# $NetBSD: Makefile,v 1.2 2010/05/13 08:12:51 jihbed Exp $
#

DISTNAME=	gwsmhg-0.8.1
CATEGORIES=	devel python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/gwsmhg/gwsmhg/v-0.8.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwsmhg.sourceforge.net/
COMMENT=	Mercurial PyGtk GUI client
LICENSE=	gnu-gpl-v2

DEPENDS+=	mercurial>=1.3.1:../../devel/mercurial
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.18.0:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-cairo>=1.8.6:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-gtksourceview>=2.6.0:../../x11/gtksourceview
DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.99.12:../../x11/py-gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
