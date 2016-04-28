# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kdesu-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Integration with su for elevated privileges
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

SPECIAL_PERMS+=	${PREFIX}/libexec/kf5/kdesud ${REAL_ROOT_USER} nogroup 2555

.include "../../wip/kpty/buildlink3.mk"
.include "../../wip/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
