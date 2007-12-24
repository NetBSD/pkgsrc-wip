# $NetBSD: Makefile,v 1.1 2007/12/24 16:33:18 bsadewitz Exp $
#

DISTNAME=	PDCurses-3.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdcurses/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://pdcurses.sourceforge.net/
COMMENT=	Public domain implementation of the X/Open curses standard

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-x

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libXaw}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libXaw}/lib
LIBXAW_SUFX=		${BUILDLINK_TRANSFORM:M*Xaw[0-9]:C/[^[0-9]]*//g}
CONFIGURE_ENV+=		LIBXAW_SUFX=${LIBXAW_SUFX:Q}
.endif

CFLAGS+=		-Wall -Wstrict-aliasing=2

INST_LIBDIR=		${DESTDIR}${PREFIX}/lib
INST_MANDIR=		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
INST_DOCDIR=		${DESTDIR}${PREFIX}/share/doc/pdcurses
INST_INCDIR=		${DESTDIR}${PREFIX}/include
INST_INCDIR.xcurses=	${INST_INCDIR}/xcurses

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"

SUBST_CLASSES+=		hdr
SUBST_STAGE.hdr=	post-build
SUBST_FILES.hdr=	panel.h
SUBST_SED.hdr=		-e 's,\#include <curses.h>,\#include <xcurses.h>,'
SUBST_MESSAGE.hdr=	Preparing for installation: ${SUBST_FILES.hdr}.

pre-install:
	cp ${WRKSRC}/panel.h ${WRKSRC}/xpanel.h

do-install:
	${INSTALL_LIB_DIR} ${INST_LIBDIR:Q}
	${INSTALL_DATA_DIR} ${INST_INCDIR:Q}
	${INSTALL_DATA_DIR} ${INST_DOCDIR:Q}
	${INSTALL_DATA_DIR} ${INST_INCDIR.xcurses:Q}
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/x11/libXCurses.la ${INST_LIBDIR:Q}/
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/x11/libxpanel.la ${INST_LIBDIR:Q}/
	${INSTALL_DATA} ${WRKSRC}/curses.h ${INST_INCDIR:Q}/xcurses.h
	${INSTALL_DATA} ${WRKSRC}/curses.h ${INST_INCDIR.xcurses:Q}
	${INSTALL_DATA} ${WRKSRC}/xpanel.h ${INST_INCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/panel.h ${INST_INCDIR.xcurses:Q}
	${INSTALL_DATA} ${WRKSRC}/curspriv.h ${INST_INCDIR.xcurses:Q}
	${INSTALL_DATA} ${WRKSRC}/tools/PDCurses.man ${INST_DOCDIR:Q}

.include "../../mk/bsd.pkg.mk"
