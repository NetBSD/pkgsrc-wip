# $NetBSD: Makefile,v 1.1.1.1 2011/06/22 13:04:27 jihbed Exp $
#

DISTNAME=	datatree-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/d/datatree/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bigjason/datatree
COMMENT=	DSL for creating structured documents in python

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.08:../../textproc/py-yaml

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/datatree-0.1.8

USE_LANGUAGES=	# none
#PYTHON_VERSIONS_ACCEPTED= 27 26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
