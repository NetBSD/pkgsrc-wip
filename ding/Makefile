# $NetBSD: Makefile,v 1.3 2004/07/18 15:50:18 ppostma Exp $

DISTNAME=	ding-1.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/	\
		ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/ger-eng/
DISTFILES=	ding-1.2.tar.gz		\
		ger-eng.txt.gz

MAINTAINER=	eukaryote@sympatico.ca
HOMEPAGE=	http://www-user.tu-chemnitz.de/~fri/ding/
COMMENT=	Ding is a Dictionary lookup program for the X window system

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	aspell-german>=0.50:../../textproc/aspell-german
DEPENDS+=	aspell-english>=0.50:../../textproc/aspell-english
DEPENDS+=	dict-data>=1.8:../../textproc/dict-dictionaries
DEPENDS+=	dict-client>=1.8:../../textproc/dict-client

USE_BUILDLINK3=	yes
USE_X11=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../textproc/aspell/buildlink3.mk"

do-install:
	 ${CP} ${WRKSRC}/ding ${PREFIX}/bin/;
	 ${CP} ${WRKSRC}/ger-eng.txt ${PREFIX}/share/dict/;
	 ${CP} ${WRKSRC}/ding.1 ${PREFIX}/man/man1/;

.include "../../mk/bsd.pkg.mk"
