# $NetBSD: Makefile,v 1.34 2024/01/14 08:41:57 wiz Exp $

DISTNAME=	nickle-2.103
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

TEST_TARGET=	check

REPLACE_SH+=	bench/runbench.sh

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
#MESON_ARGS+=	-Dlibedit=true
# does support editline, but only with a pkg-config file, which pkgsrc
# does not provide
#.include "../../mk/readline.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
