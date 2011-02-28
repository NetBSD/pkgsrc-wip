# $NetBSD: Makefile,v 1.2 2011/02/28 14:53:18 thomasklausner Exp $
#

DISTNAME=	zsh-${ZSH_SNAP_DATE}
CATEGORIES=	shells
MASTER_SITES=	http://dfn.dl.sourceforge.net/sourceforce/zsh/
EXTRACT_SUFX=	.tar.bz2

ZSH_SNAP_DATE=	20080908

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zsh.org
COMMENT=	Z Shell (development version)

BUILD_DEPENDS+=		yodl-[0-9]*:../../textproc/yodl

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		makeinfo
USE_TOOLS+=		autoconf automake

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

PKG_SYSCONFSUBDIR=	${PKGBASE}

ZSH_DATADIR=		${PREFIX}/share/zsh
ZSH_SITEFNDIR?=		${ZSH_DATADIR}/site-functions
ZSH_FNDIR?=		${ZSH_DATADIR}/${PKGNAME_NOREV}/functions

CONFIGURE_ARGS+=	--enable-function-subdirs
CONFIGURE_ARGS+=	--enable-site-fndir=${ZSH_SITEFNDIR:Q}
CONFIGURE_ARGS+=	--enable-fndir=${ZSH_FNDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
CONFIGURE_ARGS+=	--without-tcsetpgrp
.else
CONFIGURE_ARGS+=	--with-tcsetpgrp
.endif

.include "options.mk"

.if !exists(${WRKDIR}/.preconfig-done)
pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ${WRKSRC}/Util/preconfig && \
		${TOUCH} ${TOUCH_FLAGS} ${WRKDIR}/.preconfig-done
.endif

.include "../../mk/termcap.buildlink3.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
