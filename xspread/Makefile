# $NetBSD: Makefile,v 1.6 2012/10/07 19:54:59 asau Exp $
#

DISTNAME=		xspread3.1.1c
PKGNAME=		xspread-3.1.1c
CATEGORIES=		math
# What is the tucows-bsd URL for this?
MASTER_SITES=		http://public.planetmirror.com/pub/tucows-bsd/files/ \
			ftp://ftp.openbsd.org/pub/OpenBSD/distfiles/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.chemie.fu-berlin.de/chemnet/use/xspread.html
COMMENT=		X11 spreadsheet based on sc

PKG_DESTDIR_SUPPORT=	destdir

GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no

#CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include"
MAKE_ENV+=		LOCAL_LDFLAGS="${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib"

PKGMANDIR?=		man

post-extract:
	${RM} ${WRKSRC}/doc/doc.tmp ${WRKSRC}/sample_files/sample_files.tmp \
		${WRKSRC}/documents/documents.tmp

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxspread ${DESTDIR}${PREFIX}/bin/pxspread
	${INSTALL_PROGRAM} ${WRKSRC}/xspread ${DESTDIR}${PREFIX}/bin/xspread
	${INSTALL_MAN} ${WRKSRC}/pxspread.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pxspread.1
	${INSTALL_MAN} ${WRKSRC}/xspread.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xspread.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xspread
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xspread
	${INSTALL_DATA} ${WRKSRC}/x/notes  ${DESTDIR}${PREFIX}/share/doc/xspread
	${CP} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/xspread/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xspread/examples
	${CP} -R ${WRKSRC}/documents ${DESTDIR}${PREFIX}/share/xspread/
	${CP} ${WRKSRC}/sample_files/* ${DESTDIR}${PREFIX}/share/xspread/examples/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/xspread/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
