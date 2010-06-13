# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:12 thomasklausner Exp $
#

VERS=	0.2.0
DISTNAME=	othman-master
PKGNAME=	${DISTNAME:S/-master//}-${VERS}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://git.ojuba.org/cgit/othman/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://othman.ojuba.org/
COMMENT=	Electronic Quran browser
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-sqlite-[0-9]*:../../databases/py-sqlite3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR= yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
