# $NetBSD$

DISTNAME=		devkitARM-buildrules-45
CATEGORIES=		cross

MASTER_SITES=	${MASTER_SITE_GITHUB:=devkitPro/}
GITHUB_PROJECT=	buildscripts
GITHUB_TAG=	v20151213

MAINTAINER=	js@heap.zone
HOMEPAGE=	http://devkitpro.org/
COMMENT=	Build rules for devkitARM
# They currently don't have a license:
# https://github.com/devkitPro/buildscripts/issues/20
LICENSE=	devkitpro-license

WRKSRC=		${WRKDIR}/buildscripts-${GITHUB_TAG:S/v//}/dkarm-eabi
NO_BUILD=	yes

AUTO_MKDIRS=		yes

do-install:
.for i in 3ds_rules base_rules base_tools ds_rules gba_rules gp32_rules
	cp ${WRKSRC}/rules/$i ${DESTDIR}${PREFIX}/devkitpro/devkitARM/
.endfor

.include "../../mk/bsd.pkg.mk"
