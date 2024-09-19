# $NetBSD: Makefile,v 1.55 2019/03/10 11:22:43 spz Exp $

DISTNAME=		jpegsrc.v9c
ABI=			32
PKGNAME=		compat${ABI}_${DISTNAME:S/src.v/-/}
CATEGORIES=		graphics
MASTER_SITES=		http://www.ijg.org/files/
DIST_SUBDIR=		jpeg-9c-v2
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

CONFLICTS=		libjpeg-turbo-[0-9]*

WRKSRC=			${WRKDIR}/jpeg-9c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/emul/netbsd32/
CONFIGURE_ARGS+=	--disable-ld-version-script

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/emul/netbsd32

INSTALLATION_DIRS=	bin include share/doc/jpeg

PKGCONFIG_OVERRIDE=	libjpeg.pc.in

TEST_TARGET=		test

post-extract:
	${CP} ${FILESDIR}/jpegexiforient.c ${WRKSRC}

post-install:
	# ${INSTALL_SCRIPT} ${FILESDIR}/exifautotran ${DESTDIR}${PREFIX}/bin
	# ${INSTALL_DATA} ${WRKSRC}/jpegint.h ${DESTDIR}${PREFIX}/include
	# ${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/jpeg

.include "../../mk/bsd.pkg.mk"
