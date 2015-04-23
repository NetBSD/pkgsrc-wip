# $NetBSD: Makefile,v 1.1 2015/04/23 09:49:45 ahp-nils Exp $

DISTNAME=	yapf-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel textproc
MASTER_SITES=	-https://github.com/google/yapf/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/google/yapf/
COMMENT=	Python files formatter
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_ACCEPTED=	34 27

post-install:
		${MV} ${DESTDIR}${PREFIX}/bin/yapf ${DESTDIR}${PREFIX}/bin/yapf${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
