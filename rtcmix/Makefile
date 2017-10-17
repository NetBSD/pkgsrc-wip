# $NetBSD$

DISTNAME=	RTcmix-4.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=RTcmix/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org	
HOMEPAGE=	http://rtcmix.org
COMMENT=	Open-source digital signal processing and sound synthesis language
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
# Html documentation and man pages are incomplete.
# http://rtcmix.org/reference/
#CONFIGURE_ARGS+= --htmldir=${PREFIX}/share/doc/${PKGBASE}/html
CONFIGURE_ARGS+= --libdir=${PREFIX}/lib/${PKGBASE}
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake autoconf perl

pre-configure:
	cd ${WRKSRC} && autoconf
	
.include "../../mk/bsd.pkg.mk"
