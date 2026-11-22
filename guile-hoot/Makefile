# $NetBSD$

DISTNAME=		hoot-0.10.0
PKGNAME=		guile-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_CODEBERG:=spritely/}
CODEBERG_PROJECT=	hoot
CODEBERG_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://codeberg.org/spritely/hoot/
COMMENT=	Guile Scheme to WASM Compiler
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/hoot
USE_TOOLS=	autoconf aclocal automake autopoint gettext pkg-config \
		gmake makeinfo
GNU_CONFIGURE=	yes
# won't compile without 6.0
TEXINFO_REQD+=	6.0
INFO_FILES=	yes

pre-configure:
	cd ${WRKSRC} && ./bootstrap.sh

.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
