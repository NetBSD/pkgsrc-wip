# $NetBSD: Makefile,v 1.3 2003/11/20 15:19:44 mpasternak Exp $
#

DISTNAME=		Quotient-0.8.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		mail
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/divmod/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.divmod.org/Quotient/
COMMENT=		E-mail server, messaging server (IM/IRC) and IP telephony

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted>=1.1.0:../../wip/py-twisted
DEPENDS+=		${PYPKGPREFIX}-bsddb3>=4.1.1:../../databases/py-bsddb3

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
