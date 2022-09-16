# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	roswell-21.10.14.111
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=roswell/}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://github.com/roswell/roswell/
COMMENT=	Lisp implementation installer/manager, launcher, and much more!
LICENSE=	mit


USE_TOOLS+=	automake
GNU_CONFIGURE=	yes


post-extract:
	cd ${WRKSRC} && sh bootstrap


.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
