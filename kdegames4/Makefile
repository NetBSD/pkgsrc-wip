# $NetBSD: Makefile,v 1.9 2011/05/13 23:25:15 mwdavies Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../wip/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_PERL+=	katomic/katomic-levelset-upd.pl
REPLACE_PERL+=	klickety/klickety-2.0-inherit-ksame-highscore.pl

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

REPLACE_PYTHON+=	kajongg/setup.py
REPLACE_PYTHON+=	kajongg/src/deferredutil.py
REPLACE_PYTHON+=	kajongg/src/kajongg.py
REPLACE_PYTHON+=	kajongg/src/kajonggserver.py
REPLACE_PYTHON+=	kajongg/src/scoringtest.py
REPLACE_PYTHON+=	kajongg/src/server.py

.include "../../wip/kde4/kde4.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/application.mk"
# don't add python include dir to include path
# as eg kolf will pick up wrong versions of header files
BUILDLINK_INCDIRS.${PYPACKAGE}=
.include "../../games/ggz-client-libs/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.include "../../wip/kdebase-runtime4/buildlink3.mk"
.include "../../wip/kdebindings4-python/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
