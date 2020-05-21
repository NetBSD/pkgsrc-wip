# $NetBSD$

DISTNAME=	htslib-1.10.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	C library for high-throughput sequencing data formats
LICENSE=	mit

USE_TOOLS+=		autoconf automake autoreconf gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libcurl
PKGCONFIG_OVERRIDE=	htslib.pc.in
TEST_TARGET=		test

REPLACE_PERL+=		test/compare_sam.pl
REPLACE_PERL+=		test/test.pl

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_SED.version=	-e "s|m4_esyscmd_s(\[make print-version\])|[${PKGVERSION_NOREV}]|"
SUBST_FILES.version=	${WRKSRC}/configure.ac

pre-configure:
	(cd ${WRKSRC} && autoreconf)

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
