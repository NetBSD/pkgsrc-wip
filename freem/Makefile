# $NetBSD$

DISTNAME=		freem-0.62.3
PKGREVISION=		6
CATEGORIES=		lang
MASTER_SITES=		https://freem.coherent-logic.com/downloads/

MAINTAINER=		snw@coherent-logic.com
HOMEPAGE=		https://freem.coherent-logic.com/
COMMENT=		Implementation of the MUMPS programming language and database
LICENSE=		gnu-agpl-v3

USERGROUP_PHASE=	pre-install
INSTALL_UNSTRIPPED=	yes
MAKE_DIRS+=		${VARBASE}/freem/home
MAKE_DIRS_PERMS+=	${VARBASE}/freem/home freem freem 0770
PKG_HOME.freem=		${VARBASE}/freem/home
PKG_GROUPS=		freem
PKG_USERS=		freem:freem
RCD_SCRIPTS=		freem
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} CFLAGS=-ggdb


.include "../../mk/bsd.pkg.mk"
.include "../../devel/readline/buildlink3.mk"
