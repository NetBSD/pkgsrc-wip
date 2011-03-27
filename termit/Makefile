# $NetBSD: Makefile,v 1.5 2011/03/27 15:20:16 crocusino Exp $
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
# TODO - how to set properly so that pkglint is content?
FETCH_USING=	custom
FETCH_CMD=	wget
FETCH_BEFORE_ARGS=	--no-check-certificate

# fix the MANPATH
# cannot use patch as ${PKGMANDIR} is not expanded in CMakeKists.txt
SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		doc/CMakeLists.txt
SUBST_SED.fix-paths=		-e 's,/share/man,/${PKGMANDIR},g'

.include "../../x11/vte/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
