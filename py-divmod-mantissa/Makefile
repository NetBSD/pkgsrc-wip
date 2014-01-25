# $NetBSD: Makefile,v 1.11 2014/01/25 10:38:17 thomasklausner Exp $

MANTISSA_VERSION=	0.6.1
DISTNAME=	Mantissa-${MANTISSA_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-mantissa-${MANTISSA_VERSION}
PKGREVISION=	2
CATEGORIES=	python www net
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodMantissa
COMMENT=	Extensible application server

DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-pytz>=2005m:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-nevow>=0.9.0:../../www/py-nevow
DEPENDS+=	${PYPKGPREFIX}-divmod-axiom>=0.5.0:../../wip/py-divmod-axiom
DEPENDS+=	${PYPKGPREFIX}-divmod-vertex>=0.2.0:../../wip/py-divmod-vertex

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	26
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-twisted, py-xml via py-nevow

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
