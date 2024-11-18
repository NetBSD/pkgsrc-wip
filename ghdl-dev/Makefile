# $NetBSD$

GITHUB_PROJECT=	ghdl
GITHUB_TAG=	f1de234f5e77eb8fb765da945a0bf34ec4abb864
DISTNAME=	f1de234f5e77eb8fb765da945a0bf34ec4abb864
PKGNAME=	${GITHUB_PROJECT}-dev-5.0.0.9655
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghdl/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ghdl/ghdl/
COMMENT=	Open-source simulator/compiler/analyzer for VHDL
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
TOOL_DEPENDS+=	gcc10-aux-[0-9]*:../../lang/gcc10-aux
REPLACE_BASH=	scripts/vendors/*.sh

RELRO_SUPPORTED=	no
MKPIE_SUPPORTED=	no

CONFIGURE_ENV+=		GNATMAKE=${PREFIX}/gcc10-aux/bin/gnatmake
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-synth
CONFIGURE_ARGS+=	--enable-libghdl

.include "../../mk/bsd.pkg.mk"
