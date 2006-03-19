# $NetBSD: Makefile,v 1.1.1.1 2006/03/19 13:32:41 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=		mecab-${MECAB_VERSION}
PKGNAME=		mecab-base-${MECAB_VERSION}
CATEGORIES=		japanese textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=mecab/19392/}

MAINTAINER=		obata@lins.jp
HOMEPAGE=		http://mecab.sourceforge.jp/
COMMENT=		Yet Another Part-of-Speech and Morphological Analyzer

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
OWN_DIRS=		${PREFIX:Q}/lib/mecab/dic

CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

REPLACE_PERL+=		libexec/mecab-cost-train libexec/mecab-dict-info \
			libexec/mecab-dict-gen libexec/mecab-system-eval \
			libexec/mecab-dict-index libexec/mecab-test-gen

EGDIR=			${PREFIX}/share/examples/mecab
CONF_FILES=		${EGDIR:Q}/mecabrc ${PKG_SYSCONFDIR:Q}/mecabrc

SUBST_CLASSES+=		confdir
SUBST_STAGE.confdir=	pre-configure
SUBST_FILES.confdir=	Makefile.in
SUBST_SED.confdir=	-e "s,\$$(sysconfdir),${EGDIR},"

SUBST_CLASSES+=		rpaths
SUBST_STAGE.rpaths=	pre-configure
SUBST_FILES.rpaths=	mecab-config.in
SUBST_SED.rpaths=	-e '/echo[ 	]*-L/s|-L\([ 	]*[^ 	]*\)|${COMPILER_RPATH_FLAG}\1 -L\1|g'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
