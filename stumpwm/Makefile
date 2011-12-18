# $NetBSD: Makefile,v 1.7 2011/12/18 18:06:16 dukzcry Exp $
#

DISTNAME=		stumpwm-0.9.7
CATEGORIES=		wm
DISTFILES=		${DISTNAME}.tgz
SITES.${DISTNAME}.tgz=	http://download.savannah.nongnu.org/releases/stumpwm/

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://www.nongnu.org/stumpwm/
COMMENT=		Tiling, keyboard driven X11 Window Manager written in Common Lisp
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		autoconf makeinfo install-info
INSTALLATION_DIRS+=	bin ${PKGINFODIR}
HAS_CONFIGURE=		yes
INFO_FILES=		yes
INSTALL_UNSTRIPPED=	yes
# clisp-core target, until CLISP 2.50 release
USE_GNU_READLINE=	yes

## Why CLISP?
# 1) No needance to tune the prealloc heap, like with SBCL, or with CCL on 64bit platforms;
# 2) No needance to build with threads disabled like with SBCL.
#	CLISP threads support is still experimental and not enabled by default;
# 3) Wide arch support, although no native machine code generation (only byte-code, JIT).

# X11 bindings
BUILD_DEPENDS+=		clisp-new-clx>=2.42:../../x11/clisp-new-clx
## Use ppcre supplied with Stumpwm distfile tarball for now
#DEPENDS_TARGET+=	PKG_OPTIONS.cl-ppcre=clisp install clean-depends clean	# Ugly! Correct me
#BUILD_DEPENDS+=	clisp-ppcre:../../wip/cl-ppcre
#CONFIGURE_ARGS=	--with-ppcre=${PREFIX}/lib/clisp/cl-ppcre
CONFIGURE_ARGS=		--with-lisp=clisp
CONFIGURE_ARGS+=	--with-clisp=${PREFIX}/bin/clisp

pre-configure:
	cd ${WRKSRC} && autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stumpwm ${DESTDIR}${PREFIX}/bin/stumpwm
	${INSTALL_MAN} ${WRKSRC}/stumpwm.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/stumpwm.info

# clisp-core target
.include "../../wip/mk/clisp-temp.mk"

.include "../../mk/bsd.pkg.mk"
