# $NetBSD: Makefile,v 1.6 2012/09/25 07:47:48 makoto Exp $

DISTNAME=		tc-2.99.1
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		${_SVN_PKGVERSION:S/.//g}
CATEGORIES=		inputmethod

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://openlab.ring.gr.jp/tcode/index.html
COMMENT=		2-stroke non associative direct input for Kanji
# tc is in GPL2, kw is unknown for the moment
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/tcode/tc
INSTALLATION_DIRS=	${EMACS_INFOPREFIX} \
			${EMACS_LISPPREFIX}/${DISTNAME} \
			share/examples/tc

EMACS_MODULES=		base

# Instead of USE_TOOLS+=, avoid to conflict with autoconf
USE_TOOLS=		aclocal automake autoconf gmake
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
SUBST_MESSAGE.tc=	Replacing Perl PATH (@PERL@) to ${PERL5:Q}
SUBST_STAGE.tc=		post-configure
SUBST_FILES.tc+=	bushu-util/bushu2canna
SUBST_FILES.tc+=	bushu-util/where
SUBST_FILES.tc+=	mazegaki/mkcertain.pl
SUBST_SED.tc+=		-e s\|@PERL@\|${PERL5:Q}\|g

# fix hardcoded PATH, interim solution, upstream fix may differ.
# This edit should be applied before byte compile
SUBST_CLASSES+=		tc-pre
SUBST_MESSAGE.tc-pre=	Replacing tc-pre.el PATH /usr/loca/share to ${PREFIX}/share
SUBST_STAGE.tc-pre=	pre-configure
SUBST_FILES.tc-pre+=	lisp/tc-pre.el
SUBST_SED.tc-pre+=	-e s\|/usr/local/share\|${PREFIX}/share\|g

.include "options.mk"

pre-configure:
		( cd ${WRKSRC} && \
		aclocal ;\
		automake --add-missing; \
		autoconf ; \
		)
# To avoid byte-compile error 'Invalid syntax ?', convert EUC-JP to UTF-8
# Just one file is to be converted now,
.if !empty(EMACS_TYPE:Memacs23) || !empty(EMACS_TYPE:Memacs24) || !empty(EMACS_TYPE:Memacs25)
post-patch:
	(cd ${WRKSRC}/lisp; \
	for i in tc-bushu.el;  \
	do ${MV} $$i $$i.bak; \
	iconv -f euc-jp -t utf-8 < $$i.bak >$$i ; \
	done )
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README    		${DESTDIR}${PREFIX}/share/tc/README.euc
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf	${DESTDIR}${PREFIX}/share/tc
	${INSTALL_DATA} ${WRKSRC}/doc/sample.tc 	${DESTDIR}${PREFIX}/share/examples/tc

.include "../../editors/emacs/modules.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
