# $NetBSD$

DISTNAME=	CORTEX_release_v1.0.5.21
PKGNAME=	cortex-var-1.0.5.21
CATEGORIES=	biology
MASTER_SITES=	https://sourceforge.net/projects/cortexassembler/files/latest/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://sourceforge.net/projects/cortexassembler/files/latest/download/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)


WRKSRC=		${WRKDIR}/CORTEX_release_v1.0.5.21
USE_TOOLS+=	pkg-config gmake
BUILD_TARGET=	cortex_var

_BLNK_PASSTHRU_DIRS+=	${WRKSRC}/libs

PKGCONFIG_OVERRIDE+=	libs/gsl-1.15/gsl.pc.in
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cortex_var_31_c1 ${DESTDIR}${PREFIX}/bin
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
