# $NetBSD: Makefile,v 1.4 2012/10/03 18:15:32 asau Exp $
#

DISTNAME=	noor-1.2.1
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=noor/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://noor.sourceforge.net/
COMMENT=	Quran viewer
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PYDISTUTILSPKG=	yes

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
