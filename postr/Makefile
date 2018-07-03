# $NetBSD: Makefile,v 1.7 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	postr-0.12.4
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/postr/0.12/
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://projects.gnome.org/postr/
COMMENT=	GNOME flickr uploader

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gobject, py-elementtree

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
