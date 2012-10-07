# $NetBSD: Makefile,v 1.3 2012/10/07 11:54:33 asau Exp $
#

DISTNAME=	pyfeyn-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/pyfeyn/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/pyfeyn/
COMMENT=	Easy-to-use Python library to help physicists draw Feynman diagrams
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-X>=0.9:../../textproc/py-X

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/mkfeyndiag ${WRKSRC}/mkfeyndiag${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
