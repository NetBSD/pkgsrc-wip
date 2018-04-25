# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	akonadi-contacts-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries and daemons to implement basic email handling
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

#BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_FILES.xdg+=	src/contact-editor/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/akonadi-contacts.categories \
		${PKG_SYSCONFDIR}/xdg/akonadi-contacts.categories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/akonadi-contacts.renamecategories \
		${PKG_SYSCONFDIR}/xdg/akonadi-contacts.renamecategories
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/contact-editor.categories \
		${PKG_SYSCONFDIR}/xdg/contact-editor.categories

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/akonadi-contacts/plugins/CMakeFiles/categorieseditwidgetplugin_autogen.dir/AutogenInfo.cmake
SUBST_FILES.fix-moc+=	_KDE_build/kcm/CMakeFiles/kcm_akonadicontact_actions_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/akonadi-mime/buildlink3.mk"
.include "../../wip/kcontacts/buildlink3.mk"
.include "../../wip/kmime/buildlink3.mk"
.include "../../graphics/prison/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
