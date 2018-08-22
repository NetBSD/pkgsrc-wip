# $NetBSD$

DISTNAME=	10.00
PKGNAME=	xrn-10.00-beta-3
CATEGORIES=	news
MASTER_SITES=	ftp://rtfm.mit.edu/pub/xrn/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mit.edu/people/jik/software/xrn.html
COMMENT=	USENET Newsreader for the X window system
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/xrn-10.00-beta-3
DIST_SUBDIR=	xrn

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake lex pkg-config yacc

DOCDIR=		share/doc/xrn
INSTALLATION_DIRS+=	${DOCDIR}

.include "../../mk/bsd.prefs.mk"
XAW_TYPE=	standard

pre-install:
	for f in COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/doc/xrn;	\
	done

# Select implementation of the Athena Widgets via XAW_TYPE
.include "../../mk/xaw.buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
