# $NetBSD: Makefile,v 1.27 2013/09/03 03:37:58 makoto Exp $

DISTNAME=		tqsl-2.0
PKGNAME=		${DISTNAME}rc3
CATEGORIES=		ham
MASTER_SITES=		http://www.arrl.org/files/file/LoTW%20Instructions/
MASTER_SITES=		http://downloads.sourceforge.net/project/trustedqsl/TrustedQSL/v2.0-rc3/

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://sourceforge.net/projects/trustedqsl/
COMMENT=		TrustedQSL, uploading QSL Data to LoTW of ARRL
#LICENSE=		See LICENSE file (ARRL)

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_TOOLS+=		perl gmake cmake
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_CMAKE=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}

#.if !empty(X11_TYPE:Mmodular)
SUBST_CLASSES+=		x11r7
SUBST_STAGE.x11r7=	post-build
SUBST_FILES.x11r7=	apps/cmake_install.cmake
SUBST_MESSAGE.x11r7=	Remove X11R7/lib from RPATH_CHANGE, for modular only
SUBST_SED.x11r7=	-e 's,:/usr/X11R7/lib,,'
#.endif

## CMAKE RPATH_CHANGE claims the the order is not the same, so the work around.
##              /usr/pkgsrc/wip/trustedQSL/work/tqsl-114/src:/usr/pkg/lib:
##                     v
## /usr/pkg/lib:/usr/pkgsrc/wip/trustedQSL/work/tqsl-114/src

SUBST_CLASSES+=		swaprpath
SUBST_STAGE.swaprpath=	post-build
SUBST_FILES.swaprpath=	apps/cmake_install.cmake
SUBST_MESSAGE.swaprpath= Swap SRC and LIB of OLD_RPATH in RPATH_CHANGE
SUBST_SED.swaprpath=	-e '/OLD_RPATH/s,${WRKSRC}/src:${PREFIX}/lib:',${PREFIX}/lib:${WRKSRC}/src,


SUBST_CLASSES+=		rpath-link
SUBST_STAGE.rpath-link= post-build
SUBST_FILES.rpath-link=	src/cmake_install.cmake
SUBST_MESSAGE.rpath-link=	Truely experimental and interim fix for RPATH-LINK
SUBST_SED.rpath-link=	-e '/OLD_RPATH/s,::::::::::::,,'
SUBST_SED.rpath-link+=	-e '/NEW_RPATH/s,:${PREFIX}/lib,,'

#SUBST_CLASSES+=		lastcolon
#SUBST_STAGE.lastcolon=	post-build
#SUBST_FILES.lastcolon=	apps/cmake_install.cmake
#SUBST_MESSAGE.lastcolon=	Removing the very last colon from OLD_RPATH in RPATH_CHANGE
#SUBST_SED.lastcolon=	-e '/OLD_RPATH/s,${WRKSRC}/src:,${WRKSRC}/src,'

# There is an unresolved build failure, where -R for /usr/pkg/lib does
# not precede /usr/X11R7/lib, and on a netbsd-5 system with base xorg,
# an old version of pixman is found by the pkgsrc cairo.  The root
# cause (aside from having two pixman versions installed) is ad hoc -L
# usage in Makefile.am, without matching -R.

do-configure:
	(cd $(WRKSRC) ; \
	cmake \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DBDB_PREFIX=${PREFIX} \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib \
	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=yes \
	.)

.include "../../textproc/expat/buildlink3.mk"
.include "../../databases/db5/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
