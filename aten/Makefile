# $NetBSD: Makefile,v 1.1.1.1 2011/09/19 23:25:50 jihbed Exp $
#

DISTNAME=	aten-1.7
CATEGORIES=	science
MASTER_SITES=	http://www.projectaten.org/download/1.7/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.projectaten.org/
COMMENT=	Aten is a tool to create, edit, and visualise coordinates
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_GNU_READLINE= YES

.include "../../devel/readline/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.6.1nb3
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
