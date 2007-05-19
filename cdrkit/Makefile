# $NetBSD: Makefile,v 1.3 2007/05/19 19:42:39 thomasklausner Exp $
#

DISTNAME=	cdrkit-1.1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://cdrkit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cdrkit.org/
COMMENT=	Portable command-line CD/DVD recorder software

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
MAKE_FLAGS+=	MANSUBDIR=man

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
