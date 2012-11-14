# $NetBSD: Makefile,v 1.4 2012/11/14 00:16:14 othyro Exp $
#

DISTNAME=	pyfeyn-0.3.2
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/1}
PKGREVISION=	1
CATEGORIES=	graphics
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
