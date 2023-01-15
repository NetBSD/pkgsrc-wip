# $NetBSD$

DISTNAME=	bzip3-1.2.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=kspalaiologos/bzip3/releases/download/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kspalaiologos/bzip3/
COMMENT=	Spiritual successor to BZip2
LICENSE=	gnu-lgpl-v3 AND apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config # configure looks for pkg-comfig

DEPENDS+=	most-[0-9]*:../../misc/most

PKGCONFIG_OVERRIDE+=	bzip3.pc.in

REPLACE_SH+=	bunzip3
REPLACE_SH+=	bz3cat
REPLACE_SH+=	bz3grep
REPLACE_SH+=	bz3less
REPLACE_SH+=	bz3more
REPLACE_SH+=	bz3most

# needed in order to comply with the apache license
# and binary redistribution
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/libsais-LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
