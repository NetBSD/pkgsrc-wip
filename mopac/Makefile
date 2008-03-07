# $NetBSD: Makefile,v 1.17 2008/03/07 21:26:31 asau Exp $
#

DISTNAME=		mopac7
PKGNAME=		mopac-7.0
CATEGORIES=		biology math
MASTER_SITES=		http://server.ccl.net/cca/software/LINUX/mopac7/
EXTRACT_SUFX=		.tar.Z
DISTFILES=		${DEFAULT_DISTFILES} mopac7-man.tar.gz

PATCH_SITES=		${MASTER_SITES:=old-version-95.06.21/}
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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mopac7/sample
	cd ${WRKSRC} && ${PAX} -wr test_* \
	  ${DESTDIR}${PREFIX}/share/mopac7/sample
	cd ${WRKDIR} && ${PAX} -wr mopac7-man ${DESTDIR}${PREFIX}/share/mopac7

# "g77" can not be used for external function

.include "../../lang/f2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
