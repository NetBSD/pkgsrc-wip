# $NetBSD: Makefile,v 1.10 2010/06/01 21:10:06 mwdavies Exp $
#

DISTNAME=	koffice-2.2.0
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-2.2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE4 office suite

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	pstoedit>=3.0:../../graphics/pstoedit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/mysql51-client/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
