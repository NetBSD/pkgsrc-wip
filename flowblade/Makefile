# $NetBSD$

DISTNAME=	flowblade-2.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=jliljebl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jliljebl.github.io/flowblade/
COMMENT=	Multitrack non-linear video editor
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-mlt-[0-9]*:../../wip/py-mlt
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus

WRKSRC=		${WRKDIR}/flowblade-${PKGVERSION_NOREV}/flowblade-trunk

FLOWBLADE_PATH=	${PREFIX}/${PYSITELIB}/Flowblade

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Setting the man page path.
SUBST_FILES.man+=	setup.py
SUBST_VARS.man=		PKGMANDIR

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Setting FLOWBLADE_PATH.
SUBST_FILES.py+=	flowblade
SUBST_VARS.py=		FLOWBLADE_PATH

# https://github.com/jliljebl/flowblade/issues/597
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/distutils.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../wip/mlt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
