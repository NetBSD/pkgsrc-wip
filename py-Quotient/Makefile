# $NetBSD: Makefile,v 1.7 2003/12/18 02:49:44 mpasternak Exp $
#

DISTNAME=		Quotient-0.8.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		mail
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/divmod/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.divmod.org/Quotient/
COMMENT=		E-mail server, messaging server (IM/IRC) and IP telephony

DEPENDS+=		${PYPKGPREFIX}-Twisted>=1.1.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-spambayes>=1.0a7:../../wip/py-spambayes
DEPENDS+=		${PYPKGPREFIX}-bsddb>=0:../../wip/py-bsddb

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
