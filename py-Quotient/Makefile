# $NetBSD: Makefile,v 1.12 2005/07/27 16:27:48 thomasklausner Exp $
#

DISTNAME=		Quotient-0.9.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		mail
MASTER_SITES=		http://www.divmod.org/users/release/divmod/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.divmod.org/Home/Projects/Quotient/index.html
COMMENT=		E-mail server, messaging server (IM/IRC) and IP telephony

DEPENDS+=		${PYPKGPREFIX}-Lupy>=0.2.1:../../textproc/py-Lupy
DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted
DEPENDS+=		${PYPKGPREFIX}-spambayes>=1.0a7:../../wip/py-spambayes
DEPENDS+=		${PYPKGPREFIX}-bsddb>=0:../../wip/py-bsddb
DEPENDS+=		${PYPKGPREFIX}-nevow>=0.2.0:../../wip/py-nevow

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
