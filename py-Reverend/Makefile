# $NetBSD: Makefile,v 1.2 2004/02/27 01:59:14 minskim Exp $
#

DISTNAME=		Reverend-0.2.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=reverend/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.divmod.org/Reverend/
COMMENT=		General purpose Bayesian classifier

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
