# $NetBSD$

DISTNAME=	libpll-src-0.3.2
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=xflouris/}
GITHUB_PROJECT=	libpll
GITHUB_RELEASE=	0.3.2

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://github.com/xflouris/libpll/
COMMENT=	High-performance software library for phylogenetic analysis
LICENSE=	gnu-agpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	bison flex

.include "../../mk/bsd.pkg.mk"
