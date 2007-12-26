# $NetBSD: Makefile,v 1.2 2007/12/26 21:30:49 hoka_adam Exp $
#

DISTNAME=	ooRexx-3.2.0
PKGNAME=	${DISTNAME:S/R/r/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oorexx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oorexx.sourceforge.net/
COMMENT=	Powerful typeless object-oriented scripting language

CONFLICTS=	rexx-imc-[0-9]* rexx-regina-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=			fix-mandir
SUBST_MESSAGE.fix-mandir=	Fixing hard-coded manuals path.
SUBST_STAGE.fix-mandir=		pre-build
SUBST_FILES.fix-mandir=		Makefile
SUBST_SED.fix-mandir=		-e 's|share/man|man|g'

REPLACE_SH+=	platform/unix/rexx.sh
USE_TOOLS+=	sh:run

REPLACE_INTERPRETER+=	csh
REPLACE.csh.old=	.*/bin/csh
REPLACE.csh.new=	/bin/csh
REPLACE_FILES.csh=	platform/unix/rexx.csh

REPLACE_INTERPRETER+=	rexx
REPLACE.rexx.old=	.*/bin/rexx
REPLACE.rexx.new=	${PREFIX}/bin/rexx
REPLACE_FILES.rexx=	samples/ccreply.rex \
			samples/complex.rex \
			samples/factor.rex \
			samples/greply.rex \
			samples/guess.rex \
			samples/ktguard.rex \
			samples/makestring.rex \
			samples/month.rex \
			samples/pipe.rex \
			samples/properties.rex \
			samples/qdate.rex \
			samples/qtime.rex \
			samples/rexxcps.rex \
			samples/rexxtry.rex \
			samples/semcls.rex \
			samples/stack.rex \
			samples/usecomp.rex \
			samples/usepipe.rex

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
