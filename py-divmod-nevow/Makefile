# $NetBSD: Makefile,v 1.5 2008/05/22 15:38:46 tnn2 Exp $

NEVOW_VERSION=	0.9.18
DISTNAME=	Nevow-${NEVOW_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-nevow-${NEVOW_VERSION}
CATEGORIES=	www python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodNevow
COMMENT=	A web templating framework that provides Athena, a two-way AJAX toolkit

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=0.6.0:../../wip/py-twisted-web

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
