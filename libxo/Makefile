# $NetBSD$

DISTNAME=	libxo-1.6.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Juniper/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
GITHUB_TYPE=	release

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/libxo
COMMENT=	Library for generating text, XML, JSON, and HTML output
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake perl:run

REPLACE_PERL+=	xolint/xolint.pl

CONFIGURE_ARGS+=	MAKE=gmake

post-install:
	find ${DESTDIR} -type f -name \*.la -delete

.include "../../mk/bsd.pkg.mk"
