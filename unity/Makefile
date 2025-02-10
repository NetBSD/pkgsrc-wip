# $NetBSD$

DISTNAME=	unity-2.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ThrowTheSwitch/}
GITHUB_PROJECT=	Unity
GITHUB_TAG=	v${PKGVERSION_NOREV}

OWNER=		micha@NetBSD.org
HOMEPAGE=	https://www.throwtheswitch.org/unity
COMMENT=	Unit testing framework built for C
LICENSE=	mit

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99

MUON_ARGS+=		-Dc_std=c99
MUON_ARGS+=		-Dwerror=false

# Set package version (without python)
SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Insert version into meson.build file ...
SUBST_FILES.version=	meson.build
SUBST_VARS.version=	PKGVERSION_NOREV

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/unity.pc

.include "../../devel/muon/build.mk"
.include "../../mk/bsd.pkg.mk"
