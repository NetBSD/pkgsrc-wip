# $NetBSD: Makefile,v 1.1.1.1 2008/01/07 10:27:57 netcap Exp $
#

DISTNAME=		${PKGNAME}-git080103
PKGNAME=		stumpwm-0.0.6
#PKGREVISION=		1
CATEGORIES=		wm
MASTER_SITES=		http://jfranz.users.bsdprojects.net/distfiles/
DISTFILES+=		${DISTNAME}.tar.gz cl-ppcre.tar.gz # vanilla snapshots

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://www.nongnu.org/stumpwm/
COMMENT=		Tiling, keyboard driven X11 Window Manager written in Common Lisp

# If you enounter problems, check that CLISP is build with
# sigsegv, iconv, readline, gettext and esp. X11 bindings:
# PKG_OPTIONS.clisp-current+= new-clx
# We use the CVS snapshot in wip until lang/clisp has been updated.
# Eventually, we'll package new-clx and cl-ppcre seperately and use asdf.
DEPENDS+=		clisp>=2.42:../../wip/clisp-current

USE_TOOLS+=		autoconf makeinfo install-info
HAS_CONFIGURE=		yes
INFO_FILES=		yes
CONFIGURE_ARGS+=	--with-lisp=clisp --with-clisp=${PREFIX}/bin/clisp
INSTALL_UNSTRIPPED=	yes

SUBST_CLASSES+=		wrksrc
SUBST_MESSAGE.wrksrc=	"Fixing cl-ppcre distdir."
SUBST_STAGE.wrksrc=	post-patch
SUBST_FILES.wrksrc=	make-image.lisp
SUBST_SED.wrksrc=	-e 's|%PPCRE_WRKSRC%|${WRKDIR}/cl-ppcre-1.3.2/|g'

pre-configure:
	cd ${WRKSRC} && autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stumpwm ${PREFIX}/bin
	${INSTALL_INFO} ${WRKSRC}/stumpwm.info ${PREFIX}/${PKGINFODIR}/stumpwm.info

.include "../../mk/bsd.pkg.mk"
