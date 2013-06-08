# $NetBSD: Makefile,v 1.2 2013/06/08 00:17:55 othyro Exp $
#

DISTNAME=	python-gnutls-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-gnutls/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ag-projects.com/
COMMENT=	Python wrapper for the GNUTLS library
LICENSE=	gnu-lgpl-v2

.include "../../security/gnutls/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
