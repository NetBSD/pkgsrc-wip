# $NetBSD: Makefile,v 1.1 2014/10/25 14:13:13 cheusov Exp $

DISTNAME=	0.9.0
PKGNAME=	csvkit-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/onyxfish/csvkit/archive/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/onyxfish/csvkit/archive/
COMMENT=	Suite of utilities for converting to and working with CSV
LICENSE=	mit

# csvkit publishes files like "0.9.0.tar.gz"
DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
#.include "../../lang/python/egg.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
