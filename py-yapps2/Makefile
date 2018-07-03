# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:47 thomasklausner Exp $

VERS=		2.1.1
DISTNAME=	yapps${VERS}
PKGNAME=	${PYPKGPREFIX}-yapps2-${VERS}
CATEGORIES=	textproc python
MASTER_SITES=	http://theory.stanford.edu/~amitp/yapps/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://theory.stanford.edu/~amitp/yapps/
COMMENT=	Yet Another Python Parser System
LICENSE=	mit

WRKSRC=		${WRKDIR}/Yapps-2.1.1
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.1.1

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
