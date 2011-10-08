# $NetBSD: Makefile,v 1.1.1.1 2011/10/08 21:08:27 bubuchka Exp $
#

CMU_VERSION=	0.7.0
DISTNAME=	cm-unicode-${CMU_VERSION}-ttf
PKGNAME=	cm-unicode-ttf-${CMU_VERSION}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cm-unicode/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://canopus.iacp.dvo.ru/~panov/cm-unicode/
COMMENT=	Computer Modern Unicode fonts
LICENSE=	open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/cm-unicode-${CMU_VERSION}
NO_BUILD=		yes
NO_CONFIGURE=		yes

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}
INSTALLATION_DIRS+=	${FONTDIR}

do-install:
	cd ${WRKSRC} && for ff in *.ttf ; do \
		${INSTALL_DATA} $$ff ${DESTDIR}${FONTDIR}/$$ff ;\
	done

.include "../../mk/bsd.pkg.mk"
