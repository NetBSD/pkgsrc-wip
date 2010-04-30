# $NetBSD: Makefile,v 1.6 2010/04/30 08:13:03 thomasklausner Exp $
#

DISTNAME=	99561-filelight-1.9rc3
PKGNAME=	filelight-1.9rc3
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.methylblue.com/filelight/
COMMENT=	Graphical filesystem usage monitor
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
