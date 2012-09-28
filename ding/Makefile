# $NetBSD: Makefile,v 1.12 2012/09/28 21:24:36 asau Exp $

DISTNAME=	ding-1.5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/	\
		ftp://ftp.tu-chemnitz.de/pub/Local/urz/ding/de-en/
DISTFILES=	ding-1.5.tar.gz		\
		de-en.txt.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-user.tu-chemnitz.de/~fri/ding/
COMMENT=	Ding is a Dictionary lookup program for the X window system
LICENSE=	gnu-gpl-v2

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
	 ${INSTALL_SCRIPT} ${WRKSRC}/ding ${DESTDIR}${PREFIX}/bin/
	 ${INSTALL_DATA} ${WRKSRC}/de-en.txt ${DESTDIR}${PREFIX}/share/dict/
	 ${INSTALL_MAN} ${WRKSRC}/ding.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
