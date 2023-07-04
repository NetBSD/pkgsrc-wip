# $NetBSD$

DISTNAME=	mpc-1.3.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mpc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.multiprecision.org/mpc/
COMMENT=	MPFR-based library for complex floating-point with exact rounding
LICENSE=	gnu-lgpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
.include "../../mk/bsd.prefs.mk"
# .if !empty(MACHINE_PLATFORM:MNetBSD-[0-9]*-*)
# CONFIGURE_ARGS+=        --disable-float128
# .endif
# TEST_TARGET=		check
INFO_FILES=		yes

# PKGCONFIG_OVERRIDE+=	mpfr.pc.in

BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=4.1
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# .if (${MACHINE_ARCH} == alpha)
# CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-mieee}"
# .endif
