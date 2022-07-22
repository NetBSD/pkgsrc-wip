# $NetBSD$

# url2pkg from https://github.com/MerginMaps/geodiff/archive/refs/tags/1.0.6.tar.gz
GITHUB_PROJECT=	geodiff
GITHUB_TAG=	refs/tags/1.0.6
DISTNAME=	1.0.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=MerginMaps/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/MerginMaps/geodiff/
COMMENT=	Diff program for geopackages
LICENSE=	mit

# \todo Do this right; I think this is a C library and then a python
# wrapper and should be two packages.  This is the C one.
BUILD_SUBDIR=	geodiff

#.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
