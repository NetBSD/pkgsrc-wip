# $NetBSD$

GITHUB_PROJECT=	openfmod
GITHUB_TAG=	04e63e9b0ba1562db32570a0a7b68030c289dd89
DISTNAME=	04e63e9b0ba1562db32570a0a7b68030c289dd89
PKGNAME=	${GITHUB_PROJECT}-0.0.20201109
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=moon-chilled/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/moon-chilled/openfmod/
COMMENT=	Partial reimplementation of FMOD audio library
LICENSE=	mit

WRKSRC=	${WRKDIR}/openfmod-04e63e9b0ba1562db32570a0a7b68030c289dd89

MAKE_FILE=	makefile
BUILD_TARGET=	default

INSTALLATION_DIRS+=	lib

.include "../../textproc/jansson/buildlink3.mk"
.include "../../wip/gorilla-audio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
