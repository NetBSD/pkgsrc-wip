# $NetBSD: Makefile,v 1.6 2004/05/02 21:34:06 blef Exp $
#

DISTNAME=		elementtree-1.2a5-20031115
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20031115//}
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK3=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
