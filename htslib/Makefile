# $NetBSD$

DISTNAME=	htslib-1.9
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	C library for high-throughput sequencing data formats
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf gmake perl
GNU_CONFIGURE=	yes
REPLACE_PERL=	test/compare_sam.pl test/test.pl

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[make print-version\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	${WRKSRC}/configure.ac

PKGCONFIG_OVERRIDE=	htslib.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
