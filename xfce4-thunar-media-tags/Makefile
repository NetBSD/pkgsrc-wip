# $NetBSD: Makefile,v 1.2 2012/02/19 17:30:42 guigui2 Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	thunar-media-tags-plugin-0.2.0
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	http://archive.xfce.org/src/thunar-plugins/thunar-media-tags-plugin/0.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/thunar-plugins/thunar-media-tags-plugin/
COMMENT=	Thunar media tags plugin

# url2pkg-marker (please do not remove this line.)
.include "../../audio/taglib/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../wip/xfce4-thunar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
