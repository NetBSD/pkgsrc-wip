# $NetBSD$

DISTNAME=	cpuminer-multi-1.3.5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=tpruvot/}
GITHUB_PROJECT=	cpuminer-multi
GITHUB_TAG=	v${PKGVERSION_NOREV}-multi

MAINTAINER=	izaac@setec.org
HOMEPAGE=	https://github.com/tpruvot/cpuminer-multi
COMMENT=	multi-threaded CPU miner
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf autoheader automake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-crypto --with-curl

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
