# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 11:18:41 jihbed Exp $
#

DISTNAME=	PuLP-1.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/S/L/l/S/P/p/}
CATEGORIES=	math  python
MASTER_SITES=	http://pulp-or.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pulp-or/
COMMENT=	LP modeler in Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED= 26 25 24

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
