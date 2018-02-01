# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	akonadi-search-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries and daemons to implement searching in Akonadi
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../wip/kde5/applications.mk"

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/akonadi-search.categories \
		${PKG_SYSCONFDIR}/xdg/akonadi-search.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/akonadi-search.renamecategories \
		${PKG_SYSCONFDIR}/xdg/akonadi-search.renamecategories

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/runner/CMakeFiles/krunner_pimcontacts_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../wip/akonadi-mime/buildlink3.mk"
.include "../../wip/kcalcore/buildlink3.mk"
.include "../../wip/kcontacts/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
