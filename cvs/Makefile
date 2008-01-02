# $NetBSD: Makefile,v 1.1.1.1 2008/01/02 11:38:48 marttikuparinen Exp $

DISTNAME=		cvs-${VER}
CATEGORIES=		devel
MASTER_SITES=		http://ftp.gnu.org/non-gnu/cvs/source/stable/${VER}/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/cvs/cvs.html
COMMENT=		Concurrent Versions System

VER=			1.11.22

GNU_CONFIGURE=		yes

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-build
SUBST_MESSAGE.perl=	Fixing path to perl
SUBST_FILES.perl+=	contrib/check_cvs
SUBST_FILES.perl+=	contrib/clmerge
SUBST_FILES.perl+=	contrib/cln_hist
SUBST_FILES.perl+=	contrib/commit_prep
SUBST_FILES.perl+=	contrib/cvs_acls
SUBST_FILES.perl+=	contrib/log
SUBST_FILES.perl+=	contrib/log_accum
SUBST_FILES.perl+=	contrib/mfpipe
SUBST_FILES.perl+=	contrib/pvcs2rcs
SUBST_FILES.perl+=	contrib/rcslock
SUBST_SED.perl=		-e "s|${TOOLS_CMD.perl}|${PERL5}|"

.include "../../mk/bsd.pkg.mk"
