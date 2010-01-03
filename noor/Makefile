# $NetBSD: Makefile,v 1.1.1.1 2010/01/03 22:18:50 jihbed Exp $
#

DISTNAME=	noor-1.2.1
CATEGORIES=	misc python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/noor/noor/1.2.1/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://noor.sourceforge.net/
COMMENT=	Quran viewer
#LICENSE=	# TODO: (see mk/license.mk)


PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PYDISTUTILSPKG=	yes

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
