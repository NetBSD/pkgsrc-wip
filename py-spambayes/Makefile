# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:34 ykomatsu Exp $
#

DISTNAME=		spambayes-1.0a7
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
