# $NetBSD: Makefile,v 1.1 2013/01/08 03:55:32 othyro Exp $
#

DISTNAME=	swe_unix_src_1.78.00
PKGNAME=	${DISTNAME:S/e_unix_src_/isseph-/1}
CATEGORIES=	time
MASTER_SITES=	ftp://ftp.astro.com/pub/swisseph/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.astro.com/swisseph/swephinfo_e.htm
COMMENT=	High precision ephemeris developed by Astrodienst
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS+=	bin lib share/doc/${PKGBASE} share/${PKGBASE}

CFLAGS+=	-DSE_EPHE_PATH=\"${PREFIX}/share/${PKGBASE}\"

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} swetest ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_LIB} libswe.a ${DESTDIR}${PREFIX}/lib

	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} *.pdf *.htm ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libswe.a

.include "../../mk/bsd.pkg.mk"
