# $NetBSD: Makefile,v 1.11 2013/04/25 02:36:49 makoto Exp $

DISTNAME=		TrustedQSL-1_14
DISTNAME=		tqsl-114
# 1.14 instead of 114 may be better (?)
PKGNAME=		${DISTNAME:C/[0-9]/&./}
CATEGORIES=		ham
MASTER_SITES=		http://www.arrl.org/files/file/LoTW%20Instructions/
MASTER_SITES=		http://www.arrl.org/files/file/TrustedQSL-Beta/
EXTRACT_SUFX=		.tgz

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://www.arrl.org/files/file/LoTW%20Instructions/
HOMEPAGE=		http://www.arrl.org/trustedqsl-beta-release
HOMEPAGE=		http://sourceforge.net/projects/trustedqsl/
COMMENT=		TrustedQSL, uploading QSL Data to LoTW of ARRL
#LICENSE=		See LICENSE file (ARRL)

USE_TOOLS+=		perl gmake cmake
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	cmakemodules/FindBDB.cmake
SUBST_FILES.prefix+=	cmakemodules/FindCURL.cmake
SUBST_MESSAGE.prefix=	Adjust CMake Find Berkley DB and CURL PREFIX
SUBST_SED.prefix=	-e s\|@@PREFIX@@\|${PREFIX}\|

# There is an unresolved build failure, where -R for /usr/pkg/lib does
# not precede /usr/X11R7/lib, and on a netbsd-5 system with base xorg,
# an old version of pixman is found by the pkgsrc cairo.  The root
# cause (aside from having two pixman versions installed) is ad hoc -L
# usage in Makefile.am, without matching -R.

do-configure:
	(cd $(WRKSRC) ; cmake .)

.include "../../textproc/expat/buildlink3.mk"
.include "../../databases/db5/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../wip/tqsllib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
