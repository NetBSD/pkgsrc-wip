# $NetBSD: Makefile,v 1.2 2006/07/16 12:45:22 shattered Exp $
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

PYTHON_VERSIONS_ACCEPTED= 24 23 22

.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
