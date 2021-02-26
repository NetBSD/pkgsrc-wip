# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	libkgapi-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE-based library to access various Google services via their public API
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

#USE_TOOLS+=	msgmerge

#SUBST_CLASSES+=		fix-moc
#SUBST_STAGE.fix-moc=	post-configure
#SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
#SUBST_FILES.fix-moc=	_KDE_build/runner/CMakeFiles/*_autogen.dir/AutogenInfo.json
#SUBST_NOOP_OK.fix-moc=	yes
#SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/kcmutils/buildlink3.mk"
#.include "../../devel/krunner/buildlink3.mk"
#.include "../../wip/akonadi-mime/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../misc/kcontacts/buildlink3.mk"
#.include "../../textproc/xapian/buildlink3.mk"
# really should be qtwebengine
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
