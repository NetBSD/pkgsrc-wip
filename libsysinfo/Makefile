# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Mon Jan 20 10:37:16 CST 2025               #
###########################################################

DISTNAME=	libsysinfo-0.0.3
PKGNAME=	${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsdimp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/bsdimp/libsysinfo
COMMENT=	GNU libc's sysinfo port for \${OPSYS}
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM+=	FreeBSD-*-*

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_SED.man+=		-e 's|man/man|${PKGMANDIR}/man|g'
SUBST_FILES.man+=	${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
