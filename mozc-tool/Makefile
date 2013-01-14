# $NetBSD: Makefile,v 1.1 2013/01/14 06:25:23 ryo-on Exp $
#

DISTNAME=	mozc-1.6.1187.102
PKGNAME=	${DISTNAME:S/mozc-/mozc-tool-/}

INSTALLATION_DIRS+=	libexec

.include "../../x11/qt4-libs/buildlink3.mk"

ALL_ENV+=	qt_dir=${QTDIR}

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c Release -j ${MAKE_JOBS} \
			gui/gui.gyp:mozc_tool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_linux/Release/mozc_tool \
		${DESTDIR}${PREFIX}/libexec

.include "../../wip/ibus-mozc/Makefile.common"
