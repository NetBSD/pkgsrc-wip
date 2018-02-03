# $NetBSD: Makefile,v 1.69 2017/12/08 08:52:58 maya Exp $

DISTNAME=	ffmpegthumbs-${KAPPSVER}
CATEGORIES=	multimedia

HOMEPAGE=	https://kde.org/applications/multimedia/
COMMENT=	FFmpeg-based thumbnail creator for video files
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../wip/kde5/applications.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/kio/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
