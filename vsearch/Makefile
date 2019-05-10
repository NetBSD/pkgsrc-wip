# $NetBSD$

DISTNAME=	vsearch-2.13.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=torognes/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/torognes/vsearch
COMMENT=	Versatile open-source tool for metagenomics
LICENSE=	gnu-gpl-v3

# Works on powerpc64, but only in little endian mode
ONLY_FOR_PLATFORM=	*-*-aarch64 *-*-x86_64

USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake autoreconf gmake
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
