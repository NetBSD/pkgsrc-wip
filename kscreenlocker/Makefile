# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kscreenlocker-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Library and components for secure lock screen architecture
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config perl:run

REPLACE_PERL+=	updaters/ksreenlocker_5_3_separate_autologin.pl

SPECIAL_PERMS+=	${PREFIX}/libexec/kcheckpass \
		${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4555

.include "../../mk/pam.buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/kwayland/buildlink3.mk"
.include "../../wip/layer-shell-qt/buildlink3.mk"
.include "../../x11/libkscreen/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
