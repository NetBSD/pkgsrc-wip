# $NetBSD: Makefile,v 1.6 2009/03/28 21:08:10 milosn Exp $

NEVOW_VERSION=	0.9.18
DISTNAME=	Nevow-${NEVOW_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-nevow-${NEVOW_VERSION}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodNevow
COMMENT=	A web templating framework that provides Athena, a two-way AJAX toolkit

DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../wip/py-twisted

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
