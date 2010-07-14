# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:13:03 jihbed Exp $
#

DISTNAME=	prioritized_methods-0.2.1.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-prioritized-methods-0.2.1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/prioritized_methods/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://toscawidgets.org/download
COMMENT=	An extension to PEAK-Rules to prioritize methods

DEPENDS+=	${PYPKGPREFIX}-peak-rules-[0-9]*:../../wip/py-peak-rules

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/prioritized_methods-0.2.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
