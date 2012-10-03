# $NetBSD: Makefile,v 1.3 2012/10/03 22:14:53 thomasklausner Exp $
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
PYTHON_VERSIONS_ACCEPTED= 26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
