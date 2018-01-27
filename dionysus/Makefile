# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:36 asau Exp $

DISTNAME=	dionysus-1.3.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=dionysus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/dionysus/
COMMENT=	Dionysus is a database engine for for universal constants
LICENSE=	gnu-gpl-v3

INFO_FILES=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	tclsh:run

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}

INSTALLATION_DIRS+=	bin ${PKGINFODIR} share/dionysus/databases

post-install:
		${INSTALL_DATA} ${WRKSRC}/databases/*.ddb ${DESTDIR}${PREFIX}/share/dionysus/databases/

.include "../../mk/bsd.pkg.mk"
