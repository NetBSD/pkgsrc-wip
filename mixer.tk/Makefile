# $NetBSD: Makefile,v 1.1.1.1 2003/04/24 21:13:35 jejcic Exp $
#

DISTNAME=	mixer.tk-0.2
CATEGORIES=	audio
MASTER_SITES=	http://netbsd.gnorw.net/Applications/mixer.tk/downloads/

MAINTAINER=	Jaka Jejcic <keks@kibla.org>
HOMEPAGE=	http://netbsd.gnorw.net/Applications/mixer.tk/
COMMENT=	Tcl/Tk audio mixer using mixerctl utility

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mixer.tk ${PREFIX}/bin

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

