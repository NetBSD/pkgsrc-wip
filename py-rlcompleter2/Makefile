# $NetBSD: Makefile,v 1.7 2013/06/04 07:45:24 thomasklausner Exp $
#

DISTNAME=	rlcompleter2-0.96
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://codespeak.net/rlcompleter2/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codespeak.net/rlcompleter2/index.cgi?home
COMMENT=	Python command line completion
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
