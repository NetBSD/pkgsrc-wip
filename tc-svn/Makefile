# $NetBSD: Makefile,v 1.1.1.1 2011/05/23 13:37:52 makoto Exp $

DISTNAME=		tc-2.3.1
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		${_SVN_PKGVERSION:S/.//g}

CATEGORIES=		inputmethod

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://openlab.ring.gr.jp/tcode/index.html
COMMENT=		2-stroke non associative direct input for Kanji
# tc is in GPL2, kw is unknown for the moment
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/tcode/tc
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${EMACS_INFOPREFIX} \
			${EMACS_LISPPREFIX}/${DISTNAME} \
			share/examples/tc

EMACS_MODULES=		base

# Instead of USE_TOOLS+=, avoid to conflict with autoconf
USE_TOOLS=		aclocal automake14 autoconf213 gmake
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}

MAKEFLAGS+=		EMACS=${EMACS_BIN:Q}
MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INFO_FILES=		YES

SVN_ROOT.tcode=		http://tcode.googlecode.com/svn/trunk/
SVN_REPOSITORIES=	tcode

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}/${DISTNAME}
CONFIGURE_ARGS.emacs+=	--datadir=${PREFIX}/share

#.include "options.mk"
PLIST_SUBST+=		DISTNAME=${DISTNAME}

SUBST_CLASSES+=		tc
SUBST_STAGE.tc=		post-configure
SUBST_FILES.tc+=	bushu-util/bushu2canna
SUBST_FILES.tc+=	bushu-util/where
SUBST_FILES.tc+=	mazegaki/mkcertain.pl
SUBST_SED.tc+=		-e s\|@PERL@\|${PERL5:Q}\|g

##BUILD_DEPENDS+=		automake14

.include "options.mk"

pre-configure:
		( cd ${WRKSRC} && \
		aclocal ;\
		automake-1.4 --add-missing; \
		autoconf ; \
		)

post-install:
	${INSTALL_DATA} ${WRKSRC}/README    		${DESTDIR}${PREFIX}/share/tc/README.euc
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf	${DESTDIR}${PREFIX}/share/tc
	${INSTALL_DATA} ${WRKSRC}/doc/sample.tc 	${DESTDIR}${PREFIX}/share/examples/tc

.include "../../editors/emacs/modules.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
