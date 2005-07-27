# $NetBSD: Makefile,v 1.2 2005/07/27 16:29:02 thomasklausner Exp $
#

DISTNAME=		rlcompleter2-0.95
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://codespeak.net/rlcompleter2/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://codespeak.net/rlcompleter2/index.cgi?home
COMMENT=		Python command line completion

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
