# $NetBSD: Makefile,v 1.8 2013/01/19 08:20:45 othyro Exp $
#

DISTNAME=	xplore-1.2a
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xplore/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xplore/
COMMENT=	X11/Motif File Manager
LICENSE=	gnu-gpl-v2

USE_IMAKE=	yes

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
