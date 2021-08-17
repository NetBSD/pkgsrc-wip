# $NetBSD$

DISTNAME=	olm-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	https://gitlab.matrix.org/matrix-org/olm/-/archive/3.2.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.matrix.org/matrix-org/olm/-/archive/3.2.2/
COMMENT=	Olm bindings for Python
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/python

.include "../../security/olm/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
