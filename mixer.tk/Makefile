# $NetBSD: Makefile,v 1.10 2012/11/23 22:33:42 othyro Exp $
#

DISTNAME=	mixer.tk-0.4
CATEGORIES=	audio
MASTER_SITES=	http://gnorw.net/netbsd/

MAINTAINER=	jaka.jejcic@gmail.com
HOMEPAGE=	https://gnorw.net/netbsd/mixer.tk-0.4/
COMMENT=	Tcl/Tk audio mixer using mixerctl utility

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mixer.tk ${DESTDIR}${PREFIX}/bin

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
