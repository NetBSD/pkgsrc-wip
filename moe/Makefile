# $NetBSD: Makefile,v 1.2 2005/11/28 00:27:26 rillig Exp $

DISTNAME=	moe-0.5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=moe/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/moe/moe.html
COMMENT=	Moe Editor - A powerful and user-friendly text editor

GNU_CONFIGURE=	YES
USE_GNU_CONFIGURE_HOST=	NO
INFO_FILES=		moe.info
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/moe
MAKE_ENV+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_ENV+=		INSTALL_MAN=${INSTALL_MAN:Q}
USE_LANGUAGES=	c++

CONF_FILES=		${PREFIX}/share/examples/moe/moerc \
			${PKG_SYSCONFDIR}/moerc
USE_PKGINSTALL=		YES

INSTALL_TARGET=		install install-man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 info share/examples/moe

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
