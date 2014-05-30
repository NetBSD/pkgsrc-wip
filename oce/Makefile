# $NetBSD: Makefile,v 1.1 2014/05/30 11:21:00 fhajny Exp $

DISTNAME=	OCE-0.15
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	cad
MASTER_SITES=	https://github.com/tpaviot/oce/archive/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/tpaviot/oce/
COMMENT=	Open CASCADE Community Edition
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/oce-${DISTNAME}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

# mk/configure/cmake.mk disable rpath handling
# but we need it for a lib subpath
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/oce

CMAKE_ARGS+=	-DOCE_INSTALL_PREFIX:PATH=${PREFIX}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
