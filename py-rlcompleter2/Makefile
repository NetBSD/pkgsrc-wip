# $NetBSD: Makefile,v 1.1.1.1 2004/04/22 23:42:11 mpasternak Exp $
#

DISTNAME=		rlcompleter2-0.95
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://codespeak.net/rlcompleter2/download/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://codespeak.net/rlcompleter2/index.cgi?home
COMMENT=		Python command line completion

DEPENDS+=		${PYPKGPREFIX}-readline>=0:../../devel/py-readline

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
