# $NetBSD: Makefile,v 1.2 2011/06/02 22:15:50 othyro Exp $
#

DISTNAME=	qdevelop-v0.28
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	devel
MASTER_SITES=	http://biord-software.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://biord-software.org/qdevelop/
COMMENT=	Development environment entirely dedicated to Qt4
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
