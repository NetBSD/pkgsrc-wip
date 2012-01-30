# $NetBSD: Makefile,v 1.2 2012/01/30 06:10:51 noud4 Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/mkfeyndiag ${WRKSRC}/mkfeyndiag${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
