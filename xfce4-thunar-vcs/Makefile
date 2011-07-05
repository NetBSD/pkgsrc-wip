# $NetBSD: Makefile,v 1.1.1.1 2011/07/05 20:38:01 guigui2 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	thunar-vcs-plugin-0.1.4
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.xfce.org/archive/src/thunar-plugins/thunar-vcs-plugin/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/thunar-plugins/thunar-vcs-plugin
COMMENT=	Thunar vcs integration plugin

#DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../wip/xfce4-thunar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
