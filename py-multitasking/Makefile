# $NetBSD$

DISTNAME=	multitasking-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multitasking/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/ranaroussi/multitasking
COMMENT=	Non-blocking Python methods using decorators
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/sample

.include "../../mk/bsd.pkg.mk"
