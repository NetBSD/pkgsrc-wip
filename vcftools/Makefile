# $NetBSD$

DISTNAME=	vcftools_${DISTVERSION}
PKGNAME=	vcftools-${DISTVERSION}
DISTVERSION=	0.1.16
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcftools/}
GITHUB_TAG=	v${DISTVERSION}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/vcftools/vcftools
COMMENT=	Tools for working with VCF genomics files
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf gmake perl pkg-config
GNU_CONFIGURE=	yes
REPLACE_PERL=	src/perl/*

CONFIGURE_ARGS+=	--with-pmdir=${PERL5_INSTALLVENDORLIB:S|^${PREFIX}/||}/vcftools

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/vars.mk"
.include "../../mk/bsd.pkg.mk"
