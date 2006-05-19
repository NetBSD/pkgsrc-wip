# $NetBSD: Makefile,v 1.3 2006/05/19 16:51:33 ykomatsu Exp $
#

DISTNAME=		rlcompleter2-0.95
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://codespeak.net/rlcompleter2/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://codespeak.net/rlcompleter2/index.cgi?home
COMMENT=		Python command line completion

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
