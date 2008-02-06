# $NetBSD: Makefile,v 1.3 2008/02/06 19:09:50 shattered Exp $
#

DISTNAME=		pytagger-0.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		audio
MASTER_SITES=		http://www.liquidx.net/static/pytagger/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.liquidx.net/pytagger/
COMMENT=		ID3v1 and ID3v2 tag library in Python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_INCOMPATIBLE=\
			15 20 21 22

.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
