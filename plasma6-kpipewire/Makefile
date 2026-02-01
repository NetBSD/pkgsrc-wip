# $NetBSD: Makefile,v 1.48 2025/10/23 20:37:48 wiz Exp $

DISTNAME=	kpipewire-${PLASMAVER}
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Components relating to pipewire use in Plasma
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../wip/pipewire/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
