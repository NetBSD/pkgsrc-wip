# $NetBSD: Makefile,v 1.6 2003/09/14 22:00:38 marc Exp $
#

DISTNAME=		Twisted-1.0.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel net
MASTER_SITES=		http://twisted.sourceforge.net/ \
			http://twistedmatrix.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Framework for writing networked applications

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
