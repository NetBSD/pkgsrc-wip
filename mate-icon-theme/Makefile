# $NetBSD: Makefile,v 1.2 2015/02/20 11:57:20 obache Exp $

DISTNAME=	mate-icon-theme-1.8.0
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Collection of icons used as the basis for MATE themes
LICENSE=	gnu-lgpl-v3 OR cc-by-sa-v3.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
