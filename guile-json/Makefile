# $NetBSD$

DISTNAME=	guile-json-3.1.0
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/guile-json/

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://github.com/aconchillo/guile-json
COMMENT=	JSON module for Guile
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
USE_TOOLS+=	automake autoconf autoreconf pkg-config makeinfo
GNU_CONFIGURE=	YES

GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
