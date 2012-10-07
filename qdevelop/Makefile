# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	qdevelop-v0.28
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	devel
MASTER_SITES=	http://biord-software.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://biord-software.org/qdevelop/
COMMENT=	Development environment entirely dedicated to Qt4
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
