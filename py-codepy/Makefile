# $NetBSD: Makefile,v 1.1.1.1 2009/12/27 20:58:43 jihbed Exp $
#

DISTNAME=	codepy-0.90.tar
PKGNAME=	${PYPKGPREFIX}-codepy-0.90
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
