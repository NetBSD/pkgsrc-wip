# $NetBSD: Makefile,v 1.3 2003/07/21 17:33:19 marttikuparinen Exp $
#

DISTNAME=		elementtree-1.2a1-20030529
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20030529//}
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
