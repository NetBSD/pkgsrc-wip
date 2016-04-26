# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kio-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://projects.kde.org/projects/frameworks/kio
COMMENT=	Resource and network access abstraction
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

#BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../wip/kdoctools

USE_TOOLS+=	msgmerge

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kio/accept-languages.codes \
		${PKG_SYSCONFDIR}/xdg/accept-languages.codes
CONF_FILES+=	${PREFIX}/share/examples/kio/kshorturifilterrc \
		${PKG_SYSCONFDIR}/xdg/kshorturifilterrc

# generation of kcookieserver.moc fails when ${PREFIX}/include in the moc include path
SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/ioslaves/http/kcookiejar/CMakeFiles/kded_kcookiejar_automoc.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

#.include "../../lang/python/tool.mk"
#.include "../../wip/gpgmepp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/karchive/buildlink3.mk"
.include "../../wip/kbookmarks/buildlink3.mk"
.include "../../wip/kdoctools/buildlink3.mk"
.include "../../wip/kjobwidgets/buildlink3.mk"
.include "../../wip/kwallet/buildlink3.mk"
.include "../../wip/solid/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
