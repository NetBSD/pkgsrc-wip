# $NetBSD$

DISTNAME=	libcanlock-3.0.1
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael.baeuerle@gmx.net
HOMEPAGE=	http://micha.freeshell.org/libcanlock/
COMMENT=	Standalone RFC 8315 Netnews Cancel-Lock implementation
LICENSE=	mit AND modified-bsd

USE_LANGUAGES+=	c99

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	test

# Disable obsolete Version 2 API
SUBST_CLASSES+=			edit-header
SUBST_STAGE.edit-header=	post-patch
SUBST_MESSAGE.edit-header=	Prepare header file
SUBST_FILES.edit-header=	include/canlock.h
SUBST_SED.edit-header=		-e 's,CL_API_V2  1,CL_API_V2  0,g'

.include "../../mk/bsd.pkg.mk"
