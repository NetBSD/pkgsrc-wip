# $NetBSD: Makefile,v 1.5 2010/07/25 13:40:09 lexort Exp $

MANTISSA_VERSION=	0.6.1
DISTNAME=	Mantissa-${MANTISSA_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-mantissa-${MANTISSA_VERSION}
PKGREVISION=	1
CATEGORIES=	python www net
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=         pkgsrc-wip-users@sourceforge.net
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodMantissa
COMMENT=	An extensible application server

DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../wip/py-twisted
DEPENDS+=	${PYPKGPREFIX}-pytz>=2005m:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-divmod-nevow>=0.9.0:../../wip/py-divmod-nevow
DEPENDS+=	${PYPKGPREFIX}-divmod-axiom>=0.5.0:../../wip/py-divmod-axiom
DEPENDS+=	${PYPKGPREFIX}-divmod-vertex>=0.2.0:../../wip/py-divmod-vertex

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
