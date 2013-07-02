# $NetBSD: Makefile,v 1.4 2013/07/02 10:28:49 othyro Exp $
#

DISTNAME=	python-gnutls-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-gnutls/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ag-projects.com/
COMMENT=	Python wrapper for the GNUTLS library
LICENSE=	gnu-lgpl-v2

SUBST_CLASSES+=		gnutls
SUBST_FILES.gnutls=	gnutls/library/__init__.py
SUBST_MESSAGE.gnutls=	Fixing gnutls library version.
SUBST_SED.gnutls=	-e 's/26/28/g'
SUBST_SED.gnutls+=	-e "s|/usr/local/lib']|${PREFIX}/lib']|1"
SUBST_STAGE.gnutls=	post-patch

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../security/gnutls/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
