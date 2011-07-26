# $NetBSD: Makefile,v 1.1.1.1 2011/07/26 22:50:55 rhialto Exp $

DISTNAME=	algol68g-${A68G_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${DOC_FILE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olafs@cs.ru.nl
HOMEPAGE=	http://jmvdveer.home.xs4all.nl/algol.html
COMMENT=	Algol 68genie compiler
PKG_DESTDIR_SUPPORT= user-destdir

DOC_FILE=	algol68g.pdf

A68G_VERSION=	2.2.0

USE_TOOLS+=		make
USE_TOOLS+=		autoreconf autoconf aclocal automake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c
LICENSE=	gnu-gpl-v3

# We patched configure.ac
pre-configure:
	cd ${WRKSRC} && autoreconf

INSTALLATION_DIRS+= share/doc/a68g

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DOC_FILE} ${DESTDIR}${PREFIX}/share/doc/a68g/${DOC_FILE}

.include "options.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
