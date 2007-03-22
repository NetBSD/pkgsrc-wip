# $NetBSD: Makefile,v 1.2 2007/03/22 21:02:42 milosn Exp $

MANTISSA_VERSION=	0.6.1
DISTNAME=	Mantissa-${MANTISSA_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-mantissa-${MANTISSA_VERSION}
CATEGORIES=	python www net
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodMantissa
COMMENT=	An extensible application server

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-tz>=2005m:../../wip/py-tz
DEPENDS+=	${PYPKGPREFIX}-divmod-nevow>=0.9.0:../../wip/py-divmod-nevow
DEPENDS+=	${PYPKGPREFIX}-divmod-axiom>=0.5.0:../../wip/py-divmod-axiom
DEPENDS+=	${PYPKGPREFIX}-divmod-vertex>=0.2.0:../../wip/py-divmod-vertex

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
