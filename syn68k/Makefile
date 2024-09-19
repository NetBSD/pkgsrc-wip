# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:48 thomasklausner Exp $
#

DISTNAME=	ctm-syn68k-8821995
PKGNAME=	syn68k-20091205
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/ctm/syn68k/tarball/master/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.ardi.com/syn68k.php
COMMENT=	ARDI's 68LC040 CPU emulator
LICENSE=	mit

FETCH_BEFORE_ARGS=	--no-check-certificate
USE_TOOLS+=		autoconf automake bash gmake perl
REPLACE_BASH=		test/testall.sh
REPLACE_SH=		configure
REPLACE_PERL=		runtime/fold.pl runtime/i486-cleanup.pl \
			runtime/i486-optimize.pl runtime/sched.pl \
			runtime/x86_recog.pl test/maketestbattery.pl
GNU_CONFIGURE=		yes

SUBST_CLASSES+=				replace_bash_early
SUBST_STAGE.replace_bash_early=		pre-configure
SUBST_MESSAGE.replace_bash_early=	Fixing bash path.
SUBST_FILES.replace_bash_early=		autogen.sh
SUBST_SED.replace_bash_early=		-e 's,/bin/bash,${TOOLS_PATH.bash},g'

pre-configure:
	cd ${WRKSRC} && ./autogen.sh


.include "../../mk/bsd.pkg.mk"
