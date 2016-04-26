# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kfilemetadata-${KF5VER}
PKGNAME=	${DISTNAME:S/-/5-/}
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Library for extracting file metadata
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	msgmerge pkg-config

.include "../../lang/python/tool.mk"
.include "../../wip/karchive/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
