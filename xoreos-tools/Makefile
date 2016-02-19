# $NetBSD$

DISTNAME=	xoreos-tools
PKGNAME=	xoreos-tools-${GITHUB_TAG:S/v//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=xoreos/}
GITHUB_TAG=	v0.0.4

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://xoreos.org/
COMMENT=	Tools to help the development of xoreos
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CXXFLAGS+=	-fpermissive

pre-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin ${DESTDIR}${PREFIX}/man/man1

do-install:
	for prog in ${WRKSRC}/bin/*; do \
		${INSTALL_PROGRAM} $${prog} ${DESTDIR}${PREFIX}/bin; \
	done
	for page in ${WRKSRC}/man/*.1; do \
		${INSTALL_MAN} $${page} ${DESTDIR}${PREFIX}/man/man1; \
	done

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
