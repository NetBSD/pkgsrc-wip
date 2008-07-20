# $NetBSD: Makefile,v 1.4 2008/07/20 23:15:42 absd Exp $

DISTNAME=	qimageblitz-${BLITZ_SNAP_VERSION}
CATEGORIES=	x11
COMMENT=	XXX for the KDE 4 integrated X11 desktop
MASTER_SITES=	#empty

USE_TOOLS+= date
USE_LANGUAGES+= c c++
USE_CMAKE= yes

SVN_REPOSITORIES=	qimageblitz
SVN_TAG=		{${BLITZ_TAG}}
SVN_ROOT.qimageblitz=    svn://anonsvn.kde.org/home/kde/trunk/kdesupport/qimageblitz/
SVN_MODULE.qimageblitz=  qimageblitz

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "../../wip/mk/svn-package.mk"

WRKSRC=			${WRKDIR}/${PKGBASE}

YESTERDAY!=		expr `date +%s` - 86399
BLITZ_TAG!=		${DATE} +%Y%m%d
BLITZ_SNAP_VERSION!=		${DATE} -r ${YESTERDAY} +%Y%m%d

BUILD_MAKE_FLAGS+= VERBOSE=1

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
