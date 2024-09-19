# $NetBSD$

DISTNAME=	otrtool-1.2.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=otrtool/}
GITHUB_PROJECT=	otrtool
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dominik.muth@gmx.de
HOMEPAGE=	https://github.com/otrtool/otrtool/
COMMENT=	Decrypter for videos (otrkey) from onlinetvrecorder.com
LICENSE=	cc0-1.0-universal

BUILD_MAKE_FLAGS+=	VERSION=${GITHUB_TAG}-pkgsrc

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
