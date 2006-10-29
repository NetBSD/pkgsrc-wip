# $NetBSD: Makefile,v 1.3 2006/10/29 08:32:54 shattered Exp $

NEVOW_VERSION=	0.9.0
DISTNAME=	Nevow-${NEVOW_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-nevow-${NEVOW_VERSION}
CATEGORIES=	www python
MASTER_SITES=	http://www.mirrorservice.org/sites/www.ibiblio.org/gentoo/distfiles/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodNevow
COMMENT=	A web templating framework that provides Athena, a two-way AJAX toolkit

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-twisted-web>=0.6.0:../../wip/py-twisted-web

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
