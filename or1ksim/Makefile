# $NetBSD: Makefile,v 1.9 2013/10/14 13:00:04 ryo-on Exp $
#

VER=		0.5.1rc1
DISTNAME=	or1ksim-or1ksim-${VER}
PKGNAME=	${DISTNAME:S/or1ksim-or1ksim-/or1ksim-/}
CATEGORIES=	emulators
MASTER_SITES=	-https://github.com/openrisc/or1ksim/archive/or1ksim-${VER}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencores.org/or1k/Or1ksim
COMMENT=	OpenRISC emulator

FETCH_USING=	curl

USE_TOOLS+=	gmake

INFO_FILES=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+=	--target=or32

# rl_event_hook
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
