# $NetBSD: Makefile,v 1.2 2007/12/22 18:41:16 mwdavies Exp $

DISTNAME=	qimageblitz-${BLITZ_SNAP_VERSION}
CATEGORIES=	x11
COMMENT=	XXX for the KDE 4 integrated X11 desktop
MASTER_SITES=   #empty

USE_TOOLS+= date
USE_LANGUAGES+= c c++
USE_CMAKE= yes

SVN_REPOSITORIES=       qimageblitz
SVN_TAG=                {${BLITZ_TAG}}
SVN_ROOT.qimageblitz=    svn://anonsvn.kde.org/home/kde/trunk/kdesupport/qimageblitz/
SVN_MODULE.qimageblitz=  qimageblitz

.include "../../mk/bsd.prefs.mk"
.include "../../wip/mk/svn-package.mk"

WRKSRC=                 ${WRKDIR}/${PKGBASE}

YESTERDAY!=             expr `date +%s` - 86399
BLITZ_TAG!=             ${DATE} +%Y%m%d
BLITZ_SNAP_VERSION!=            ${DATE} -r ${YESTERDAY} +%Y%m%d

BUILD_MAKE_FLAGS+= VERBOSE=1

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/


.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
