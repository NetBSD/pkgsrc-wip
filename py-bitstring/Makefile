# $NetBSD: Makefile,v 1.3 2009/05/23 19:23:22 jihbed Exp $
#

DISTNAME=	bitstring-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://python-bitstring.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://python-bitstring.googlecode.com/
COMMENT=	Tools for analysis and modification of binary data in python
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
