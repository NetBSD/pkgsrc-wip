# $NetBSD: Makefile,v 1.3 2009/11/12 21:10:37 christtrekker Exp $
#

#DISTNAME=	ctm-syn68k-b9044353deba13876bd024ea42c8be04e2ff3d8f
DISTNAME=	ctm-syn68k-b904435
PKGNAME=	syn68k-20090622
CATEGORIES=	emulators
MASTER_SITES=	http://download.github.com/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.ardi.com/syn68k.php
COMMENT=	ARDI's 68LC040 CPU emulator
LICENSE=	mit

USE_TOOLS+=	autoconf automake bash
#REPLACE_BASH=	autogen.sh test/testall.sh
REPLACE_BASH=	test/testall.sh

SUBST_CLASSES+=	replace_bash_early
SUBST_STAGE.replace_bash_early=	pre-configure
SUBST_MESSAGE.replace_bash_early=	Fixing bash path.
SUBST_FILES.replace_bash_early=	autogen.sh
SUBST_SED.replace_bash_early=	-e 's,/bin/bash,${TOOLS_PATH.bash},g'

pre-configure:
	cd ${WRKSRC} && ./autogen.sh


.include "../../mk/bsd.pkg.mk"
