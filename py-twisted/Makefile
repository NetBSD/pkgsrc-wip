# $NetBSD: Makefile,v 1.8 2003/11/08 11:51:30 mpasternak Exp $
#

DISTNAME=		Twisted-1.1.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel net
MASTER_SITES=		http://twisted.sourceforge.net/ \
			http://twistedmatrix.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Framework for writing networked applications

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
