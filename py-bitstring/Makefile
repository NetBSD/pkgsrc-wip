# $NetBSD: Makefile,v 1.2 2009/04/13 22:17:17 jihbed Exp $
#

DISTNAME=	bitstring-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://python-bitstring.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://python-bitstring.googlecode.com/
COMMENT=	Tools for analysis and modification of binary data in python

USE_LANGUAGES=	# none

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 25 24 # preview 26
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
