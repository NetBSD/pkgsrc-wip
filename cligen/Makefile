# $NetBSD$

DISTNAME=	cligen-7.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=clicon/}
GITHUB_PROJECT=	cligen
DISTFILES=	${PKGNAME_NOREV}.tar.gz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://www.cligen.se/
COMMENT=	Tool to generate interactive command-line interfaces
LICENSE=	apache-2.0 OR gnu-gpl-v2

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
#USE_LIBTOOL=	yes

USE_TOOLS+=	gmake bison flex autoconf

# Could in principle be an option:
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
