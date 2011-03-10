# $NetBSD: Makefile,v 1.5 2011/03/10 12:14:32 obache Exp $
#

DISTNAME=	WritRecogn-0.1.9
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/writrecogn/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://writrecogn.sourceforge.net/
COMMENT=	CJK Handwriting Recoginzer
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	gob2>=2.0.0:../../devel/gob2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		datadir
SUBST_STAGE.datadir=	post-configure
SUBST_SED.datadir=	-e 's|/usr/share|${PREFIX}/share|'
SUBST_FILES.datadir=	src/common.h

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
