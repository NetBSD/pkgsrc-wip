# $NetBSD: Makefile,v 1.3 2010/04/11 16:03:45 crocusino Exp $
#

DISTNAME=	termit-2.4.0
CATEGORIES=	x11
MASTER_SITES=	http://github.com/downloads/nonstop/termit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://wiki.github.com/nonstop/termit
COMMENT=	Simple vte-based terminal with tabs and encoding switching
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=  c c++
USE_TOOLS+=     gmake
USE_CMAKE=      yes

# fix the MANPATH
SUBST_CLASSES+=             fix-paths
SUBST_STAGE.fix-paths=      pre-configure
SUBST_MESSAGE.fix-paths=    Fixing absolute paths.
SUBST_FILES.fix-paths=      doc/CMakeLists.txt
SUBST_SED.fix-paths=        -e 's,/share/man,/${PKGMANDIR},g'

.include "../../x11/vte/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
