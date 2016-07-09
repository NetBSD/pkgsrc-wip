# $NetBSD: Makefile,v 1.16 2014/05/09 07:38:46 thomasklausner Exp $

EPSILON_VERSION=	0.5.12
DISTNAME=	Epsilon-${EPSILON_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-epsilon-${EPSILON_VERSION}
#PKGREVISION=	2
CATEGORIES=	python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodNevow
COMMENT=	Python utilities package, most famous for its Time class

DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../net/py-twisted

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
