# $NetBSD: Makefile,v 1.3 2012/11/14 00:15:59 othyro Exp $
#

DISTNAME=	aten-1.7
CATEGORIES=	graphics math
MASTER_SITES=	http://www.projectaten.org/download/1.7/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.projectaten.org/
COMMENT=	Aten is a tool to create, edit, and visualise coordinates
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/readline/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.6.1nb3
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
