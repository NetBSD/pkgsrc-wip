# $NetBSD: Makefile,v 1.1.1.1 2012/06/02 11:02:13 slitvinov Exp $
#

DISTNAME=	recoll-1.17.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://www.lesbonscomptes.com/recoll/
COMMENT=	Full text desktop search engine
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
CONFIGURE_ARGS+= --disable-python-module

# the package installs share/applications/recoll-searchgui.desktop
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../sysutils/fam/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
