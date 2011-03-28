# $NetBSD: Makefile,v 1.6 2011/03/28 22:27:01 crocusino Exp $
#

DISTNAME=	termit-2.7.1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/downloads/nonstop/termit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://wiki.github.com/nonstop/termit
COMMENT=	Simple vte-based terminal with tabs and encoding switching
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_CMAKE=	yes

# fetch from https - fails with ftp
# curl still fails for pkgsrc-2010Q4,
# but for newer mk/fetch/fetch.mk, curl works fine
FETCH_USING=	curl

# fix the MANPATH
# cannot use patch as ${PKGMANDIR} is not expanded in CMakeLists.txt
SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		doc/CMakeLists.txt
SUBST_SED.fix-paths=		-e 's,/share/man,/${PKGMANDIR},g'

.include "../../x11/vte/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
