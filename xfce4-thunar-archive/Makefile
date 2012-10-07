# $NetBSD: Makefile,v 1.3 2012/10/07 20:11:09 asau Exp $
#

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
