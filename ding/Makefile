# $NetBSD: Makefile,v 1.8 2007/01/13 23:46:40 shattered Exp $

DISTNAME=	ding-1.4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/	\
		ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/de-en/
DISTFILES=	ding-1.4.tar.gz		\
		de-en.txt.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-user.tu-chemnitz.de/~fri/ding/
COMMENT=	Ding is a Dictionary lookup program for the X window system

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	aspell-german>=0.50:../../textproc/aspell-german
DEPENDS+=	aspell-english>=0.50:../../textproc/aspell-english
DEPENDS+=	dict-data>=1.8:../../textproc/dict-dictionaries
DEPENDS+=	dict-client>=1.8:../../textproc/dict-client

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../textproc/aspell/buildlink3.mk"

do-install:
	 ${INSTALL_SCRIPT} ${WRKSRC}/ding ${PREFIX}/bin/
	 ${INSTALL_DATA} ${WRKSRC}/de-en.txt ${PREFIX}/share/dict/
	 ${INSTALL_MAN} ${WRKSRC}/ding.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
