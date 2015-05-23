# $NetBSD: Makefile,v 1.3 2015/05/23 17:47:33 krytarowski Exp $

DISTNAME=	lxqt-common-0.9.1
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Common data file required for running an lxde-qt session
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=	xdg
SUBST_FILES.xdg=	autostart/CMakeLists.txt
SUBST_SED.xdg=		-e 's,/etc/xdg/autostart,${PREFIX}/etc/xdg/autostart,'
SUBST_STAGE.xdg=	post-patch

CMAKE_ARGS+=	-DLXQT_ETC_XDG_DIR=${PREFIX}/etc/xdg

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
