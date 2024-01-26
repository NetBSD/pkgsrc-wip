# $NetBSD$

COMMITS=	225
DISTNAME=	sonic-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=waywardgeek/}
GITHUB_TAG=	8694c596378c24e340c09ff2cd47c065494233f1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/waywardgeek/sonic
COMMENT=	Simple library to speed up or slow down speech
LICENSE=	apache-2.0

USE_LANGUAGES=		c
USE_TOOLS=		gmake
CFLAGS+=		-Wall -O3 -Wno-unused-function -ansi -fPIC -pthread
CFLAGS+=		-Wl,-rpath=${PREFIX}/lib
MAKE_FLAGS=		PACKAGING=YES
CHECK_SHLIBS_SKIP=	bin/sonic

.include "../../mk/bsd.pkg.mk"
