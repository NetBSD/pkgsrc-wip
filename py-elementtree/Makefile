# $NetBSD: Makefile,v 1.5 2003/09/14 22:00:37 marc Exp $
#

DISTNAME=		elementtree-1.2a2-20030729
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20030729//}
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
