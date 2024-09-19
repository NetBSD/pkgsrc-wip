# $NetBSD$

DISTNAME=	uperf-1.0.6
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=uperf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.uperf.org/
COMMENT=	Network performance tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	aclocal autoconf automake

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} bootstrap

.include "../../mk/bsd.pkg.mk"
