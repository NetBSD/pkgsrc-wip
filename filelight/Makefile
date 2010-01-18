# $NetBSD: Makefile,v 1.4 2010/01/18 09:38:20 thomasklausner Exp $
#

DISTNAME=	99561-filelight-1.9rc3
PKGNAME=	filelight-1.9rc3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.methylblue.com/filelight/
COMMENT=	Graphical filesystem usage monitor
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME}

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
