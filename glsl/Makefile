# $NetBSD: Makefile,v 1.1.1.1 2010/11/22 23:39:34 pallegra Exp $
#

.include "../../wip/glsl/Makefile.common"

PKGNAME=	${COMPONENT}-${MESA_PKGVERSION}
DISTFILES=	MesaLib-${MESA_VERSION}${EXTRACT_SUFX}
CATEGORIES=	graphics lang
EXTRACT_SUFX=	.tar.bz2

COMPONENT=	glsl

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	Mesa's GLSL preprocessor and compiler
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	bin

BUILD_DIRS=	src/glsl
BUILD_TARGET=	default

post-extract:
	for fn in ${FILESDIR}/configs/*; do \
		${CP} $${fn} ${WRKSRC}/configs; \
	done
	${CP} ${FILESDIR}/configs/pkgsrc ${WRKSRC}/configs/current

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/glsl/glcpp/glcpp \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/glsl/glsl_compiler \
	    ${DESTDIR}${PREFIX}/bin

.include "../../wip/talloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
