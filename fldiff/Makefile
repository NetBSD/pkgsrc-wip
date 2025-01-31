# $NetBSD$

DISTNAME=	fldiff-1.1-source
PKGNAME=	${DISTNAME:S/-source//}
# mgdiff is in devel, xxdiff is in textproc
CATEGORIES=	textproc
MASTER_SITES=	https://web.archive.org/web/20130406143757/http://www.easysw.com/~mike/fldiff/

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20130406143757/http://www.easysw.com/~mike/fldiff/index.html
COMMENT=	Graphical diff program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

MAKE_FLAGS+=	BUILDROOT=${DESTDIR:Q}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
