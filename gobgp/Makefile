# $NetBSD$

DISTNAME=	gobgp-4.9.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=osrg/}
GITHUB_PROJECT=	gobgp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/osrg/gobgp/
COMMENT=	GoBGP: BGP implementation in Go
LICENSE=	apache-2.0

USE_LANGUAGES=	c

# config is to common filename, rename to gobgp-config
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/config \
		${DESTDIR}${PREFIX}/bin/gobgp-config

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
