# $NetBSD$

DISTNAME=	scheme-bytestructures-1.0.5
PKGNAME=	${DISTNAME:S/scheme/guile/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=TaylanUB/}
GITHUB_PROJECT=	scheme-bytestructures
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TaylanUB/scheme-bytestructures/
COMMENT=	Structured access to bytevector contents
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c
USE_TOOLS+=	automake autoconf autoreconf pkg-config
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
