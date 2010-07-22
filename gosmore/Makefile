# $NetBSD: Makefile,v 1.4 2010/07/22 16:56:04 drochner Exp $
#

DISTNAME=	gosmore-1
CHECKOUT_DATE=	20100722
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.openstreetmap.org/wiki/Gosmore
COMMENT=	Navigation program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes

# Get it from Subversion repository:
SVN_REPOSITORIES=	gosmore
SVN_ROOT.gosmore= http://svn.openstreetmap.org/applications/rendering/gosmore/

WRKSRC=			${WRKDIR}/gosmore

.include "../../wip/mk/svn-package.mk"

BUILDLINK_DEPMETHOD.bzip2= build
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
