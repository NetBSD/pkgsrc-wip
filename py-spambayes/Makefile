# $NetBSD: Makefile,v 1.7 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=		spambayes-1.1b1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=spambayes/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://spambayes.sourceforge.net/
COMMENT=		Bayesian anti-spam filter, initially based on the work of Paul Graham

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
