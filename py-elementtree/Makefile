# $NetBSD: Makefile,v 1.4 2003/08/15 19:50:27 marc Exp $
#

DISTNAME=		elementtree-1.2a2-20030729
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/-20030729//}
CATEGORIES=		textproc
MASTER_SITES=		http://effbot.org/downloads/
EXTRACT_SUFX=		.zip

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://effbot.org/zone/element.htm
COMMENT=		Read XML and HTML files into trees of Element objects

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

post-install:
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py \
		${PREFIX}/${PYSITELIB}/elementtree

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
