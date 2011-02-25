# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:50 thomasklausner Exp $

DISTNAME=				ssh4py-0.6.9
EXTRACT_SUFX=			.zip
PKGNAME=				${PYPKGPREFIX}-ssh2-0.6.9
CATEGORIES=				security python
MASTER_SITES=			http://www.keyphrene.com/download/

MAINTAINER=				pmcphee@givex.com
COMMENT=				Python wrapper around libssh2
HOMEPAGE=				http://www.keyphrene.com/products/4py/
LICENSE=				gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=					${WRKDIR}/ssh4py-0.6.9

NO_CONFIGURE=			yes

#PYTHON_VERSIONS_ACCEPTED= 27 26 25 24 23

PYDISTUTILSPKG=	yes
#PYBINMODULE=	yes
PYSETUP=				setup_ssh4.py

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
