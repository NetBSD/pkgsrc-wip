# $NetBSD: Makefile,v 1.5 2013/09/09 14:05:32 thomasklausner Exp $

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	thunar-vcs-plugin-0.1.4
PKGNAME=	xfce4-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://archive.xfce.org/src/thunar-plugins/thunar-vcs-plugin/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/thunar-plugins/thunar-vcs-plugin
COMMENT=	Thunar vcs integration plugin

#DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../wip/xfce4-thunar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
