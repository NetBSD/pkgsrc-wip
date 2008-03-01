# $NetBSD: Makefile,v 1.12 2008/03/01 14:13:17 hoka_adam Exp $
#
#

DISTNAME=		mopac7
PKGNAME=		mopac-7.0
CATEGORIES=		biology
MASTER_SITES=		http://server.ccl.net/cca/software/LINUX/mopac7/
EXTRACT_SUFX=		.tar.Z
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} mopac7-man.tar.gz

PATCH_SITES=		http://server.ccl.net/cca/software/LINUX/mopac7/old-version-95.06.21/
PATCHFILES=		mopac7-linux.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		oishi@ims.ac.jp
HOMEPAGE=		http://server.ccl.net/cca/software/LINUX/mopac7/index.shtml
COMMENT=		Molecular energy calculation program

WRKSRC=			${WRKDIR}/mopac7
BUILD_TARGET=		MOPAC7
USE_TOOLS+=		gmake
USE_LANGUAGES=		fortran
PKG_FC?=		f2c-f77

post-patch:
	${CP} ${WRKSRC}/esp.rof ${WRKSRC}/esp.f
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/mopac7/sample
	${CP} ${WRKSRC}/test_* ${PREFIX}/share/mopac7/sample
	${CP} -pR ${WRKDIR}/mopac7-man ${PREFIX}/share/mopac7

# "g77" can not be used for external function

.include "../../lang/f2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
