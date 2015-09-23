# $NetBSD$

DISTNAME=	opendylan-2014.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylan-lang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_TOOLS+=	autoconf automake autoreconf perl gmake

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=dylan-lang/opendylan/}
COMMENT=	Multi-paradigm functional and OO programming language
#LICENSE=	# TODO: (see mk/license.mk)
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
