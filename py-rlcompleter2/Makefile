# $NetBSD: Makefile,v 1.4 2010/08/05 14:03:34 jihbed Exp $
#

DISTNAME=	rlcompleter2-0.96
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://codespeak.net/rlcompleter2/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codespeak.net/rlcompleter2/index.cgi?home
COMMENT=	Python command line completion
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
