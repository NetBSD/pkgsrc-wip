# $NetBSD: Makefile,v 1.17 2012/11/09 23:18:45 outpaddling Exp $

DISTNAME=	meep-1.2
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/meep/
COMMENT=	FDTD simulation software to model electromagnetic systems
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran77

CONFIGURE_ARGS+=--with-libctl=${BUILDLINK_PREFIX.libctl}/share/libctl

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

# Hack to work around problem finding libguile*.dylib
# Darwin needs libguile with a .so suffix and LD_LIBRARY_PATH to include
# ${LOCALBASE}/lib
.if ${OPSYS} == "Darwin"
post-install:
	${CP} ${PREFIX}/lib/libguile-srfi-srfi-1-v-3.dylib \
		${DESTDIR}${PREFIX}/lib/libguile-srfi-srfi-1-v-3.so
.endif

.include "../../wip/mpb/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../math/harminv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
