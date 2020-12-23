# $NetBSD$

DISTNAME=	libcyaml-1.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlsa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dressupgeekout@gmail.com
COMMENT=	Schema-based YAML parsing and serialization
LICENSE=	isc

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++

USE_TOOLS+=		gmake
NO_CONFIGURE=		yes

# The Makefile wants to add a bunch of options to install(1) specific to GNU
# install(1) -- disable those right here.
INSTALL_MAKE_FLAGS+=	INSTALL="install"

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
