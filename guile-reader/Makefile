# $NetBSD$

DISTNAME=	guile-reader-0.6.2
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-reader/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://download.savannah.nongnu.org/releases/guile-reader/
COMMENT=	Extensible reader framework for GNU Guile.
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config automake autoconf autoreconf gmake

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib
# --with-guilemoduledir=/usr/pkg/guile/2.2/share/guile/site/2.2'.

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../devel/gperf/buildlink3.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
