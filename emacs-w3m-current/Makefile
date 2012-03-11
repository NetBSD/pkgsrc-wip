# $NetBSD: Makefile,v 1.10 2012/03/11 02:18:22 makoto Exp $

DISTNAME=	emacs-w3m-1.4.50
PKGNAME=	emacs-w3m-1.4.50
CATEGORIES=	www
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	Emacs frontend for w3m browser
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${ETCDIR}
# the name is slightly different for now, so put. (Shall I?)
# CONFLICTS+=	emacs-w3m-[0-9]*

USE_TOOLS+=	makeinfo gzip autoconf
INFO_FILES=	YES

DEPENDS+=	w3m{,-img}>=0.5.1nb2:../../www/w3m

CVS_REPOSITORIES=	emacs-w3m
CVS_ROOT.emacs-w3m=	:pserver:anonymous:@cvs.namazu.org:/storage/cvsroot

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN}
CONFIGURE_ARGS+=--with-icondir=${ICONDIR}
CONFIGURE_ARGS+=--infodir=${PREFIX}/info
BUILD_TARGET=	default
INSTALL_TARGET=		install install-icons install-icons30
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN}

WRKSRC=			${WRKDIR}/emacs-w3m

PLIST_SUBST+=		ETCDIR=${ETCDIR}

SUBST_CLASSES+=	fix-icondir
SUBST_STAGE.fix-icondir=	pre-configure
SUBST_FILES.fix-icondir=	Makefile.in w3m.el w3mhack.el
SUBST_SED.fix-icondir=		-e 's|etc/images/w3m|etc/w3m|g'
SUBST_SED.fix-icondir+=		-e 's|images/w3m|w3m|g'

EMACS_BUILDLINK=
EMACS_VERSIONS_ACCEPTED=	emacs22 emacs22nox emacs21 emacs21nox emacs20 \
				xemacs215 xemacs214 \
				emacs23 emacs24 

EVAL_PREFIX+=		W3MPREFIX=w3m

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	w3m.el
SUBST_SED.paths+=	-e 's,@W3MPREFIX@,${W3MPREFIX},g'
SUBST_STAGE.paths=	pre-configure

.include "../../editors/emacs/modules.mk"
BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

# GNU Emacs 21 or later and XEmacs have GUI support
PLIST_VARS+=	gui
.if (${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} > 20) || \
    ${EMACS_FLAVOR} == "xemacs"
PLIST.gui=	yes
.endif

DOCUMENTS=	COPYING ChangeLog ChangeLog.1 README README.ja
ETCDIR=		${ETCDIR.${EMACS_FLAVOR}}
ICONDIR=	${PREFIX}/${ETCDIR}

INSTALL_TARGET.emacs=	install install-icons
INSTALL_TARGET.xemacs=	install-package
ETCDIR.emacs=		share/emacs/${_EMACS_VERSION_MAJOR}/etc/w3m
ETCDIR.xemacs=		lib/xemacs/site-packages/etc/w3m

PLIST_SRC+=		PLIST


pre-configure:
	(set -e; cd ${WRKSRC} ; autoconf)

post-install:
	set -e; \
	for f in ${DOCUMENTS}; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/${ETCDIR}; \
	done

.include "options.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../devel/flim/buildlink3.mk"
.include "../../editors/mule-ucs/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
