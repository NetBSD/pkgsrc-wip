# $NetBSD: Makefile,v 1.7 2009/03/28 21:04:58 milosn Exp $

EPSILON_VERSION=	0.5.6
DISTNAME=	Epsilon-${EPSILON_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-epsilon-${EPSILON_VERSION}
PKGREVISION=	1
CATEGORIES=	python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodNevow
COMMENT=	A Python utilities package, most famous for its Time class

DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../wip/py-twisted

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
