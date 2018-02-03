# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	khelpcenter-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	http://kde.org/applications/utilities/kcalc/
COMMENT=	Application to show KDE Applications' documentation
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kinit>=5.21.0:../../x11/kinit

USE_TOOLS+=	msgmerge pkg-config perl:run

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

REPLACE_PERL+=	searchhandlers/khc_mansearch.pl

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/khelpcenter.categories \
		${PKG_SYSCONFDIR}/xdg/khelpcenter.categories

.include "../../devel/grantlee-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/kdoctools/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
