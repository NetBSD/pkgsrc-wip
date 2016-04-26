# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kwallet-${KF5VER}
CATEGORIES=	security

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Secure and unified container for user passwords
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../wip/kdoctools

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../wip/gpgmepp/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/kiconthemes/buildlink3.mk"
.include "../../wip/knotifications/buildlink3.mk"
.include "../../wip/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
