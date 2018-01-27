# $NetBSD: Makefile,v 1.22 2016/04/11 19:02:00 ryoon Exp $

DISTNAME=	breeze-${PLASMAVER}
PKGNAME=	${DISTNAME:S/-/-kde4-/}
CATEGORIES=	graphics

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Breeze widget style for KDE4 applications
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

.include "../../wip/kde5/plasma.mk"

DISTINFO_FILE=	${.CURDIR}/../../wip/breeze/distinfo

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	pkg-config perl

CMAKE_ARGS+=	-DDATA_INSTALL_DIR=${PREFIX}/share/kde/apps
CMAKE_ARGS+=	-DUSE_KDE4=ON

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
