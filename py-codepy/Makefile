# $NetBSD: Makefile,v 1.2 2012/01/30 06:01:48 noud4 Exp $
#

DISTNAME=	codepy-0.90.tar
PKGNAME=	${PYPKGPREFIX}-codepy-0.90
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/codepy/
EXTRACT_SUFX=	.gz#md5=72efff7486689f778f1b1f82a87b2d12

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://mathema.tician.de/software/codepy
COMMENT=	CodePy is a C metaprogramming toolkit for Python
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/codepy-0.90
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
