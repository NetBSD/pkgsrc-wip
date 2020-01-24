# $NetBSD: Makefile,v 1.10 2012/09/24 18:26:55 asau Exp $

DISTNAME=		${PKGNAME}-BlameTheSegfault.src
PKGNAME=		crm114-20070810
CATEGORIES=		mail
# For some reason, later versions are just being placed on the home page
#   MASTER_SITES=		${MASTER_SITE_SOURCEFORGET:=crm114/}
MASTER_SITES=		http://crm114.sourceforge.net/tarballs/

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://crm114.sourceforge.net/
COMMENT=		Fast and accurate learning classifier, good for spam
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		msgfmt

DOCDIR=			${PREFIX}/share/doc/crm114
EMACSDIR=		${PREFIX}/share/emacs/site-lisp
EXAMPLESDIR=		${PREFIX}/share/examples/crm114
SCRIPTSDIR=		${PREFIX}/share/crm114
INSTALLATION_DIRS+=	bin ${DOCDIR} ${EMACSDIR} ${EXAMPLESDIR} ${SCRIPTSDIR}

DOCS=			CRM114_Mailfilter_HOWTO.txt README FAQ.txt INTRO.txt \
			QUICKREF.txt knownbugs.txt
SCRIPTS=		mailfilter.crm maillib.crm mailreaver.crm \
			mailtrainer.crm shuffle.crm pad.crm classifymail.crm \
			rewriteutil.crm
EXAMPLES=		procmailrc.recipe mailfilter.cf blacklist.mfp.example \
			priolist.mfp.example whitelist.mfp.example pad.dat \
			rewrites.mfp

REPLACE_INTERPRETER+=	crm
# NOTE: special case ending .* so as to remove the -(...) flags.
#   These flags reported to cause problems on SunOS and FreeBSD
  REPLACE.crm.old=	.*/bin/crm.*
  REPLACE.crm.new=	${PREFIX}/bin/crm
  REPLACE_FILES.crm=	${SCRIPTS}

SUBST_CLASSES+=		crmdirs
SUBST_STAGE.crmdirs=	pre-configure
SUBST_MESSAGE.crmdirs=	Fixing script references
SUBST_FILES.crmdirs=	${SCRIPTS}
SUBST_VARS.crmdirs=	SCRIPTSDIR

# Several differences will be shown in `make test':
#   * userdirtest.crm: output depends on locale collation ordering
#   * many of the `pR' values differ as a rescaling effort was
#     backed out; these will be corrected for in the next release.
TEST_TARGET=		megatest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crm114 ${PREFIX}/bin/crm
	cd ${WRKSRC} &&							\
	    ${INSTALL_PROGRAM} cssdiff cssmerge cssutil osbf-util	\
		${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${SCRIPTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} crm114-mode.el ${EMACSDIR}

.include "../../devel/tre/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
