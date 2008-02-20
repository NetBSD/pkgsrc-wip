# $NetBSD: Makefile,v 1.4 2008/02/20 03:27:03 netcap Exp $
#

DISTNAME=		stumpwm-0.9.2
#PKGREVISION=		1
CATEGORIES=		wm
DISTFILES=		${DISTNAME}.tgz cl-ppcre.tar.gz
SITES.${DISTNAME}.tgz=	http://download.savannah.nongnu.org/releases/stumpwm/
SITES.cl-ppcre.tar.gz=	http://weitz.de/files/

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://www.nongnu.org/stumpwm/
COMMENT=		Tiling, keyboard driven X11 Window Manager written in Common Lisp

USE_TOOLS+=		autoconf makeinfo install-info
HAS_CONFIGURE=		yes
INFO_FILES=		yes
INSTALL_UNSTRIPPED=	yes

# clisp needs sigsegv, iconv, readline, gettext and esp. X11 bindings:
# PKG_OPTIONS.clisp-current+= new-clx
DEPENDS+=		clisp>=2.42:../../wip/clisp
CONFIGURE_ARGS=		--with-lisp=clisp
CONFIGURE_ARGS+=	--with-ppcre=`basename ${WRKDIR}/cl-ppcre-*`
CONFIGURE_ARGS+=	--with-clisp=${PREFIX}/bin/clisp

pre-configure:
	cd ${WRKSRC} && autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stumpwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stumpwm.info ${PREFIX}/${PKGINFODIR}/stumpwm.info

.include "../../mk/bsd.pkg.mk"
