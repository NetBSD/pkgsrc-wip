# $NetBSD: Makefile,v 1.2 2013/06/06 08:44:10 francksys Exp $
#

DISTNAME=	theama-0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=theama/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	francksys@free.fr
HOMEPAGE=	https://theama.sourceforge.net/
COMMENT=	Theama is a curses-based version of the famous HangMan game
LICENSE=	gnu-gpl-v2


SUBST_CLASSES+=			makefile
SUBST_STAGE.makefile=		post-extract
SUBST_MESSAGE.makefile=		Replacing directories in Makefile
SUBST_FILES.makefile=		Makefile
SUBST_SED.makefile=		-e 's|/usr/local|$${DESTDIR}$${PREFIX}|g'

SUBST_CLASSES+=			pdb
SUBST_STAGE.pdb=		post-extract
SUBST_MESSAGE.pdb=		Replacing PDB directory
SUBST_FILES.pdb=		theama.c
SUBST_SED.pdb=			-e 's|/usr/local|${PREFIX}|g'

INSTALLATION_DIRS=		bin

.include "../../mk/bsd.pkg.mk"
