# $NetBSD: Makefile,v 1.1.1.1 2003/11/20 17:23:59 mpasternak Exp $
#

DISTNAME=		spambayes-1.0a7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/spambayes/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://spambayes.sourceforge.net/
COMMENT=		Bayesian anti-spam filter, initially based on the work of Paul Graham

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
