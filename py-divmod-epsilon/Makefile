# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:53 shattered Exp $

EPSILON_VERSION=	0.5.0
DISTNAME=	Epsilon-${EPSILON_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-epsilon-${EPSILON_VERSION}
CATEGORIES=	python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodNevow
COMMENT=	A Python utilities package, most famous for its Time class

DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
