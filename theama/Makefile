# $NetBSD: Makefile,v 1.1 2013/05/25 13:45:59 francksys Exp $
#

DISTNAME=	theama-0.2
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/project/theama/theama/0.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	francksys@free.fr
HOMEPAGE=	http://downloads.sourceforge.net/project/theama/theama/0.2/
COMMENT=	Theama is a curses-based version of the famous HangMan game
LICENSE=	gnu-gpl-v2


SUBST_CLASSES+=			makefile
SUBST_STAGE.makefile=		post-extract
SUBST_MESSAGE.makefile=		Replacing directories in Makefile
SUBST_FILES.makefile=		Makefile
SUBST_SED.makefile=		-e 's|/usr/local|$${DESTDIR}$${PREFIX}|g'

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
