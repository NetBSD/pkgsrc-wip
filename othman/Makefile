# $NetBSD: Makefile,v 1.5 2014/01/25 10:38:14 thomasklausner Exp $

VERS=		0.2.5
DISTNAME=	othman-${VERS}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://git.ojuba.org/cgit/othman/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://othman.ojuba.org/
COMMENT=	Electronic Quran browser

USE_PKGLOCALEDIR= yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2

.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
