# $NetBSD$

DISTNAME=	flpsed-0.7.3
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	http://flpsed.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flpsed.org/flpsed.html
COMMENT=	Postscript and PDF annotator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gs:run

INSTALLATION_DIRS+=	share/doc/flpsed

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/flpsed

# FLTK version 1.4 is supported too
.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
