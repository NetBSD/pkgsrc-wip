# $NetBSD$

GITHUB_PROJECT=	flag
GITHUB_TAG=	0.1
DISTNAME=	0.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
MASTER_SITES=   ${MASTER_SITE_GITHUB:=cirnatdan/}
DIST_SUBDIR=    ${GITHUB_PROJECT}
CATEGORIES=	pkgtools

MAINTAINER=	dan@alt.md
HOMEPAGE=	http://github.com/cirnatdan/flag
COMMENT=	Frontend/wrapper for pkgsrc 
LICENSE=	modified-bsd

BUILD_TARGET=	all
USE_LANGUAGES=	c

USE_BSD_MAKEFILE=	yes
INSTALLATION_DIRS+=     bin

.include "../../mk/bsd.pkg.mk"
