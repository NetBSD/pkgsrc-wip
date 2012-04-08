# $NetBSD: Makefile,v 1.2 2012/04/08 19:09:49 thomasklausner Exp $
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
PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
