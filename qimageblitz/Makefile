# $NetBSD: Makefile,v 1.5 2008/10/05 10:08:21 mwdavies Exp $

DISTNAME=	qimageblitz-0.0.4
CATEGORIES=	graphics
COMMENT=	interm graphical effect and filter library for KDE4.0
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qimageblitz/}
EXTRACT_SUFX=	.tar.bz2

USE_TOOLS+= date
USE_LANGUAGES+= c c++
USE_CMAKE= yes

#SVN_REPOSITORIES=       qimageblitz
#SVN_TAG=                {${BLITZ_TAG}}
#SVN_ROOT.qimageblitz=    svn://anonsvn.kde.org/home/kde/trunk/kdesupport/qimageblitz/
#SVN_MODULE.qimageblitz=  qimageblitz

.include "../../mk/bsd.prefs.mk"
#.include "../../wip/mk/svn-package.mk"

#WRKSRC=                 ${WRKDIR}/${PKGBASE}

#YESTERDAY!=             expr `date +%s` - 86399
#BLITZ_TAG!=             ${DATE} +%Y%m%d
#BLITZ_SNAP_VERSION!=            ${DATE} -r ${YESTERDAY} +%Y%m%d

#BUILD_MAKE_FLAGS+= VERBOSE=1

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/


.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
