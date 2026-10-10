# $NetBSD$

DISTNAME=	roswell-26.02.116
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=roswell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/roswell/roswell/
COMMENT=	Common Lisp environemnt setup utility
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	automake
GNU_CONFIGURE=	yes


post-extract:
	cd ${WRKSRC} && sh bootstrap


.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
