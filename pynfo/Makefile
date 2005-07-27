# $NetBSD: Makefile,v 1.7 2005/07/27 16:29:32 thomasklausner Exp $
#

DISTNAME=		pynfo-0.6.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pynfo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pynfo.sourceforge.net/
COMMENT=		Nice, configureable info bot in Python

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.1.1rc1:../../net/py-twisted

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
