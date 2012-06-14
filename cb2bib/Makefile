# $NetBSD: Makefile,v 1.12 2012/06/14 02:25:45 othyro Exp $
#

DISTNAME=		cb2bib-0.7.2
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.molspaces.com/dl/progs/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.molspaces.com/cb2bib/
COMMENT=		Extract and organize bibliographic references
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	src/src.pro
SUBST_SED.path=		-e 's,xxPREFIXxx,${PREFIX},g'
SUBST_MESSAGE.path=	Fixing hardcoded paths.

do-configure:
	cd ${WRKSRC} && ${SET_ENV} ${CONFIGURE_ENV} ./configure \
	--prefix ${PREFIX} --bindir ${PREFIX}/bin --datadir ${PREFIX}/share

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
