# $NetBSD$

DISTNAME=	0.16.0
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	https://git.sr.ht/~rjarry/aerc/archive/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~rjarry/aerc/archive/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/aerc-0.16.0

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
USE_LANGUAGES=	c go

TOOL_DEPENDS+=	go118>=1.18.0:../../lang/go118
TOOL_DEPENDS+=	scdoc:../../textproc/scdoc

REPLACE_INTERPRETER+=	env
REPLACE.env.old=	.*/bin/env
REPLACE.env.new=	${PREFIX}/bin/env
REPLACE_FILES.env=	contrib/carddav-query
REPLACE_FILES.env=	filters/show-ics-details.py

.include "../../mk/bsd.pkg.mk"
