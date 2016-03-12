# $NetBSD$

DISTNAME=	otrtool-1.2.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=otrtool/}
GITHUB_PROJECT=	otrtool
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	Decrypter for videos (otrkey) from onlinetvrecorder.com
HOMEPAGE=	${MASTER_SITE_GITHUB:=otrtool/otrtool/}
MAINTAINER=	dominik.muth@gmx.de
LICENSE=	cc0-1.0-universal

BUILD_MAKE_FLAGS+=	VERSION=${GITHUB_TAG}-pkgsrc

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
