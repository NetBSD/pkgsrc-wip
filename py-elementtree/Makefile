# $NetBSD: Makefile,v 1.1.1.1 2003/05/26 14:24:43 marc Exp $
#

DISTNAME=		elementtree-1.1-20030511
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20030511//}
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		read XML and HTML files into trees of Element objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
