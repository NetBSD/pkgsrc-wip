# $NetBSD: Makefile,v 1.3 2012/11/13 22:25:44 othyro Exp $
#

DISTNAME=	prioritized_methods-0.2.1.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-prioritized-methods-0.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prioritized_methods/}
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://toscawidgets.org/download
COMMENT=	Extension to PEAK-Rules to prioritize methods

DEPENDS+=	${PYPKGPREFIX}-peak-rules-[0-9]*:../../wip/py-peak-rules

WRKSRC=		${WRKDIR}/prioritized_methods-0.2.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
