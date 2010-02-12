# $NetBSD: Makefile,v 1.1 2010/02/12 17:55:50 drochner Exp $
#

DISTNAME=	gosmore-1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.openstreetmap.org/wiki/Gosmore
COMMENT=	Navigation program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c c++

# Get it from Subversion repository:
SVN_REPOSITORIES=	gosmore
SVN_ROOT.gosmore= http://svn.openstreetmap.org/applications/rendering/gosmore/

WRKSRC=			${WRKDIR}/gosmore

.include "../../wip/mk/svn-package.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
