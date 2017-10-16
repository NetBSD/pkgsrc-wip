# $NetBSD$

GITHUB_PROJECT=	RTcmix
DISTNAME=	v4.2.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	local
MASTER_SITES=	${MASTER_SITE_GITHUB:=RTcmix/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org	
HOMEPAGE=	http://rtcmix.org
COMMENT=	An open-source digital signal processing and sound synthesis language
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/RTcmix-4.2.0
GNU_CONFIGURE=	yes
# Html documentation and man pages are incomplete.
# http://rtcmix.org/reference/
#CONFIGURE_ARGS+= --htmldir=${PREFIX}/share/doc/${PKGBASE}/html
CONFIGURE_ARGS+= --libdir=${PREFIX}/lib/${PKGBASE}
USE_LANGUAGES=	c c++
USE_TOOLS= gmake autoconf perl

pre-configure:
	cd ${WRKSRC} && autoconf
	
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
