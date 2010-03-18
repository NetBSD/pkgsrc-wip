# $NetBSD: Makefile,v 1.2 2010/03/18 00:06:01 crocusino Exp $
#

DISTNAME=	termit-2.3.0
CATEGORIES=	x11
MASTER_SITES=	http://termit.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://code.google.com/p/termit
COMMENT=	Simple vte-based terminal with tabs and encoding switching
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_CMAKE=	yes

# fix the MANPATH
SUBST_CLASSES+=		    fix-paths
SUBST_STAGE.fix-paths=	    pre-configure
SUBST_MESSAGE.fix-paths=    Fixing absolute paths.
SUBST_FILES.fix-paths=	    doc/CMakeLists.txt
SUBST_SED.fix-paths=	    -e 's,/share/man,/${PKGMANDIR},g'

# fix the version
SUBST_CLASSES+=		    fix-version
SUBST_STAGE.fix-version=    pre-configure
SUBST_MESSAGE.fix-version=  Fixing version number.
SUBST_FILES.fix-version=    CMakeLists.txt
SUBST_SED.fix-version=	    -e 's/2\.2\.0/2.3.0/g'


.include "../../x11/vte/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
