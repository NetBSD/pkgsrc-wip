# $NetBSD: Makefile,v 1.1 2014/02/06 15:24:19 outpaddling Exp $

DISTNAME=	python-hostlist-1.14
CATEGORIES=	parallel
MASTER_SITES=	http://www.nsc.liu.se/~kent/python-hostlist/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.nsc.liu.se/~kent/python-hostlist/
COMMENT=	Manage SLURM host lists
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		man
SUBST_FILES.man=	setup.py python-hostlist.spec
SUBST_STAGE.man=	post-patch
SUBST_SED.man=		-e 's|share/man|man|g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
