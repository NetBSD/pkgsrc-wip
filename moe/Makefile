# $NetBSD: Makefile,v 1.18 2015/05/08 20:18:18 gschwarz Exp $

DISTNAME=	moe-1.9
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=moe/}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/moe/moe.html
COMMENT=	Moe Editor - A powerful and user-friendly text editor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_GNU_CONFIGURE_HOST=	NO
INFO_FILES=		YES
MAKE_ENV+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_ENV+=		INSTALL_MAN=${INSTALL_MAN:Q}
MAKE_ENV+=		INSTALL_DIR=${MKDIR:Q}
LDFLAGS+=		${BUILDLINK_LDADD.ncurses:Q}
USE_LANGUAGES=		c++

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# cf. https://lists.gnu.org/archive/html/bug-moe/2017-09/msg00000.html
SUBST_CLASSES+= clang
SUBST_STAGE.clang=	post-patch
SUBST_FILES.clang=	window_vector.cc
SUBST_MESSAGE.clang=	fixing code for clang incompatiblity
SUBST_SED.clang=	-e "s/, 1, /, 1U, /"
.endif

CONF_FILES=		${PREFIX}/share/examples/moe/moerc \
			${PKG_SYSCONFDIR}/moerc
INSTALL_TARGET=		install install-man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGINFODIR} share/examples/moe

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
