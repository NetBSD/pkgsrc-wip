# $NetBSD$

DISTNAME=	gash-0.1
PKGNAME=	guile-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://download.savannah.nongnu.org/releases/gash/

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://git.savannah.nongnu.org/cgit/gash.git
COMMENT=	POSIX-compatible shell written in Guile Scheme
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib
USE_TOOLS+=		automake autoconf autoreconf pkg-config

INFO_FILES=	YES

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
