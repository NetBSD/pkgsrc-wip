# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:21 thomasklausner Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.0

DISTNAME=	xfce4-radio-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-radio-plugin/
EXTRACT_SUFX=	.tar.gz
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Xfce V4L radio plugin

ONLY_FOR_PLATFORM=	Linux-*-*	# V4L

BROKEN=		Must fix the PLIST first

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
