# $NetBSD: Makefile,v 1.2 2011/07/04 19:28:09 guigui2 Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	thunar-archive-plugin-0.3.0
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	http://archive.xfce.org/src/thunar-plugins/thunar-archive-plugin/0.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/thunar-plugins/thunar-archive-plugin/
COMMENT=	Thunar archive plugin

DEPENDS=	file-roller:../../archivers/file-roller

.include "../../wip/xfce4-thunar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
