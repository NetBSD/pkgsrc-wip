# $NetBSD: Makefile,v 1.2 2003/11/26 19:31:37 mpasternak Exp $
#

DISTNAME=		pynfo-0.6.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pynfo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pynfo.sourceforge.net/
COMMENT=		Nice, configureable info bot in Python

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted>=1.1.1rc1:../../wip/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
