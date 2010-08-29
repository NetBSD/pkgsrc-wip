# $NetBSD: Makefile,v 1.1.1.1 2010/08/29 14:13:36 cheusov Exp $
#

DISTNAME=	dikt-2d
CATEGORIES=	textproc x11
MASTER_SITES=	http://dikt.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://dikt.googlecode.com/
COMMENT=	Dictionary for KDE
LICENSE=	modified-bsd

BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
