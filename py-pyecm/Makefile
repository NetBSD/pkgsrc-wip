# $NetBSD: Makefile,v 1.5 2012/11/12 16:26:49 othyro Exp $
#

DISTNAME=	pyecm-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyecm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyecm.sourceforge.net/
COMMENT=	Integer factorization with the Elliptic Curve Method (ECM)
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

NO_BUILD=	yes

REPLACE_PYTHON+=	pycem.py

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pyecm.py ${DESTDIR}${PREFIX}/bin/pycem

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
