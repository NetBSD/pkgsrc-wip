# $NetBSD: Makefile,v 1.3 2009/11/11 11:27:09 mwdavies Exp $
#

DISTNAME=	koffice-2.0.91
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=../unstable/koffice-2.0.91/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE4 office suite

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

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
