# $NetBSD: Makefile,v 1.4 2005/04/11 21:14:03 tvierling Exp $
#

DISTNAME=	mixer.tk-0.3
CATEGORIES=	audio
MASTER_SITES=	http://netbsd.gnorw.net/Applications/mixer.tk/downloads/

MAINTAINER=	Jaka Jejcic <keks@kibla.org>
HOMEPAGE=	http://netbsd.gnorw.net/Applications/mixer.tk/
COMMENT=	Tcl/Tk audio mixer using mixerctl utility

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mixer.tk ${PREFIX}/bin

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

