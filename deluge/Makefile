# $NetBSD$

DISTNAME=	deluge-1.3.15
CATEGORIES=	net
MASTER_SITES=	http://download.deluge-torrent.org/source/
EXTRACT_SUFX=	.tar.xz
PKGREVISION=	3

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://download.deluge-torrent.org/source/
COMMENT=	Lightweight, free software, cross-platform BitTorrent client
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-xdg:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-gtk2:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-twisted:../../net/py-twisted

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
