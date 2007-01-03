# $NetBSD: Makefile,v 1.6 2007/01/03 10:33:57 jejcic Exp $
#

DISTNAME=	mixer.tk-0.3
CATEGORIES=	audio
MASTER_SITES=	http://netbsd.gnorw.net/Applications/mixer.tk/downloads/

MAINTAINER=	gnorwos@gmail.com
HOMEPAGE=	http://netbsd.gnorw.net/Applications/mixer.tk/
COMMENT=	Tcl/Tk audio mixer using mixerctl utility

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mixer.tk ${PREFIX}/bin

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

