# $NetBSD$

DISTNAME=	xoreos-tools-0.0.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=xoreos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://xoreos.org/
COMMENT=	Tools to help the development of xoreos
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CXXFLAGS+=	-fpermissive

pre-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/man/man1

do-install:
	for prog in ${WRKSRC}/bin/*; do \
		${INSTALL_PROGRAM} $${prog} ${DESTDIR}${PREFIX}/bin; \
	done
	for page in ${WRKSRC}/man/*.1; do \
		${INSTALL_MAN} $${page} ${DESTDIR}${PREFIX}/man/man1; \
	done

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
