# $NetBSD$

DISTNAME=	v0.1.0
DIST_SUBDIR=	${PKGNAME_NOREV}
PKGNAME=	guile-gcrypt-${DISTNAME:S/v//}
CATEGORIES=	devel
MASTER_SITES=	https://notabug.org/cwebber/guile-gcrypt/archive/
PKGREVISION=	1

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://notabug.org/cwebber/guile-gcrypt/archive/
COMMENT=	Guile bindings for libgcrypt
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/guile-gcrypt
USE_LANGUAGES=	# none
USE_TOOLS+=	automake autoconf autoreconf pkg-config makeinfo
GNU_CONFIGURE=	YES

GNU_CONFIGURE_PREFIX=   ${PREFIX}/guile/2.2
CONFIGURE_ARGS+=        --libdir=${PREFIX}/guile/2.2/lib
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
