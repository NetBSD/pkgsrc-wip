# $NetBSD: Makefile,v 1.4 2013/03/21 17:35:58 shattered Exp $
#

DISTNAME=	# empty
PKGNAME=	vista-fonts-20061028
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://download.microsoft.com/download/f/5/a/f5a3df76-d856-4a61-a6bd-722f52a5be26/
DISTFILES=	PowerPointViewer.exe

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.microsoft.com/download/en/details.aspx?id=6
COMMENT=	TrueType fonts from Microsoft Windows Vista
LICENSE=	ms-ttf-license

RESTRICTED=	No redistribution in altered form

BUILD_DEPENDS+=	cabextract-[0-9]*:../../archivers/cabextract

NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_CONFIGURE=	yes
NO_BUILD=	yes

EXTRACT_CMD=	${LOCALBASE}/bin/cabextract -q -s $${extract_file} ppviewer.cab
FONTDIR=	${PREFIX}/share/fonts/X11/TTF
DOCDIR=		${PREFIX}/share/doc/vista-fonts
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR} ${DOCDIR}

post-extract:
	${RUN}								\
	for f in ${WRKSRC}/*.TTF ; do					\
		${MV} $$f `${ECHO} $$f | ${SED} 's|TTF$$|ttf|'`;		\
	done

do-install:
	cd ${WRKSRC} && for f in *.ttf ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${FONTDIR}/$$f; \
	done
	${INSTALL_DATA} ${.CURDIR}/../../licenses/${LICENSE:Q} ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
