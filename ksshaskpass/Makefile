# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	ksshaskpass-${PLASMAVER}
CATEGORIES=	security

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	ssh-add helper that uses kwallet and kpassworddialog
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../security/kwallet/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
