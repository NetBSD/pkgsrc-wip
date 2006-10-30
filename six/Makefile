# $NetBSD: Makefile,v 1.3 2006/10/30 22:45:31 shattered Exp $

MASTER_SITES=	http://six.retes.hu/download/
DISTNAME=	six-0.5.2
CATEGORIES=	games

COMMENT=	Six is a Hex playing program for Linux/Un*x systems running KDE
HOMEPAGE=	http://six.retes.hu/
SUBDIR+=	six
MAINTAINER=	gizm0@inbox.lv

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFIGURE_ARGS+=	--disable-setgid

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
