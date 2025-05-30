# $NetBSD: Makefile,v 1.7 2014/02/23 15:34:48 makoto Exp $

DISTNAME=		tc-2.99.3
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
MASTER_SITES=		${MASTER_SITE_GITHUB:=makoto-fujiwara/}
CATEGORIES=		inputmethod
PKGREVISION=		1

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://openlab.ring.gr.jp/tcode/index.html
COMMENT=		2-stroke non associative direct input for Kanji
# tc is in GPL2, kw is unknown for the moment
LICENSE=		gnu-gpl-v2

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} \
			${EMACS_LISPPREFIX}/${DISTNAME} \
			share/examples/tc

EMACS_MODULES=		base

# Instead of USE_TOOLS+=, avoid to conflict with autoconf
USE_TOOLS=		aclocal automake autoconf gmake makeinfo
GNU_CONFIGURE=		YES
TOOL_DEPENDS+=		web2c-[0-9]*:../../print/web2c

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}

MAKEFLAGS+=		EMACS=${EMACS_BIN}
MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX}
INFO_FILES=		YES

# fatal: unable to access 'http://github.com/kanchoku/tc.git/': SSL certificate problem: unable to get local issuer certificate
# Add "-c http.sslVerify=false" to git command or,
#PKGSRC_SETENV=		GIT_SSL_NO_VERIFY=true
## With some condition, it pauses waiting for interaction:
## Saving file /WRKOBJDIR/wip/tc-git/work/tc/etc/bushu.rev...

#  For the target in etc/Makefile ->  bushu.expand bushu.index2: bushu.rev $(BATCH_SORT)
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}/${DISTNAME}
CONFIGURE_ARGS.emacs+=	--datadir=${PREFIX}/share

#.include "options.mk"
PLIST_SUBST+=		DISTNAME=${DISTNAME}

REPLACE_PERL+=		bushu-util/bushu2canna
REPLACE_PERL+=		bushu-util/where
REPLACE_PERL+=		mazegaki/mkcertain.pl

# fix hardcoded PATH, interim solution, upstream fix may differ.
# This edit should be applied before byte compile
SUBST_CLASSES+=		tc-pre
SUBST_MESSAGE.tc-pre=	Replacing tc-pre.el PATH /usr/loca/share to ${PREFIX}/share
SUBST_STAGE.tc-pre=	pre-configure
SUBST_FILES.tc-pre+=	lisp/tc-pre.el
SUBST_SED.tc-pre+=	-e s\|/usr/local/share\|${PREFIX}/share\|g

SUBST_CLASSES+=		texinfo
SUBST_MESSAGE.texinfo=	Fix problem: /usr/pkgsrc/wip/tc-git/work/tc/doc/-I does not exist!
SUBST_STAGE.texinfo=	post-configure
SUBST_FILES.texinfo=	doc/Makefile
SUBST_SED.texinfo=	-e '/$$(MAKEINFO) $$(AM_MAKEINFOFLAGS) $$(MAKEINFOFLAGS) -I $$(srcdir)/s/-I $$(srcdir)/ -I. tc.texinfo ; echo disable following line /'

# string-to-int to string-to-number
SUBST_CLASSES+=		s2i
SUBST_MESSAGE.s2i=	string-to-int is an obsolete function; use `string-to-number' instead
SUBST_STAGE.s2i=	post-patch
SUBST_FILES.s2i=	lisp/eelll.el lisp/tc-is22.el lisp/tc-is20.el lisp/tc-is19.el lisp/tc-pre.el
SUBST_SED.s2i=		-e s/string-to-int/string-to-number/g

SUBST_CLASSES+=		l2e
SUBST_MESSAGE.l2e=	last-command-char is an obsolete function; use `last-command-event' instead
SUBST_STAGE.l2e=	post-patch
SUBST_FILES.l2e=	\
			lisp/tc-ja-alnum.el \
			lisp/tc-mazegaki.el \
			lisp/tc-util.el \
			lisp/tc-is22.el \
			lisp/tc-is20.el \
			lisp/tc-is19.el
SUBST_SED.l2e=		-e s/last-command-char/last-command-event/g

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && aclocal && automake --add-missing && autoconf

# To avoid byte-compile error 'Invalid syntax ?', convert EUC-JP to UTF-8
# Just one file is to be converted now,
.if (${EMACS_TYPE} == emacs25) || \
    (${EMACS_TYPE} == emacs26)
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
.include "../../mk/bsd.pkg.mk"
