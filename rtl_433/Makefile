# $NetBSD$

GITHUB_PROJECT=	rtl_433
GITHUB_TAG=	25.12
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=merbanan/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://triq.org/rtl_433/
COMMENT=	Generic data receiver and decoder using software defined radio
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pax
AUTO_MKDIRS=	yes

PKG_SYSCONFSUBDIR=	rtl_433
# However, things are installed that are examples or belong in share
# and are not truly config files.  \todo Address upstream.

post-install:
	# \todo File bug upstream about wrong man location.
	${INSTALL_MAN} ${WRKSRC}/man/man1/rtl_433.1 \
	        ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RM} -rf ${DESTDIR}${PREFIX}/share/man
	# \todo File a bug upstream about needing to install these things
	cd ${WRKSRC}/examples && ${PAX} -wr . ${DESTDIR}${PREFIX}/share/examples/rtl_433/
	cd ${WRKSRC}/conf && ${PAX} -wr . ${DESTDIR}${PREFIX}/share/examples/rtl_433/conf/
	cd ${WRKSRC}/docs && ${PAX} -wr . ${DESTDIR}${PREFIX}/share/doc/rtl_433/
	# \todo File upstream bug.
	# \todo remove in source before copying, to be cleaner
	${RM} ${DESTDIR}${PREFIX}/share/doc/rtl_433/.gitignore

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
