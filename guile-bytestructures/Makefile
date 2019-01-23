# $NetBSD$

GITHUB_PROJECT=	scheme-bytestructures
DISTNAME=	v1.0.5
PKGNAME=	${GITHUB_PROJECT:S/scheme/guile/}-${DISTNAME:S/v//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=TaylanUB/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TaylanUB/scheme-bytestructures/
COMMENT=	Structured access to bytevector contents
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/scheme-bytestructures-1.0.5
USE_LANGUAGES=	c
USE_TOOLS+=	automake autoconf autoreconf pkg-config
GNU_CONFIGURE=	YES

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
