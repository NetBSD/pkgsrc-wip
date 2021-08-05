# $NetBSD: Makefile,v 1.99 2021/05/24 19:49:59 wiz Exp $
#

DISTNAME=	kdevelop-5.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=kdevelop/5.6.2/src/}

HOMEPAGE=	https://www.kdevelop.org/
COMMENT=	Integrated Development Environment for Unix/X11/KDE
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	gmake gtar pkg-config #perl msgfmt

REPLACE_BASH+=	kdevplatform/util/kdevplatform_shell_environment.sh

CHECK_INTERPRETER_SKIP=	share/kdevplatform/shellutils/.zshrc

pre-configure:
	ln -s ${TOOLS_DIR}/bin/gtar ${TOOLS_DIR}/bin/tar

.include "../../devel/grantlee-qt5/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kitemmodels/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../devel/libkomparediff2/buildlink3.mk"
.include "../../devel/purpose/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../wip/okteta/buildlink3.mk"
.include "../../wip/libksysguard/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
