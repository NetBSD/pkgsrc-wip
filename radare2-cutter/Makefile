# $NetBSD$

.include "../../devel/radare2/Makefile.common"

DISTNAME=	cutter-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radareorg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/radareorg/cutter/
COMMENT=	Qt and C++ GUI for radare2 reverse engineering framework
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

#post-extract:
#	${RUN} cd ${WRKSRC} && \
#		rmdir radare2 &&
#

.include "../../mk/bsd.pkg.mk"
