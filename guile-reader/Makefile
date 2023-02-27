# $NetBSD$

DISTNAME=	guile-reader-0.6.3
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-reader/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/guile-reader/
COMMENT=	Extensible reader framework for GNU Guile
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		gmake gsed pkg-config
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

.include "../../devel/gperf/buildlink3.mk"
.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
