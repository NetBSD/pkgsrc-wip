# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	plasma-widget-menubar-0.2.0
CATEGORIES=	x11

COMMENT=	Kde application menubar plasmoid
HOMEPAGE=	https://launchpad.net/plasma-widget-menubar
LICENSE=	gnu-gpl-v3
MAINTAINER=	nathanialsloss@yahoo.com.au

MASTER_SITES=	-https://launchpad.net/plasma-widget-menubar/trunk/0.2.0/+download/plasma-widget-menubar-0.2.0.tar.bz2
EXTRACT_SUFX=	.tar.bz2

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl
.include "../../devel/qjson/buildlink3.mk"
.include "../../devel/libdbusmenu-qt/buildlink3.mk"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
