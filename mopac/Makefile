# $NetBSD: Makefile,v 1.8 2004/12/02 16:39:03 thomasklausner Exp $
#
#

DISTNAME=	mopac7
PKGNAME=	mopac-7.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ccl.net/pub/chemistry/software/SOURCES/FORTRAN/mopac7_sources/
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mopac7-man.tar.Z

PATCH_SITES=	ftp://infomeister.osc.edu/pub/chemistry/software/LINUX/mopac7/old-version-95.06.21/
PATCHFILES=	mopac7-linux.diff.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://server.ccl.net/cca/software/LINUX/mopac7/index.shtml
COMMENT=	Molecular energy calculation program

WRKSRC=			${WRKDIR}/mopac7
BUILD_TARGET=		MOPAC7
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_FORTRAN=		yes
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
