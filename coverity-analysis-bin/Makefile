# $NetBSD$

DISTNAME=	cov-analysis-netbsd64-2022.06
PKGNAME=	coverity-analysis-bin-2022.06
CATEGORIES=	devel
MASTER_SITES=	# http://scan.coverity.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scan.coverity.com/
COMMENT=	Static Analysis for Java, C/C++, C\#, JavaScript, Ruby, or Python
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/cov-analysis-netbsd64-2022.6.0
INSTALLATION_DIRS+=	${PREFIX}/coverity

ONLY_FOR_PLATFORM=	NetBSD-*-x86_64
NOT_FOR_PLATFORM=	NetBSD-[0-4]*.*-x86_64
# pre-built binaries without RELRO
CHECK_RELRO_SUPPORTED=	no

USE_TOOLS+=		pax
EXTRACT_USING=		bsdtar

do-build:

do-install:
	cd ${WRKSRC} && pax -pp -rw * ${DESTDIR}${PREFIX}/coverity/
	find ${DESTDIR}${PREFIX}/coverity/config/templates -type f -exec ${CHMOD} a-x {} \;

.include "../../mk/bsd.pkg.mk"
