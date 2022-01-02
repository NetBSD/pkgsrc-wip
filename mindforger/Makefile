# $NetBSD$

DISTNAME=	mindforger_1.52.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=dvorka/mindforger/releases/download/1.52.0/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://www.mindforger.com/
COMMENT=	Thinking notebook and Markdown editor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
ICON_THEMES=	yes

PKGCONFIG_OVERRIDE+=	deps/cmark-gfm/src/libcmark-gfm.pc.in

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

pre-build:
	cd ${WRKSRC} && PREFIX=${PREFIX} ${BUILDLINK_DIR}/bin/qmake -r CONFIG+=mfnoccache mindforger.pro

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
