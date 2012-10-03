# $NetBSD: Makefile,v 1.5 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	ooRexx-3.2.0
PKGNAME=	${DISTNAME:S/R/r/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oorexx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oorexx.sourceforge.net/
COMMENT=	Powerful typeless object-oriented scripting language

CONFLICTS=	rexx-imc-[0-9]* rexx-regina-[0-9]*

GNU_CONFIGURE=			yes
USE_LIBTOOL=			yes
USE_LANGUAGES=			c c++

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
REPLACE_FILES.rexx=	samples/*.rex

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
