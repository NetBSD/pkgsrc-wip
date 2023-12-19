# $NetBSD$

DISTNAME=	0.16.0
CATEGORIES=	mail
MASTER_SITES=	https://git.sr.ht/~rjarry/aerc/archive/

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://git.sr.ht/~rjarry/aerc/archive/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/aerc-0.16.0

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
USE_LANGUAGES=	c go

TOOL_DEPENDS+=	go118>=1.18.0:../../lang/go118
TOOL_DEPENDS+=	scdoc:../../textproc/scdoc

REPLACE_PYTHON+=	contrib/carddav-query
REPLACE_PYTHON+=	filters/show-ics-details.py
.include "../../lang/python/application.mk"

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
