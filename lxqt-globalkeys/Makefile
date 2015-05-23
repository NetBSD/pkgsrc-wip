# $NetBSD: Makefile,v 1.3 2015/05/23 17:47:33 krytarowski Exp $

DISTNAME=	lxqt-globalkeys-0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Daemon and library for global keyboard shortcuts registration
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DLXQT_ETC_XDG_DIR=${PREFIX}/xdg

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
