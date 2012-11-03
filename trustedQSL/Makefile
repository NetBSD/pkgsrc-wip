# $NetBSD: Makefile,v 1.8 2012/11/03 23:28:59 lexort Exp $

DISTNAME=		TrustedQSL-1_13
PKGNAME=		TrustedQSL-1.13
PKGREVISION=		1
CATEGORIES=		ham
MASTER_SITES=		http://www.arrl.org/files/file/LoTW%20Instructions/
EXTRACT_SUFX=		_tar.gz

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://www.arrl.org/files/file/LoTW%20Instructions/
COMMENT=		Uploading QSL Data to LoTW of ARRL
#LICENSE=		See LICENSE file (ARRL)

USE_TOOLS+=		perl gmake
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tqsllib=${PREFIX}/lib
# looking for bin/wx-config under it.
CONFIGURE_ARGS+=	--with-wxwindows=${PREFIX}
# The configure script is broken and looks in explicit paths, instead
# of just trying to link.
CONFIGURE_ARGS+=	--with-expat=${PREFIX}

SUBST_CLASSES+=		wxGTK
SUBST_STAGE.wxGTK=	post-patch
SUBST_FILES.wxGTK=	configure
SUBST_MESSAGE.wxGTK=	Adjust wxGTK path
SUBST_SED.wxGTK=	-e s\|@@PREFIX@@\|${PREFIX}\|

# There is an unresolved build failure, where -R for /usr/pkg/lib does
# not precede /usr/X11R7/lib, and on a netbsd-5 system with base xorg,
# an old version of pixman is found by the pkgsrc cairo.  The root
# cause (aside from having two pixman versions installed) is ad hoc -L
# usage in Makefile.am, without matching -R.

.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../wip/tqsllib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
