# $NetBSD: Makefile,v 1.4 2012/11/23 22:44:44 othyro Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.0

DISTNAME=	xfce4-radio-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-radio-plugin/
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Xfce V4L radio plugin

ONLY_FOR_PLATFORM=	Linux-*-*	# V4L

BROKEN=		Must fix the PLIST first

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
