# $NetBSD: Makefile,v 1.6 2012/10/07 13:57:29 asau Exp $
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

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
