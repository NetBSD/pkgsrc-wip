# $NetBSD: Makefile,v 1.8 2004/01/04 10:25:12 mpasternak Exp $
#

DISTNAME=		Quotient-0.8.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		mail
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/divmod/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.divmod.org/Quotient/
COMMENT=		E-mail server, messaging server (IM/IRC) and IP telephony

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../wip/py-bsddb/buildlink2.mk"
.include "../../wip/py-spambayes/buildlink2.mk"
.include "../../wip/py-twisted/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
