# $NetBSD: Makefile,v 1.1.1.1 2003/11/18 08:03:42 mpasternak Exp $
#

DISTNAME=		Quotient-0.8.0
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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
