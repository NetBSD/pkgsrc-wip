# $NetBSD: Makefile,v 1.30 2013/09/08 22:31:24 makoto Exp $

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

SUBST_CLASSES+=		rpathapp
SUBST_STAGE.rpathapp=	post-build
SUBST_FILES.rpathapp=	apps/cmake_install.cmake
SUBST_MESSAGE.rpathapp=	(modular only) Fix RPATH for apps/cmake_install.cmake
SUBST_SED.rpathapp=	-e '/OLD_RPATH/s,:::::::::::::::::::::::::::::::::::::::,,'
SUBST_SED.rpathapp+=	-e '/NEW_RPATH/s,:${PREFIX}/lib,,'

SUBST_CLASSES+=		rpathsrc
SUBST_STAGE.rpathsrc=	post-build
SUBST_FILES.rpathsrc=	src/cmake_install.cmake
SUBST_MESSAGE.rpathsrc=	(modular only) Fix RPATH for src/cmake_install.cmake
SUBST_SED.rpathsrc=	-e '/OLD_RPATH/s,::::::::::::,,'
SUBST_SED.rpathsrc+=	-e '/NEW_RPATH/s,:${PREFIX}/lib,,'

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
