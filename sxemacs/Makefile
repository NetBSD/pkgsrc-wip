# $NetBSD: Makefile,v 1.11 2012/10/07 16:23:18 asau Exp $

DISTNAME=	sxemacs-22.1.5
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://downloads.sxemacs.org/releases/

MAINTAINER=	hauke@Espresso.Rhein-Neckar.DE
HOMEPAGE=	http://www.sxemacs.org/
COMMENT=	SXEmacs text editor version 22

CONFLICTS+=	gnuclient-[0-9]*
CONFLICTS+=	xemacs-[0-9]*


PLIST_SUBST+=	DISTNAME=${DISTNAME}
MESSAGE_SUBST+=	DISTNAME=${DISTNAME}

GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo perl
INSTALL_UNSTRIPPED=	yes

.include "options.mk"

# XXX GUI configuration is a mess...
#
#.if defined(USE_ATHENA)
#WITH_DIALOGS= \
#		--with-menubars=athena \
#		--with-scrollbars=athena \
#		--with-dialogs=athena \
#		--with-widgets=athena \
#		--with-athena=xaw \
#		--with-xim=xlib
#.include "../../mk/xaw.buildlink3.mk"
#.elif defined(USE_MOTIF)
#WITH_DIALOGS= \
#		--with-menubars=motif \
#		--with-scrollbars=motif \
#		--with-dialogs=motif \
#		--with-widgets=motif \
#		--with-xim=motif
#.include "../../mk/motif.buildlink3.mk"
#.else
# XXX Default is "lucid".  Due to the output of `configure --help', Lucid
#     widgets wrap Athena, so xaw.buildlink3.mk.
WITH_DIALOGS= \
		--with-toolbars=yes \
		--with-menubars=lucid \
		--with-scrollbars=lucid \
		--with-dialogs=athena \
		--with-widgets=athena \
		--with-athena=xaw \
		--with-xim=xlib
.include "../../mk/xaw.buildlink3.mk"
#.endif

.if ${OPSYS} == "SunOS"
.  if !exists(/usr/demo/SOUND/libaudio.a) && !exists(/usr/demo/SOUND/lib/libaudio.a)
CONFIGURE_ARGS+=	--with_sound=none
.  endif
.endif

.if defined(MANZ)
PLIST_SUBST+=	ELSUFX='.gz'
.else
PLIST_SUBST+=	ELSUFX=''
.endif
PLIST_SUBST+=	X11ONLY=""

.include "../../mk/oss.buildlink3.mk"

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.if ${OPSYS} == "Darwin"
.include "../../devel/ncurses/buildlink3.mk"
.endif

INFOPATH=	${PREFIX}/info:${X11BASE}/info:/usr/local/info

CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--with-mule=yes
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-ncurses
.elif ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--with-ncurses=no
.endif
CONFIGURE_ARGS+=	--with-pdump
CONFIGURE_ARGS+=	${WITH_DIALOGS}
CONFIGURE_ARGS+=	--with-infopath=${INFOPATH:Q}
CONFIGURE_ARGS+=	--with-site-includes=${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
CONFIGURE_ARGS+=	--with-site-libraries=${BUILDLINK_DIR}/lib:${BUILDLINK_X11_DIR}
CONFIGURE_ARGS+=	--with-site-runtime-libraries=${LOCALBASE}/lib:${X11BASE}/lib

CFLAGS+=		-Dunix

post-patch:
	@${RM} -f ${WRKSRC}/etc/ctags.1.orig

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${DISTNAME}
	## ${INSTALL_DATA_DIR} ${PREFIX}/lib/sxemacs
.if defined(MANZ)
	${FIND} ${PREFIX}/lib/${DISTNAME} -name "*.el" -type f -print | \
	${XARGS} ${GZIP_CMD}
.endif

.include "../../mk/bsd.pkg.mk"
