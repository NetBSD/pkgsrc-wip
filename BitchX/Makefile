# $NetBSD: Makefile,v 1.4 2013/06/13 09:51:05 noud4 Exp $

DISTNAME=	BitchX-1.2-final
PKGNAME=	bitchx-1.2 # XXX ${DISTNAME:S|-final||:LC}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.bitchx.ca/

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

# This package is not even remotely 64-bit clean
NOT_FOR_PLATFORM=	${LP64PLATFORMS}

USE_TOOLS+=	bash

WRKSRC=			${WRKDIR}/${DISTNAME:S|-final||}
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-plugins
CONFIG_SHELL=		${TOOLS_PATH.bash}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CFLAGS+=	-DBIND_8_COMPAT
.endif

SUBST_CLASSES+=		manpage
SUBST_STAGE.manpage=	post-patch
SUBST_FILES.manpage+=	doc/BitchX.1
SUBST_SED.manpage+=	-e 's,@PREFIX@,${PREFIX},g'

INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
